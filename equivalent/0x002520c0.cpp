// STATUS: equivalent (tools/equiv.py level 3: 2853 inputs, branch coverage 6/6)
// audio::SeqEventChannelVolumes::vfunc_1 @ 0x002520c0
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual unsigned char vfunc_1(void **);
};
struct SeqEventChannelVolumes : SeqEvent {
    char pad[0x14];
    float fadeTime;
    virtual unsigned char vfunc_1(void **);
};
}
struct Output { char pad[0x24]; int depth; };
unsigned char __cdecl FUN_00246f50(Output *, const char *, ...);
unsigned char __cdecl FUN_0024eb60(void **, const char *, float *);
unsigned char audio::SeqEventChannelVolumes::vfunc_1(void **stream) {
    if (SeqEvent::vfunc_1(stream)) {
        if (FUN_00246f50((Output *)*stream, "\n[\n")) {
            ++((Output *)*stream)->depth;
            if (FUN_0024eb60(stream, "mFadeTime", &fadeTime))
                FUN_00246f50((Output *)*stream, "%s ", "mLayerNameBuf");
        }
    }
    return 0;
}