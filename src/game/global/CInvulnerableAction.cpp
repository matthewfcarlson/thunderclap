// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000175c0..0x00017630 (kind game, layer game, confidence medium), dominant class CInvulnerableAction
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8bedd60 {
#define TREE_TU_END }
namespace fn_f8bedd60 {} using namespace fn_f8bedd60;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8bedd60 {
struct Obj_175c0 {
    Obj_175c0* second();
    void third(int);
    void fourth(int);
};
struct CAction_175c0 {
    virtual void q();
    char pad[0x18];
    Obj_175c0* mObj;
};
class Obj_175f0 {
  public:
    Obj_175f0* second();
    void m40(int);
    void mC0(int);
    void m20(void*);
    void mA0(void*);
};
class Factory_175f0 {
  public:
};

} // namespace fn_f8bedd60

// 0x000175c0 CInvulnerableAction::vfunc_6 (42 B): matches/0x000175c0.cpp
// sym: ?vfunc_6@CInvulnerableAction@@UAE_NH@Z
bool CInvulnerableAction::vfunc_6(int x) {
    Obj_175c0* a = ((Obj_175c0 *)((owners::Object_592a0 *)((*(Obj_175c0 * *)&this->f_1c)))->FUN_000592a0());
    Obj_175c0* b = a->second();
    b->third(1);
    b->fourth(1);
    return true;
}


// 0x000175f0 CInvulnerableAction::vfunc_4 (64 B): matches/0x000175f0.cpp
// sym: ?vfunc_4@CInvulnerableAction@@UAEXXZ
void CInvulnerableAction::vfunc_4() {
    Obj_175f0* x = ((Obj_175f0 *)((owners::Object_592a0 *)((*(Factory_175f0 * *)&this->f_1c)))->FUN_000592a0());
    Obj_175f0* s = x->second();
    s->m40(0);
    s->mC0(0);
    s->m20((*(void * *)&this->f_20));
    s->mA0((*(void * *)&this->f_20));
}

