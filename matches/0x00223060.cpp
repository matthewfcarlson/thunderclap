#include "gen/owners.h"
class A_223060 {
  public:
    int f();
};
class B_223060 {
  public:
};
class C_223060 {
  public:
    char pad[0x10];
    A_223060 a;
    void f();
};
void C_223060::f() {
    int x = a.f();
    ((owners::C_284820 *)(((B_223060*)*(void**)((char*)this + 0x64))))->FUN_00284820((hulk_intptr)x);
}