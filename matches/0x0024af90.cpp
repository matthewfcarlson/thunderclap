#include "compat/ptr.h"
struct X {
    int a;
    int value;
    int b;
    float scale;
};
extern unsigned int get(X*);
extern const float big;
unsigned int __cdecl target(X* p) {
    unsigned int n = get(p);
    hulk_freg f = (hulk_freg)(unsigned int)p->value * p->scale;
    return n <= (unsigned int)(int)f;
}