#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
// data: reciprocal = DAT_003f32dc, threshold_2a54e0 = DAT_004275c4, zero_2a54e0 = DAT_003f32e0

#include "compat/ptr.h"
struct Vec2_2a54e0 {
    float x;
    float y;
};
extern "C" double sqrt(double);
hulk_freg __fastcall Vec2Normalize(Vec2_2a54e0* v) {
    hulk_freg n = v->x * v->x + v->y * v->y;
    if (n >= (*(float*)&DAT_004275c4)) {
        hulk_freg r = (*(float*)&DAT_003f32dc) / (hulk_freg)sqrt(n);
        v->x *= r;
        v->y *= r;
        return (*(float*)&DAT_003f32dc) / r;
    }
    v->y = 0.0f;
    hulk_freg z = (*(float*)&DAT_003f32e0);
    v->x = 0.0f;
    return z;
}