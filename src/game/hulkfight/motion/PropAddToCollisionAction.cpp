// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00182000..0x00182070 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropAddToCollisionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f812a616 {
#define TREE_TU_END }
namespace fn_f812a616 {} using namespace fn_f812a616;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f812a616 {
struct Act_182000 {
    void Run(void* o, unsigned char b);
};
struct G_182000 {
    char pad[0x10];
    Act_182000* act;
};
extern G_182000* gG_182000;
struct Cfg_182000 {
    char pad[0x10];
    int idx;
    unsigned char b;
};
struct Ent_182000 {
    char pad[0x128];
    void* s128;
};
struct Reg2 {
    Ent_182000* Lookup();
};
struct Owner_182000 {
};

} // namespace fn_f812a616

// 0x00182000 hulkfight::motion::PropAddToCollisionAction::vfunc_5 (99 B): matches/0x00182000.cpp
// sym: ?vfunc_5@PropAddToCollisionAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropAddToCollisionAction::vfunc_5(hulk_intptr __p0, int q) { unsigned int p = (unsigned int)__p0;

    if (p == 0 && (*(Owner_182000 * *)&this->f_20) != 0) {
        Ent_182000* e = ((Reg2 *)((owners::Object_592a0 *)((*(Owner_182000 * *)&this->f_20)))->FUN_000592a0())->Lookup();
        int i = (*(Cfg_182000 * *)&this->f_1c)->idx;
        if (e) {
            void* o;
            if (i < 0)
                o = e->s128;
            else {
                if (i >= 8)
                    return false;
                o = ((void *)((owners::C_35ef0 *)e)->FUN_00035ef0((hulk_intptr)i));
            }
            if (o)
                gG_182000->act->Run(o, (*(Cfg_182000 * *)&this->f_1c)->b);
        }
    }
    return false;
}

