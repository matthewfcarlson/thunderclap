#include "gen/audio.h"

class SeqAction_252c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

void audio::SeqActionVarTempo::vfunc_1(void* __p0) { void * param = (void *)__p0;

    *(int*)(*(int*)((char*)param + 4) + 0x28) = this->f_08 + 0x10;
    *(int*)(*(int*)((char*)param + 4) + 0x30) = this->f_08 + 8;
    this->f_0c = 0;
}
