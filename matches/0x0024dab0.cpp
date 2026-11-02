#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

class ListenerEffectPs2 {
  public:
    virtual void F0();
    virtual void F1();
    virtual ListenerEffectPs2* F2(unsigned char);
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    void Base();
};
extern "C" void FUN_00247550(void*, ListenerEffectPs2*);
ListenerEffectPs2* ListenerEffectPs2::F2(unsigned char flag) {
    Base();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6548), this);
    return this;
}