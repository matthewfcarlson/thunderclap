#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern char vt[];
class Track_14dd70 {
  public:
    Track_14dd70();
    char pad[8];
};
class HitPauseTrack : public Track_14dd70 {
  public:
    HitPauseTrack();
    int m8;
    int mC;
    int m10;
    int m14;
};
HitPauseTrack::HitPauseTrack() : Track_14dd70() {
    mC = 0;
    m10 = 0;
    m14 = 0;
    *(hulk_intptr*)this = (hulk_intptr)vt;
    m8 = 1;
}
