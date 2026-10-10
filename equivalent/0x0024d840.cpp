// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 2/2)
// audio::ListenerEffectXBoxType::vfunc_2 @ 0x0024d840
struct EffectRegistry;
namespace audio {
struct ListenerEffectXBox {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(EffectRegistry*);
    void FUN_0025fb00();
};
struct ListenerEffectXBoxType {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual ListenerEffectXBox* vfunc_2();
    virtual void vfunc_3();
};
}
struct EffectRegistry {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual audio::ListenerEffectXBox* vfunc_3(audio::ListenerEffectXBox*);
};
extern char DAT_004e6468[];
audio::ListenerEffectXBox* __cdecl FUN_00247530(void*);
audio::ListenerEffectXBox* audio::ListenerEffectXBoxType::vfunc_2() {
    ListenerEffectXBox* result = FUN_00247530(DAT_004e6468);
    if (result) {
        result->FUN_0025e6f0((EffectRegistry*)DAT_004e6468);
        ListenerEffectXBox initial;
        *(void**)result = *(void**)&initial;
        ListenerEffectXBox* object = ((EffectRegistry*)DAT_004e6468)->vfunc_3(result);
        object->FUN_0025fb00();
    }
    return result;
}