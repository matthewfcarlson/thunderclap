// Same code shape as 0x0024ea70 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/audio.h"

class SeqAction_252860 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

void audio::SeqActionVarVolume::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}
