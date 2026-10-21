#include "compat/ptr.h"
struct Obj_28b150 {
    void Get(int d, float* out);
};

hulk_freg __cdecl FUN_0028b150(Obj_28b150* a, Obj_28b150* b, float t, int d) {
    float x, y;
    a->Get(d, &x);
    b->Get(d, &y);
    return (y - x) * t + x;
}
