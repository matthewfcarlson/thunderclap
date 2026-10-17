// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventVarTempo::vfunc_2 @ 0x00252ed0
namespace audio {
struct SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct SeqActionVarTempo { virtual void vfunc_0(); char pad[4]; SeqEvent* event; int value; };
struct SeqEventVarTempo : SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); };
}
extern char DAT_004e6f40;
extern char DAT_0042a090;
extern "C" void* __cdecl FUN_00247530(void*);
struct Receiver { void FUN_0025dc20(audio::SeqActionVarTempo*); };
void audio::SeqEventVarTempo::vfunc_2(void* receiver) {
    audio::SeqActionVarTempo* action = (audio::SeqActionVarTempo*)FUN_00247530(&DAT_004e6f40);
    if (action) {
        *(void**)action = &DAT_0042a090;
        action->event = this;
        action->value = 0;
    }
    ((Receiver*)receiver)->FUN_0025dc20(action);
}