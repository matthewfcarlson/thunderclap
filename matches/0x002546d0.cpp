#include "gen/audio.h"

class SeqAction_2546d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, char);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[0x1c];
};

void audio::SeqActionSilence::vfunc_2(int , int __p1) { char flag = (char)__p1;

    *(int*)((char*)this + 0x18) = 2;
    if (flag)
        *(int*)((char*)this + 0xc) = 0;
}
