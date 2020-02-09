// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(custom)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV math(HSV hsv,  int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    hsv.h = 185;
    hsv.s = 84;
    uint16_t effect = tick + dist * 5;
    if (effect > 255)
        effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
bool custom(effect_params_t* params) {
    return effect_runner_reactive_custom(qsub8(g_last_hit_tracker.count, 1), params, &math);
}

#endif
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
