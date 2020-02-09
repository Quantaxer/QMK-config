#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

typedef HSV (*reactive_splash_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick);

bool effect_runner_reactive_custom(effect_params_t* params, reactive_f effect_func) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  uint16_t max_tick = 65535 / rgb_matrix_config.speed;
  //uint8_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 2);
  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    uint16_t tick = max_tick;
    // Reverse search to find most recent key hit
    for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
      if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
        tick = g_last_hit_tracker.tick[j];
        break;
      }
    }
    if (tick != max_tick) {
        uint16_t  offset = scale16by8(tick, rgb_matrix_config.speed);
        RGB rgb = hsv_to_rgb(effect_func(rgb_matrix_config.hsv, offset));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    else {
        HSV hsv2 = rgb_matrix_config.hsv;
        hsv2.h += 50;
        int16_t dx = g_led_config.point[i].x - k_rgb_matrix_center.x;
        int16_t dy = g_led_config.point[i].y - k_rgb_matrix_center.y;
        uint8_t dist = sqrt16(dx * dx + dy * dy);
       
        hsv2.h = hsv2.h - (dist / 2);
        if (hsv2.h > rgb_matrix_config.hsv.h + 50) {
            hsv2.h = hsv2.h - 1;
        }
        else if (hsv2.h < rgb_matrix_config.hsv.h) {
            hsv2.h = hsv2.h + 1;
        }
        RGB rgb = hsv_to_rgb(effect_func(hsv2, 0));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
