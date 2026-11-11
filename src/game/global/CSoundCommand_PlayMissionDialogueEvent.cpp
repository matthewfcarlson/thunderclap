// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef570..0x001ef5b0 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayMissionDialogueEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fe14a887 {
#define TREE_TU_END }
namespace fn_fe14a887 {} using namespace fn_fe14a887;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe14a887 {
struct Resolver {
    int Lookup(void*);
};
struct Player {
    void Play(int, void*, int, void*, int, unsigned char);
};
struct SoundMgr {
    Player* player;
    Resolver* resolver;
};
class CSoundCommand_1ef570 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};

} // namespace fn_fe14a887

// 0x001ef570 CSoundCommand_PlayMissionDialogueEvent::vfunc_1 (64 B): matches/0x001ef570.cpp
// sym: ?vfunc_1@CSoundCommand_PlayMissionDialogueEvent@@UAEXHH@Z
// data: gSoundMgr = DAT_004e370c
void CSoundCommand_PlayMissionDialogueEvent::vfunc_1(int a, int b) {
    SoundMgr* mgr = (*(SoundMgr**)&DAT_004e370c);
    Resolver* r = mgr->resolver;
    int item = r->Lookup(&this->f_10);
    if (item)
        (*(SoundMgr**)&DAT_004e370c)->player->Play(item, (char*)this + 0x18, a, (char*)this + 0x20, this->f_1c, (*(unsigned char *)&this->f_40));
}

