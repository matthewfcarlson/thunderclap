#include "compat/ptr.h"
extern char VT_004179e8[];
class Track_170270 {
  public:
    Track_170270();
    virtual void f();
    char pad[4];
};
class LocomotionStateTrack : public Track_170270 {
  public:
    LocomotionStateTrack();
    virtual void f();
    int m8;
    int mc;
    int m10;
};
LocomotionStateTrack::LocomotionStateTrack() {
    mc = 0;
    m10 = 0;
    *(void**)this = (void*)((hulk_intptr)VT_004179e8);
    m8 = 1;
}
