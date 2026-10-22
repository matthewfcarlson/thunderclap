#include "compat/ptr.h"
typedef unsigned int U_2d4350;
extern U_2d4350 vt1_2d4350;
extern U_2d4350 vt2_2d4350;
void drop(U_2d4350);
class OverLifeAttributes_2d4350 {
  public:
    hulk_uintptr vptr;
    U_2d4350 x[3];
    U_2d4350 a[8];
    void f();
};
void OverLifeAttributes_2d4350::f() {
    vptr = (hulk_uintptr)&vt1_2d4350;
    drop(a[0]);
    drop(a[1]);
    drop(a[2]);
    drop(a[3]);
    drop(a[4]);
    drop(a[5]);
    drop(a[6]);
    drop(a[7]);
    vptr = (hulk_uintptr)&vt2_2d4350;
}
