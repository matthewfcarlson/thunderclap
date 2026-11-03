// Same code shape as 0x0030efa0 (propagated; names are from that function)
#include "gen/owners.h"
class C_30f000 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void third();
    void target(int);
};
void C_30f000::target(int arg) {
    first();
    ((owners::Target_22be40 *)(((C_30f000*)((char*)this + 0x14))))->FUN_0022be40((const int *)(hulk_uintptr)(int)arg);
    value = 2;
    third();
}