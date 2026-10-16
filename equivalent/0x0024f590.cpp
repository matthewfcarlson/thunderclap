// STATUS: equivalent (tools/equiv.py level 3: 2853 inputs, branch coverage 6/6)
// audio::SeqEventChannelSendVolumes::vfunc_1 @ 0x0024f590
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual bool vfunc_1(void **);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct SeqEventChannelSendVolumes : SeqEvent {
    char padding[0x48 - sizeof(SeqEvent)];
    float mFadeTime;
    virtual void vfunc_0();
    virtual bool vfunc_1(void **);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
}
struct ParseState { char pad[0x24]; int depth; };
extern "C" bool __cdecl FUN_00246f50(void *, const char *, ...);
extern "C" bool __cdecl FUN_0024eb60(void **, const char *, float *);
bool audio::SeqEventChannelSendVolumes::vfunc_1(void **state) {
    if (SeqEvent::vfunc_1(state) && FUN_00246f50(*state, "\n[\n")) {
        ++((ParseState *)*state)->depth;
        if (FUN_0024eb60(state, "mFadeTime", &mFadeTime))
            FUN_00246f50(*state, "%s ", "mLayerNameBuf");
    }
    return false;
}
