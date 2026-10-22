#include "compat/ptr.h"
struct Track_14ded0 {
    Track_14ded0();
    virtual void vfn();
};

class HitWaitTrack_14ded0 : public Track_14ded0 {
  public:
    char pad[8];
    int m0c;
    int m10;
    HitWaitTrack_14ded0();
};

extern "C" void _ReadWriteBarrier();

extern int vftable[];

HitWaitTrack_14ded0::HitWaitTrack_14ded0() {
    m0c = 0;
    m10 = 0;
    *(hulk_intptr*)this = (hulk_intptr)vftable;
}
