#include "gen/owners.h"
struct Helper_182c90 {
    Helper_182c90* f59a30();
    void f27ffb0(int);
};
extern Helper_182c90* __cdecl f27f250();
class BallAndChainReturnAction_182c90 {
  public:
    char pad[0x48];
    void vfunc_4();
};
void BallAndChainReturnAction_182c90::vfunc_4() {
    Helper_182c90* x = ((Helper_182c90 *)((owners::Object_592a0 *)(((Helper_182c90*)*(void**)(pad + 0x20))))->FUN_000592a0());
    x = x->f59a30();
    ((owners::C_35ef0 *)x)->FUN_00035ef0((hulk_intptr)(*(int*)(*(char**)(pad + 0x1c) + 0x14)));
    x = f27f250();
    x->f27ffb0(*(int*)(pad + 0x44));
}