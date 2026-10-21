#include "compat/ptr.h"
extern float __cdecl A(float);
extern float __cdecl C(float);
extern float __cdecl B(float, float, int, int, int);
hulk_freg __cdecl Target(float p1, float p2, int p3, int p4, int p5) {
    float f1 = A(p2 - p1);
    float f2 = A(p1);
    return C(B(f2, f2 + f1, p3, p4, p5));
}
