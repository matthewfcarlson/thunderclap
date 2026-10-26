#include "compat/ptr.h"
#include "gen/audio.h"

class SeqAction_24ea70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

void audio::SeqActionChannelSendVolumes::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}
