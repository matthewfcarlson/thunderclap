// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00182420..0x00182490 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropDestroyAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd0c682a {
#define TREE_TU_END }
namespace fn_fd0c682a {} using namespace fn_fd0c682a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd0c682a {
struct Info_182420 {
    char p[0x10];
    int idx;
};
struct Hit_182420 {
    void Go_001d6770();
};
struct Mgr_182420 {
    void Play_0003acf0(int i, int a, int b, int c, int d, int e);
    char p[0x128];
    Hit_182420* def;
};
struct Sing {
    Mgr_182420* Find_00059a30();
};
struct Tgt_182420 {
};

} // namespace fn_fd0c682a

// 0x00182420 hulkfight::motion::PropDestroyAction::vfunc_3 (100 B): matches/0x00182420.cpp
// sym: ?vfunc_3@PropDestroyAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropDestroyAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!(*(Tgt_182420 * *)&this->f_20))
        return false;
    Mgr_182420* m = ((Sing *)((owners::Object_592a0 *)((*(Tgt_182420 * *)&this->f_20)))->FUN_000592a0())->Find_00059a30();
    int i = (*(Info_182420 * *)&this->f_1c)->idx;
    if (m) {
        Hit_182420* h;
        if (i < 0)
            h = m->def;
        else {
            if (i >= 8)
                return false;
            h = ((Hit_182420 *)((owners::C_35ef0 *)m)->FUN_00035ef0((hulk_intptr)i));
        }
        if (h) {
            m->Play_0003acf0(i, 0, -1, 0, 0, 0);
            h->Go_001d6770();
        }
    }
    return false;
}

