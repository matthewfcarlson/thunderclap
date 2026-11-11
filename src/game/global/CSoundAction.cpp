// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014bb0..0x00014c30 (kind game, layer game, confidence medium), dominant class CSoundAction
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0f741bf {
#define TREE_TU_END }
namespace fn_f0f741bf {} using namespace fn_f0f741bf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0f741bf {
struct C_14bb0 {
};
struct B_14bb0 {
    C_14bb0* GetC();
};
struct A_14bb0 {
};
struct SoundObj_14bb0 {
    char pad[0x10];
    char data[0x40];
    char flag;
};
struct Out_14bb0 {
    void Send(C_14bb0*, void*);
    void Play(Z*, void*, float, int);
};
struct Mgr_14bb0 {
    char pad[0x34];
    Out_14bb0* out;
};
extern Mgr_14bb0* gMgr_14bb0;

} // namespace fn_f0f741bf

// 0x00014bb0 CSoundAction::vfunc_7 (116 B): matches/0x00014bb0.cpp
// sym: ?vfunc_7@CSoundAction@@UAE_NH@Z
bool CSoundAction::vfunc_7(int ) {
    C_14bb0* c = ((B_14bb0 *)((owners::Object_592a0 *)((*(A_14bb0 * *)&this->f_1c)))->FUN_000592a0())->GetC();
    if (!(*(SoundObj_14bb0 * *)&this->f_20)->flag) {
        gMgr_14bb0->out->Send(c, (*(SoundObj_14bb0 * *)&this->f_20)->data);
        return false;
    }
    if (((owners::C_35f20 *)c)->FUN_00035f20()) {
        Z* z = ((Z *)((owners::C_35ef0 *)c)->FUN_00035ef0((hulk_intptr)0));
        if (z)
            gMgr_14bb0->out->Play(z, (*(SoundObj_14bb0 * *)&this->f_20)->data, 100.0f, 0);
    }
    return false;
}

