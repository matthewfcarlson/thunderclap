// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 2/2)
// audio::ListenerEffectXBoxType::vfunc_2 @ 0x0024d840
#include "gen/audio.h"

struct EffectRegistry;
namespace audio {
struct ListenerEffectXBox_24d840 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(EffectRegistry*);
    void FUN_0025fb00();
};
}
struct EffectRegistry {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual audio::ListenerEffectXBox_24d840* vfunc_3(audio::ListenerEffectXBox_24d840*);
};
extern char DAT_004e6468[];
audio::ListenerEffectXBox_24d840* __cdecl FUN_00247530(void*);
void* audio::ListenerEffectXBoxType::vfunc_2() {
    ListenerEffectXBox_24d840* result = FUN_00247530(DAT_004e6468);
    if (result) {
        result->FUN_0025e6f0((EffectRegistry*)DAT_004e6468);
        ListenerEffectXBox_24d840 initial;
        *(void**)result = *(void**)&initial;
        ListenerEffectXBox_24d840* object = ((EffectRegistry*)DAT_004e6468)->vfunc_3(result);
        object->FUN_0025fb00();
    }
    return (void*)(result);
}
