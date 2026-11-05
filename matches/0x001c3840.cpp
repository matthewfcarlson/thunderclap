// Same code shape as 0x001c3830 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
class Inner_1c3840 {
  public:
};
class Outer_1c3840 {
  public:
    Inner_1c3840* p;
    void g(hulk_intptr, hulk_intptr);
};
void Outer_1c3840::g(hulk_intptr a0, hulk_intptr a1) {
    ((owners::Obj_1c1750 *)p)->FUN_001c1750((int *)(hulk_uintptr)(int)a0, (int *)(hulk_uintptr)(int)a1);
}