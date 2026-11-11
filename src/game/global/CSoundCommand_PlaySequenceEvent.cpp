// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef410..0x001ef470 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlaySequenceEvent
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f0cd7e54 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0cd7e54 {} using namespace fn_f0cd7e54;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0cd7e54 {
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


// 0x001ef410 CSoundCommand_PlaySequenceEvent::vfunc_1 (95 B): matches/0x001ef410.cpp
// sym: ?vfunc_1@CSoundCommand_PlaySequenceEvent@fn_f0cd7e54@@UAEXHH@Z
// data: gCount_1ef410 = DAT_004e371c, gFail = DAT_004e3724, gMiss = DAT_004e3720, gSound_1ef410 = DAT_004e370c
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

} // namespace fn_f0cd7e54
