#include "gen/owners.h"
typedef unsigned int u32_1f3400;
void F249A90(u32_1f3400 a, u32_1f3400* b);
void F24A800(u32_1f3400 a, int b);
void F2497E0(u32_1f3400 a);
struct Pair_1f3400 {
    u32_1f3400 x;
    u32_1f3400 y;
};
void owners::Obj_1f3400::FUN_001f3400(u32_1f3400 param) {
    Pair_1f3400 p;
    if (a != 0) {
        p.x = 0;
        p.y = param;
        F249A90(a, &p.x);
        F24A800(a, 0x32);
        if (b != 0) {
            F2497E0(b);
            b = 0;
        }
    }
}
