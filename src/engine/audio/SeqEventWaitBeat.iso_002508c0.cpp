// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002504b0..0x00250960 (kind game, layer engine, confidence high), dominant class audio::SeqEventWaitBeat
#include "tree_prelude.h"
#include "compat/ptr.h"


// 0x002508c0 audio::SeqEventWaitBeat::vfunc_2 (70 B): equivalent/0x002508c0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?vfunc_2@SeqEventWaitBeat@audio@@UAEXH@Z @a1578b58bf7d @w92aae4a3e218
// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// audio::SeqEventWaitBeat::vfunc_2 @ 0x002508c0
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

/* size_t: tree_prelude.h */
__forceinline void* __cdecl operator new(size_t, void* p) { return p; }
namespace audio {

struct SeqActionWaitBeat_2508c0 {
 virtual void* vfunc_0_00250770(int);
 virtual void vfunc_1_002505f0(void*);
 unsigned int unknown4;
 audio::SeqEventWaitBeat* event;
 unsigned int unknownC;
 unsigned int unknown10;
 unsigned int unknown14;
};
}
extern "C" audio::SeqActionWaitBeat_2508c0* __cdecl FUN_00247530(void*);
struct Sequence_2508c0 { void FUN_0025dc20(audio::SeqActionWaitBeat_2508c0*); };
void audio::SeqEventWaitBeat::vfunc_2(hulk_intptr __p0) { void * sequence = (void *)__p0;

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

