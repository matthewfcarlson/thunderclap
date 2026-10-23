#include "gen/global.h"

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
extern SoundMgr* gSoundMgr;
class CSoundCommand_1ef570 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};

void CSoundCommand_PlayMissionDialogueEvent::vfunc_1(int a, int b) {
    SoundMgr* mgr = gSoundMgr;
    Resolver* r = mgr->resolver;
    int item = r->Lookup(&this->f_10);
    if (item)
        gSoundMgr->player->Play(item, (char*)this + 0x18, a, (char*)this + 0x20, this->f_1c, (*(unsigned char *)&this->f_40));
}
