#include "compat/ptr.h"
struct X {
    int a;
    int value;
    int b;
    float scale;
};
extern "C" unsigned __cdecl FUN_0025e2b0(void *);
extern const float big;
unsigned int __cdecl target(X* p) {
    unsigned int n = ((unsigned int)FUN_0025e2b0((X *)p));
    hulk_freg f = (hulk_freg)(unsigned int)p->value * p->scale;
    return n <= (unsigned int)(int)(__int64)f;
}