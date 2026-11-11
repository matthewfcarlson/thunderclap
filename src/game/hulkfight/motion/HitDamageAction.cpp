// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014fda0..0x0014fe00 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitDamageAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_febef950 {
#define TREE_TU_END }
namespace fn_febef950 {} using namespace fn_febef950;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_febef950 {
class Mid_14fda0 {
  public:
    Mid_14fda0* Touch();
    void Draw(float, int, int, int, int, unsigned char);
};
class Thing_14fda0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d();
    char pad[0x48 - 4];
    int x48;
    int x4c;
    char p[0x78 - 0x50];
    float x78;
    int x7c;
    char p2[0x91 - 0x80];
    unsigned char x91;
};
class Ref_14fda0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Thing_14fda0* d();
};

} // namespace fn_febef950

// 0x0014fda0 hulkfight::motion::HitDamageAction::vfunc_3 (95 B): matches/0x0014fda0.cpp
// sym: ?vfunc_3@HitDamageAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::HitDamageAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if ((*(Ref_14fda0 * *)&this->f_20)) {
        Thing_14fda0* t = (*(Ref_14fda0 * *)&this->f_20)->d();
        if (t) {
            Mid_14fda0* m = ((Mid_14fda0 *)((owners::Object_592a0 *)((*(Ref_14fda0 * *)&this->f_20)))->FUN_000592a0())->Touch();
            m->Draw(*(float*)((char*)(*(void * *)&this->f_1c) + 0x10) * t->x78, t->x4c, t->x48, t->x7c, 0, t->x91);
        }
    }
    return (bool)(0);
}

