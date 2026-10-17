// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventChannelVolumes::vfunc_2 @ 0x00252190
struct AllocationPool { char byte; };
extern AllocationPool DAT_004e6ce0;
void* __cdecl FUN_00247530(AllocationPool*);
namespace audio {
struct SeqEventChannelVolumes;
struct SeqActionChannelVolumes {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char padding[4];
    SeqEventChannelVolumes* source;
    int state;
};
struct SeqEventChannelVolumes {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* context);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
}
struct Context { void FUN_0025dc20(audio::SeqActionChannelVolumes*); };
void audio::SeqEventChannelVolumes::vfunc_2(void* context) {
    void* memory = FUN_00247530(&DAT_004e6ce0);
    audio::SeqActionChannelVolumes* action = (audio::SeqActionChannelVolumes*)memory;
    if (action) {
        action->audio::SeqActionChannelVolumes::SeqActionChannelVolumes();
        action->source = this;
        action->state = 0;
    }
    ((Context*)context)->FUN_0025dc20(action);
}
