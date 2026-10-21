// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// FUN_003058c0 @ 0x003058c0
#include "compat/ptr.h"
struct Matrix { float x0,y0,z0,w0; float x1,y1,z1,w1; float x2,y2,z2,w2; };
extern "C" double __cdecl sqrt(double);
hulk_freg __cdecl FUN_003058c0(const Matrix* m, float tolerance) {
    float a = (double)m->z0*m->z0 + (double)m->y0*m->y0 + (double)m->x0*m->x0;
    double b = (double)m->z1*m->z1 + (double)m->y1*m->y1 + (double)m->x1*m->x1;
    union { float f; unsigned int u; } delta;
    delta.f = a-b;
    delta.u &= 0x7fffffff;
    double inverse = 1.0 / a;
    if (!(delta.f * inverse < tolerance)) return 1.0f;
    delta.f = a-((double)m->z2*m->z2 + (double)m->y2*m->y2 + (double)m->x2*m->x2);
    delta.u &= 0x7fffffff;
    if (!(delta.f * inverse < tolerance)) return 1.0f;
    return (float)sqrt(a);
}