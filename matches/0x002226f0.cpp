// Same code shape as 0x002226e0 (propagated; names are from that function)
#include "gen/owners.h"
class Inner_2226f0 {
  public:
};
class Obj_2226f0 {
  public:
    char pad[0x10];
    void target(int);
};
void Obj_2226f0::target(int a0) {
    ((owners::Target_22be40 *)(((Inner_2226f0*)((char*)this + 0x10))))->FUN_0022be40((const int *)(hulk_uintptr)(int)a0);
}