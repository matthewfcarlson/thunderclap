// Same code shape as 0x0027ff80 (propagated; names are from that function)
#include "compat/ptr.h"
class D {
  public:
    int f(int, int, int, int, int, int, int, int);
};
class C_2842e0 {
  public:
    char pad[0x10];
    D* member;
    hulk_intptr target(hulk_intptr, int, int, hulk_intptr, hulk_intptr, hulk_intptr, int, int);
};
hulk_intptr C_2842e0::target(hulk_intptr a0, int a1, int a2, hulk_intptr a3, hulk_intptr a4, hulk_intptr a5, int a6, int a7) {
    return member->f(a0, a1, a2, a3, a4, a5, a6, a7);
}