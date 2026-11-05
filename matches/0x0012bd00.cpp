#include "compat/ptr.h"
extern "C" char DAT_00410c84[];
class ThreatDodgeTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual ThreatDodgeTrack* vfunc_5(unsigned char);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad[0x1c];
};
class Helper_12bd00 {
  public:
    void call1();
    void call2();
};
void FUN_0008d330(ThreatDodgeTrack*);
ThreatDodgeTrack* ThreatDodgeTrack::vfunc_5(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_00410c84);
    ((Helper_12bd00*)((char*)this + 0x20))->call1();
    ((Helper_12bd00*)this)->call2();
    if (flags & 1)
        FUN_0008d330(this);
    return this;
}