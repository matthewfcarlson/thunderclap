// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001822d0..0x00182380 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropDamageAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f73cfe7c {
#define TREE_TU_END }
namespace fn_f73cfe7c {} using namespace fn_f73cfe7c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f73cfe7c {
struct Obj_1822d0 {
    Obj_1822d0* Fnb_00059a30();
    unsigned int Fnd_0003aef0(int);
};
struct State_1822d0 {
    char pad[0x10];
    int value;
};
struct Tgt_182310 {
    void FnG_001d6ec0(int, int, int);
};
struct Ent_182310 {
    char pad[0x128];
    Tgt_182310* t128;
    int i12c;
};
struct Holder_182310 {
    Ent_182310* Find_00059a30();
};
struct Src_182310 {
};
struct Cfg_182310 {
    char pad[0x10];
    int idx;
    float f;
};
class Action_182310 {
  public:
    virtual void a();
    virtual void b();
    virtual bool vfunc_2();
};

} // namespace fn_f73cfe7c

// 0x001822d0 hulkfight::motion::PropDropAction::vfunc_3 (57 B): matches/0x001822d0.cpp
// sym: ?vfunc_3@PropDropAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropDropAction::vfunc_3(hulk_intptr x, hulk_intptr y) {
    if ((*(Obj_1822d0 * *)&this->f_20)) {
        Obj_1822d0* p = ((Obj_1822d0 *)((owners::Object_592a0 *)((*(Obj_1822d0 * *)&this->f_20)))->FUN_000592a0());
        p = p->Fnb_00059a30();
        int n = (*(State_1822d0 * *)&this->f_1c)->value;
        if (n < 0) {
            ((unsigned int)((::CCharacter *)p)->FUN_00040170());
            return false;
        }
        p->Fnd_0003aef0(n);
    }
    return false;
}


// 0x00182310 hulkfight::motion::PropDamageAction::vfunc_3 (103 B): matches/0x00182310.cpp
// sym: ?vfunc_3@PropDamageAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropDamageAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(Src_182310 * *)&this->f_20))
        return false;
    {
        Holder_182310* h = ((Holder_182310 *)((owners::Object_592a0 *)((*(Src_182310 * *)&this->f_20)))->FUN_000592a0());
        Ent_182310* e = h->Find_00059a30();
        int i = (*(Cfg_182310 * *)&this->f_1c)->idx;
        if (e) {
            Tgt_182310* t;
            if (i < 0)
                t = e->t128;
            else if (i < 8)
                t = ((Tgt_182310 *)((owners::C_35ef0 *)e)->FUN_00035ef0((hulk_intptr)i));
            else
                return false;
            if (t)
                t->FnG_001d6ec0((int)(*(Cfg_182310 * *)&this->f_1c)->f, e->i12c, 0);
        }
    }
    return false;
}

