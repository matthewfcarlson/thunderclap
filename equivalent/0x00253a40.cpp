// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventVarPitch::vfunc_2 @ 0x00253a40
namespace audio {
struct Sequencer;
struct SeqEventVarPitch;
struct SeqActionVarPitch {
    void** vtable;
    int unknown;
    SeqEventVarPitch* event;
    int value;
};
struct SeqEventVarPitch { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(Sequencer*); };
struct Sequencer { void FUN_0025dc20(SeqActionVarPitch* action); };
}
extern char DAT_004e7150;
extern void* DAT_0042a244;
void* __cdecl FUN_00247530(void*);
void audio::SeqEventVarPitch::vfunc_2(audio::Sequencer* sequencer) {
    audio::SeqActionVarPitch* action = (audio::SeqActionVarPitch*)FUN_00247530(&DAT_004e7150);
    if (action) {
        action->vtable = &DAT_0042a244;
        action->event = this;
        action->value = 0;
    }
    sequencer->FUN_0025dc20(action);
}