// Same code shape as 0x0012bc00 (propagated; names are from that function)
#include "gen/fight.h"
extern char threat_vftable_23f1f0;
struct BreakPointTrack_nv_23f1f0 {
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(fight::BreakPointTrack*);
class BreakPointTrack_23f1f0 {
  public:
    void* vftable;
    char pad[0x0c];
    BreakPointTrack_23f1f0* vfunc_5(unsigned char);
};
BreakPointTrack_23f1f0* BreakPointTrack_23f1f0::vfunc_5(unsigned char param) {
    BreakPointTrack_23f1f0* p = this;
    *(char**)p = &threat_vftable_23f1f0;
    ((BreakPointTrack_nv_23f1f0*)(((fight::BreakPointTrack*)((char*)p + 0x10))))->f1();
    ((BreakPointTrack_nv_23f1f0*)(((fight::BreakPointTrack*)p)))->f2();
    if (param & 1)
        thunk_FUN_00267090((fight::BreakPointTrack*)p);
    return p;
}