#include "compat/ptr.h"
struct Vec2_2a54e0 {
    float x;
    float y;
};
extern float threshold_2a54e0;
extern float reciprocal;
extern float zero_2a54e0;
extern "C" double sqrt(double);
hulk_freg __fastcall Vec2Normalize(Vec2_2a54e0* v) {
    hulk_freg n = v->x * v->x + v->y * v->y;
    if (n >= threshold_2a54e0) {
        hulk_freg r = reciprocal / (hulk_freg)sqrt(n);
        v->x *= r;
        v->y *= r;
        return reciprocal / r;
    }
    v->y = 0.0f;
    hulk_freg z = zero_2a54e0;
    v->x = 0.0f;
    return z;
}