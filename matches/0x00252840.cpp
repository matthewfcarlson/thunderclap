#include "gen/audio.h"

class SeqAction_252840 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(void*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};

void audio::SeqActionVarVolume::vfunc_1(void* __p0) { void * p = (void *)__p0;

    *(int*)((char*)*(int*)((char*)p + 4) + 0x18) = this->f_08 + 8;
    this->f_0c = 0;
}
