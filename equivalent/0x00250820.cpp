// STATUS: equivalent (tools/equiv.py level 3: 2823 inputs, branch coverage 4/4)
// audio::SeqEventWaitBeat::vfunc_1 @ 0x00250820
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual bool vfunc_1(struct SeqEventArg* arg);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct SeqEventWaitBeat : SeqEvent {
    virtual void vfunc_0();
    virtual bool vfunc_1(struct SeqEventArg* arg);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
struct SeqEventData {
    char pad[0x24];
    int layerCount;
};
struct SeqEventArg { SeqEventData* data; };
}
extern bool __cdecl FUN_00246f50(audio::SeqEventData*, const char*, ...);
bool audio::SeqEventWaitBeat::vfunc_1(audio::SeqEventArg* arg) {
    if (audio::SeqEvent::vfunc_1(arg) && FUN_00246f50(arg->data, "\n[\n")) {
        ++arg->data->layerCount;
        FUN_00246f50(arg->data, "%s ", "mLayerNameBuf");
    }
    return false;
}