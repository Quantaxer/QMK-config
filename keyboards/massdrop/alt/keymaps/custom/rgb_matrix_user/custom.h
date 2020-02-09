// !!! DO NOT ADD #pragma once !!! //
RGB_MATRIX_EFFECT(custom)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV math(HSV hsv, uint16_t offset) {
    hsv.h = scale8(255 - offset, hsv.h);
    return hsv;
}

#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
bool custom(effect_params_t* params) {
    return effect_runner_reactive_custom(params, &math);
}

#endif
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
