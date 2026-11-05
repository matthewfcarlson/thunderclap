#include "compat/ptr.h"
#include "gen/owners.h"
class W_e2f80 {
  public:
    char p[8];
};
class Z {
  public:
    char p[8];
    W_e2f80* w;
};
class Y_e2f80 {
  public:
    char p[4];
    Z* z;
};
class X_e2f80 {
  public:
    char p[8];
    Y_e2f80* y;
};
class Obj_e2f80 {
  public:
    char p[0x14];
    X_e2f80* x;
    char q[0x1d94 - 0x18];
    int* arr;
    void f(hulk_intptr);
};
void Obj_e2f80::f(hulk_intptr arg) {
    int* p = ((int *)((owners::Obj_f8d70 *)(x->y->z->w))->FUN_000f8d70((hulk_intptr)arg));
    arr = p;
    if (p) {
        int i = 0;
        while (i < 4 && p[i + 1] != 0)
            ++i;
        if (i != 4)
            p[i + 1] = (hulk_intptr)this;
    }
}