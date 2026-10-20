#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern char vt[];
class Base {
  public:
    Base();
    char pad[8];
};
class HitPauseTrack : public Base {
  public:
    HitPauseTrack();
    int m8;
    int mC;
    int m10;
    int m14;
};
HitPauseTrack::HitPauseTrack() : Base() {
    mC = 0;
    m10 = 0;
    m14 = 0;
    *(hulk_intptr*)this = (hulk_intptr)vt;
    m8 = 1;
}
