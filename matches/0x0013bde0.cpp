#include "compat/ptr.h"
extern "C" {
extern "C" char DAT_00412570[];
void __cdecl opdel(void*);
void _ReadWriteBarrier();
}

class RefObj_13bde0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup();

    char pad[0x18];
    int m1c;
    RefObj_13bde0* m20;
    RefObj_13bde0* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_00412570;
    _ReadWriteBarrier();
    RefObj_13bde0* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13bde0* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
