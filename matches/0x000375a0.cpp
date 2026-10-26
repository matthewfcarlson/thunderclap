#include "decls/data/game/global.h"
// data: gEpsilon = DAT_003f5b94

struct V3_375a0 {
    float x;
    float y;
    float z;
};
extern "C" bool __fastcall FUN_000375a0(V3_375a0* p) {
    union U {
        float f;
        unsigned int i;
    } u;
    u.f = p->x * p->x + p->y * p->y + p->z * p->z - DAT_003f32dc;  // the listing's order (MSVC 7.1 reassociates; clang does not)
    u.i &= 0x7fffffff;
    return u.f <= DAT_003f5b94;
}