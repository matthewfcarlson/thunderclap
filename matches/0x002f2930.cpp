#include "decls/data/game/global.h"
// data: half = DAT_003f32f4

#include "compat/ptr.h"
struct S_2f2930 {
    char pad[0x14];
    float x;
};
hulk_freg f(S_2f2930* a, S_2f2930* b) {
    return (a->x + b->x) * DAT_003f32f4;
}