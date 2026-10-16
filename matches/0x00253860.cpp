// Same code shape as 0x0024ea80 (propagated; names are from that function)
#include "gen/audio.h"

class SeqAction_253860 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};

void audio::SeqActionVarPitch::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}
