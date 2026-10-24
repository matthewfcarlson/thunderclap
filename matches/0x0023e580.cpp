#include "gen/fight.h"

#include "compat/ptr.h"
class Inner_23e580 {
  public:
    void Init();
};
struct StopTrack_nv_23e580 {
    void Finish();
};
extern int StopTrack_vftable;

void fight::StopTrack::FUN_0023e580() {
    *(hulk_intptr*)this = (hulk_intptr)&StopTrack_vftable;
    ((Inner_23e580*)((char*)this + 0x14))->Init();
    ((StopTrack_nv_23e580*)this)->Finish();
}
