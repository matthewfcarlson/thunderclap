// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00015970..0x00015a20 (kind game, layer game, confidence medium), dominant class CGrappleDetachAction
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f86c4abf {
#define TREE_TU_END }
namespace fn_f86c4abf {} using namespace fn_f86c4abf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f86c4abf {
class Obj_15970 {
  public:
    void Fn(int a, int b, int c, int d, int e, int e2, float f, int g);
    char pad[0x334];
    Obj_15970* mA;
    Obj_15970* mB;
};
class Mid_15970 {
  public:
    char pad[0x10];
    int mVal;
};
class Owner_15970 {
  public:
    Obj_15970* Get();
};
class Mgr_15970 {
  public:
    Obj_15970* Get();
};
Mgr_15970* GetMgr(Owner_15970* o);
class Ctx_15970 {
  public:
    Mgr_15970* Get();
};

} // namespace fn_f86c4abf

// 0x00015970 CGrappleDetachAction::vfunc_4 (169 B): matches/0x00015970.cpp
// sym: ?vfunc_4@CGrappleDetachAction@@UAEXXZ
void CGrappleDetachAction::vfunc_4() {
    Obj_15970* o = (*(Ctx_15970 * *)&this->f_1c)->Get()->Get();
    Obj_15970* p = o->mA;
    if (p) {
        p->Fn(0, -1, 0, 0, 0, 0, 1.0f, (*(Mid_15970 * *)&this->f_20)->mVal);
        p->mA = 0;
    }
    p = o->mB;
    if (p) {
        p->Fn(0, -1, 0, 0, 0, 0, 1.0f, (*(Mid_15970 * *)&this->f_20)->mVal);
        p->mA = 0;
    }
    o->Fn(0, -1, 0, 0, 0, 0, 1.0f, (*(Mid_15970 * *)&this->f_20)->mVal);
    o->mA = 0;
}

