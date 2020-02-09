// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(orange)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

int orange_r = 255;
int orange_g = 140;
int orange_b =   0;

static void orange_init(effect_params_t* params) {

}

static bool orange_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for(int i=0; i<=led_max; i++) {
        if (i < led_max-18 || i > led_max-6) {
          rgb_matrix_set_color(i, orange_r, orange_g, orange_b);
        }
        else {
          rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}


static bool orange(effect_params_t* params) {
  if (params->init) orange_init(params);
  return orange_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
