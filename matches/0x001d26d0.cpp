#include "gen/owners.h"
class B_1d26d0 {
  public:
};
class D {
  public:
    void h(B_1d26d0*);
};
class C_1d26d0 {
  public:
    char pad[12];
    D d;
    void g(unsigned int, B_1d26d0*);
};
void C_1d26d0::g(unsigned int a, B_1d26d0* b) {
    ((owners::CAgent_1d04b0 *)b)->FUN_001d04b0((hulk_intptr)a);
    d.h(b);
}
