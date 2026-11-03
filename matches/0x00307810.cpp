#include "compat/ptr.h"
#include "gen/owners.h"
class A_307810 {
  public:
    char pad[0x284];
    hulk_intptr member;
    void First();
    void Last();
};
class B_307810 {
  public:
};
void __cdecl target(A_307810* p1, int p2) {
    p1->First();
    ((owners::X_2647e0 *)(((B_307810*)p1->member)))->FUN_002647e0((hulk_intptr)p2, (hulk_intptr)3, 4, (hulk_intptr)1);
    p1->Last();
}