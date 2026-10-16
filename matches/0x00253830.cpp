#include "gen/audio.h"

class SeqAction_253830 {
  public:
    virtual void f0();
    virtual void f1(void*);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Holder_253830 {
  public:
    char pad[0x1c];
    int value;
};

void audio::SeqActionVarPitch::vfunc_1(void* __p0) { void * param = (void *)__p0;

    Holder_253830* h = *(Holder_253830**)((char*)param + 4);
    h->value = *(int*)((char*)this + 8) + 8;
    *(int*)((char*)this + 0xc) = 0;
}
