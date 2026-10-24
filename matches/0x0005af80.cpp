#include "gen/global.h"

#include "compat/ptr.h"
extern "C" char DAT_003f9a2c[];
class A_5af80 {
  public:
    void InitA();
};
class B_5af80 {
  public:
    void InitB();
};
class CGrappleOpportunityTrack_5af80 {
  public:
    void Finish();
};

void CGrappleSequenceTrack::FUN_0005af80() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f9a2c);
    ((A_5af80*)((char*)this + 0x1c))->InitA();
    ((B_5af80*)((char*)this + 0x0c))->InitB();
    ((CGrappleOpportunityTrack_5af80*)this)->Finish();
}
