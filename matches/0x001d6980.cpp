// Same code shape as 0x001d64a0 (propagated; names are from that function)
#include "gen/owners.h"
class B_1d6980 {
  public:
};
class A_1d6980 {
  public:
    char pad[0xec];
    B_1d6980* p;
    int F();
};
int A_1d6980::F() {
    return ((owners::Target_1d4df0 *)p)->FUN_001d4df0();
}