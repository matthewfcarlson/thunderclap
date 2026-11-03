// Same code shape as 0x0030efa0 (propagated; names are from that function)
#include "gen/owners.h"
class C_30efd0 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void third();
    void target(int);
};
void C_30efd0::target(int arg) {
    first();
    ((owners::Obj_30f140 *)(((C_30efd0*)((char*)this + 0x14))))->FUN_0030f140((owners::Obj_30f140 *)(hulk_uintptr)(int)arg);
    value = 2;
    third();
}