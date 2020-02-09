// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(purple)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

int purple_r = 139;
int purple_g =   0;
int purple_b = 139;

static void purple_init(effect_params_t* params) {

}

static bool purple_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for(int i=0; i<=led_max; i++) {
        if (i < led_max-18 || i > led_max-6) {
          rgb_matrix_set_color(i, purple_r, purple_g, purple_b);
        }
        else {
          rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}


static bool purple(effect_params_t* params) {
  if (params->init) purple_init(params);
  return purple_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
