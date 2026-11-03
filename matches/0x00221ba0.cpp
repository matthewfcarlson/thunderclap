// Same code shape as 0x0030f0a0 (propagated; names are from that function)
#include "gen/owners.h"
struct Pair_221ba0 {
    int a, b, c, d;
};
class Obj_221ba0 {
  public:
    char pad[0x40];
    Pair_221ba0 value;
    int flag;
    void First();
    Obj_221ba0* Run(Pair_221ba0* src, int x);
};
Obj_221ba0* Obj_221ba0::Run(Pair_221ba0* src, int x) {
    First();
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
    value = *src;
    flag = 1;
    return this;
}
