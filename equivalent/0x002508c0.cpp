// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// audio::SeqEventWaitBeat::vfunc_2 @ 0x002508c0
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
__forceinline void* __cdecl operator new(size_t, void* p) { return p; }
namespace audio {

struct SeqActionWaitBeat_2508c0 {
 virtual void vfunc_0();
 virtual void vfunc_1();
 unsigned int unknown4;
 audio::SeqEventWaitBeat* event;
 unsigned int unknownC;
 unsigned int unknown10;
 unsigned int unknown14;
};
}
extern "C" audio::SeqActionWaitBeat_2508c0* __cdecl FUN_00247530(void*);
struct Sequence_2508c0 { void FUN_0025dc20(audio::SeqActionWaitBeat_2508c0*); };
void audio::SeqEventWaitBeat::vfunc_2(int __p0) { void * sequence = (void *)__p0;

 audio::SeqActionWaitBeat_2508c0* action = FUN_00247530(((char*)&DAT_004e6a18));
 if (action) {
  new (action) audio::SeqActionWaitBeat_2508c0;
  action->unknown10 = 0;
  action->unknown14 = 0;
  action->unknownC = 0;
  action->event = this;
 }
 ((Sequence_2508c0*)sequence)->FUN_0025dc20(action);
}
