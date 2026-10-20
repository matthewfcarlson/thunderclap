#include "compat/ptr.h"
struct S_212c50 {
    char pad0[8];
    int a;
    int b;
    char pad10[4];
    hulk_intptr e;
    int c;
    int d;
};
extern void Grow(S_212c50*, int);
int __cdecl target(S_212c50* p, int n) {
    if (((p->a - p->b) >> 3) + n > 0x800)
        return 0;
    if (p->c - p->a <= n * 8)
        Grow(p, n);
    unsigned int v = p->a + n * 8;
    if ((unsigned int)*(int*)(p->e + 4) < v)
        *(int*)(p->e + 4) = v;
    return 1;
}