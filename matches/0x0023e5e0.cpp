#include "compat/ptr.h"
extern "C" char DAT_00428db0[];
class Helper_23e5e0 {
  public:
    void first();
};
class StopTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual StopTrack* vfunc_5(unsigned char flag);
    char pad[0x14 - 4];
    Helper_23e5e0 h;
    void second();
};
void __cdecl destroy(StopTrack*);

StopTrack* StopTrack::vfunc_5(unsigned char flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_00428db0);
    h.first();
    second();
    if (flag & 1)
        destroy(this);
    return this;
}
