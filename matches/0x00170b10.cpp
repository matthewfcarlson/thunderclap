#include "compat/ptr.h"
extern "C" char hulk_at_00417c24[];
class Track_170b10 {
  public:
    Track_170b10();
    virtual void V0();
};

class CriticalMassDrainTrack_170b10 : public Track_170b10 {
  public:
    CriticalMassDrainTrack_170b10();
    virtual void V1();
    char pad[4];
    int mBase8;
    int mC;
    int m10;
};

CriticalMassDrainTrack_170b10::CriticalMassDrainTrack_170b10() : Track_170b10() {
    mC = 0;
    m10 = 0;
    *(hulk_intptr*)this = ((hulk_intptr)(hulk_at_00417c24 + 0x4));
    mBase8 = 1;
}
