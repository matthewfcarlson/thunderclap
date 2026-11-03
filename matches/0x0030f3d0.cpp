#include "gen/owners.h"
class Base_30f3d0 {
  public:
    Base_30f3d0();
    char pad[0x40];
};
class Thing_30f3d0 : public Base_30f3d0 {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing_30f3d0(int);
};
Thing_30f3d0::Thing_30f3d0(int x) : Base_30f3d0() {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    int* q = &e;
    *q = 0;
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
}
