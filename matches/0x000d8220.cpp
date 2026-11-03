#include "gen/owners.h"
class B_d8220 {
  public:
    void F1(int);
    int F2(int);
    void F3(int);
};
class A_d8220 {
  public:
};
class M_d8220 {
  public:
    A_d8220* Get();
};
class FEMemCardControl_d8220 {
  public:
    int Run(int x);
    char pad[0x150];
    M_d8220* m;
};
int FEMemCardControl_d8220::Run(int x) {
    ((B_d8220 *)((owners::Obj_89a50 *)(m->Get()))->FUN_00089a50())->F1(x);
    int r = ((B_d8220 *)((owners::Obj_89a50 *)(m->Get()))->FUN_00089a50())->F2(x);
    ((B_d8220 *)((owners::Obj_89a50 *)(m->Get()))->FUN_00089a50())->F3(x);
    return r;
}