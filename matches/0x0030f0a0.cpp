#include "gen/owners.h"
struct Pair_30f0a0 {
    int a, b, c, d;
};
class Obj_30f0a0 {
  public:
    char pad[0x40];
    Pair_30f0a0 value;
    int flag;
    void First();
    Obj_30f0a0* Run(Pair_30f0a0* src, int x);
};
Obj_30f0a0* Obj_30f0a0::Run(Pair_30f0a0* src, int x) {
    First();
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
    value = *src;
    flag = 1;
    return this;
}
