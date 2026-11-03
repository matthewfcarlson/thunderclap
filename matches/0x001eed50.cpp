#include "gen/owners.h"
struct Pair {
    int a, b;
};
struct Sub {
    int q, r;
};
struct Obj {
    char pad0[8];
    int a;
    float f;
    int zero;
    char flag;
    char pad1[3];
    Sub sub;
    int other;
    float old;
    void Fn(int, Pair*, int, float);
};
void Obj::Fn(int x, Pair* p, int y, float z) {
    f -= old;
    a = x;
    zero = 0;
    flag = 1;
    other = y;
    old = z;
    if (p)
        ((owners::Pair_27af60 *)&sub)->FUN_0027af60(p->a, p->b);
    else
        ((owners::Pair_27af60 *)&sub)->FUN_0027af60(0, 0);
}