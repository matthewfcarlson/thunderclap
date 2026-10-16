#include "gen/audio.h"

class HalStream_262c50 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};

void audio::HalRadicalAdpcmDecodeStream::vfunc_0() {
    this->f_1c = 1;
    if (!(*(HalStream_262c50 * *)&this->f_04)->vfunc_1())
        (*(HalStream_262c50 * *)&this->f_04)->vfunc_0();
}
