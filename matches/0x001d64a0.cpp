#include "gen/owners.h"
class B_1d64a0 {
  public:
};
class A_1d64a0 {
  public:
    char pad[0xec];
    B_1d64a0* p;
    int F();
};
int A_1d64a0::F() {
    return ((owners::C_1d4de0 *)p)->FUN_001d4de0();
}