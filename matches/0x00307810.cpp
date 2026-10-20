#include "compat/ptr.h"
class A_307810 {
  public:
    char pad[0x284];
    hulk_intptr member;
    void First();
    void Last();
};
class B_307810 {
  public:
    void Second(int, int, int, int);
};
void __cdecl target(A_307810* p1, int p2) {
    p1->First();
    ((B_307810*)p1->member)->Second(p2, 3, 4, 1);
    p1->Last();
}