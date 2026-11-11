// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef4f0..0x001ef530 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayDialogueEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f7a186ee {
#define TREE_TU_END }
namespace fn_f7a186ee {} using namespace fn_f7a186ee;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7a186ee {
struct Lookup {
    int FUN_001e98b0(int*);
};
struct Player {
    void FUN_001f3c00(int, int*, int, int, int, unsigned char);
};
struct SoundSystem {
    Player* player;
    Lookup* lookup;
};

} // namespace fn_f7a186ee

// 0x001ef4f0 CSoundCommand_PlayDialogueEvent::vfunc_1 (60 B): matches/0x001ef4f0.cpp
// sym: ?vfunc_1@CSoundCommand_PlayDialogueEvent@@UAEXHH@Z
void CSoundCommand_PlayDialogueEvent::vfunc_1(int value, int unused) {
    SoundSystem* sys = (*(SoundSystem**)&DAT_004e370c);
    Lookup* lookup = sys->lookup;
    int result = lookup->FUN_001e98b0(&this->f_10);
    if (result) {
        int v = value;
        int* p = &this->f_18;
        unsigned char f = (*(unsigned char *)&this->f_1c);
        (*(SoundSystem**)&DAT_004e370c)->player->FUN_001f3c00(result, p, v, 0, 0, f);
    }
}

