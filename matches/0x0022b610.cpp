#include "compat/ptr.h"
struct V {
    float x, y, z, w;
};
struct C_22b610 {
    int dummy;
    void Target(hulk_intptr a, V* p);
};
extern "C" void __cdecl FUN_0022b080(float *, const float *, const float *);
void C_22b610::Target(hulk_intptr a, V* p) {
    V q;
    q.x = -p->x;
    q.y = -p->y;
    q.z = -p->z;
    q.w = p->w;
    FUN_0022b080((float *)(C_22b610 *)this, (const float *)(hulk_uintptr)(int)a, (const float *)(V *)(&q));
}
