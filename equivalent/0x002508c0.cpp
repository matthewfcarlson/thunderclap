// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventWaitBeat::vfunc_2 @ 0x002508c0
typedef unsigned int size_t;
__forceinline void* __cdecl operator new(size_t, void* p) { return p; }
namespace audio {
struct SeqEventWaitBeat;
struct SeqActionWaitBeat {
 virtual void vfunc_0();
 virtual void vfunc_1();
 unsigned int unknown4;
 SeqEventWaitBeat* event;
 unsigned int unknownC;
 unsigned int unknown10;
 unsigned int unknown14;
};
struct SeqEventWaitBeat {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2(void* sequence);
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
};
}
extern char DAT_004e6a18;
extern "C" audio::SeqActionWaitBeat* __cdecl FUN_00247530(void*);
struct Sequence { void FUN_0025dc20(audio::SeqActionWaitBeat*); };
void audio::SeqEventWaitBeat::vfunc_2(void* sequence) {
 audio::SeqActionWaitBeat* action = FUN_00247530(&DAT_004e6a18);
 if (action) {
  new (action) audio::SeqActionWaitBeat;
  action->unknown10 = 0;
  action->unknown14 = 0;
  action->unknownC = 0;
  action->event = this;
 }
 ((Sequence*)sequence)->FUN_0025dc20(action);
}
