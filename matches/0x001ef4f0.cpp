#include "gen/global.h"
#include "decls/data/game/unknown.h"

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
