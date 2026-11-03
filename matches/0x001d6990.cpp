// Same code shape as 0x001d64a0 (propagated; names are from that function)
#include "gen/owners.h"
class B_1d6990 {
  public:
};
class A_1d6990 {
  public:
    char pad[0xec];
    B_1d6990* p;
    int F();
};
int A_1d6990::F() {
    return ((int)((owners::C_1d4e00 *)p)->FUN_001d4e00());
}