#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: gCount_1ef410 = DAT_004e371c, gFail = DAT_004e3724, gMiss = DAT_004e3720, gSound_1ef410 = DAT_004e370c

class Seq;
class Player_1ef410;
class SoundSystem_1ef410 {
  public:
    Player_1ef410* player;
    Seq* sequences;
};
class Seq {
  public:
    Seq* Find(void*);
};
class Player_1ef410 {
  public:
    void* Play(Seq*, int);
};
class Event_1ef410 {
  public:
    void Apply(void*);
};
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_PlaySequenceEvent : public CSoundCommand {
    char pad[12];
    int id;
    int pad2;
    Event_1ef410 event;

  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlaySequenceEvent::vfunc_1(int x, int y) {
    SoundSystem_1ef410* sys = (*(SoundSystem_1ef410* volatile*)&DAT_004e370c);
    ++(*(volatile int*)&DAT_004e371c);
    Seq* s = sys->sequences->Find(&id);
    if (!s) {
        ++DAT_004e3720;
        return;
    }
    int arg = x;
    SoundSystem_1ef410* sys2 = (*(SoundSystem_1ef410* volatile*)&DAT_004e370c);
    void* p = sys2->player->Play(s, arg);
    if (p) {
        ((Event_1ef410*)p)->Apply(&event);
        return;
    }
    ++DAT_004e3724;
}