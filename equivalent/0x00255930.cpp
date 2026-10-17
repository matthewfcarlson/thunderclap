// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventCrossFade::vfunc_2 @ 0x00255930
typedef unsigned int size_t;
void* __cdecl FUN_00247530(void*);
extern char DAT_004e74c0;
namespace audio {
struct SeqEventCrossFade;
struct SeqActionCrossFade {
    virtual void vfunc_0();
    char pad[4];
    SeqEventCrossFade* event;
    int valueC, value10, value14, value18;
    SeqActionCrossFade() : event(0), valueC(0), value10(0), value14(0), value18(0) {}
};
struct SeqContext { void FUN_0025dc20(SeqActionCrossFade*); };
struct SeqEventCrossFade {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(SeqContext*);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
void SeqEventCrossFade::vfunc_2(SeqContext* context) {
    SeqActionCrossFade* action = (SeqActionCrossFade*)FUN_00247530(&DAT_004e74c0);
    if (action) {
        action->value10 = 0;
        action->value14 = 0;
        action->value18 = 0;
        action->valueC = 0;
        action->SeqActionCrossFade::SeqActionCrossFade();
        action->event = this;
    }
    context->FUN_0025dc20(action);
}
}
