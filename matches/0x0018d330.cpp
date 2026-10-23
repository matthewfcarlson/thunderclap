// Same code shape as 0x0012bc00 (propagated; names are from that function)
#include "gen/hulkfight.h"
extern char threat_vftable_18d330;
struct TimerCondition_nv_18d330 {
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(hulkfight::motion::TimerCondition*);
class GrappleVarCompareCondition_18d330 {
  public:
    void* vftable;
    char pad[0x0c];
    GrappleVarCompareCondition_18d330* vfunc_5(unsigned char);
};
GrappleVarCompareCondition_18d330* GrappleVarCompareCondition_18d330::vfunc_5(unsigned char param) {
    GrappleVarCompareCondition_18d330* p = this;
    *(char**)p = &threat_vftable_18d330;
    ((TimerCondition_nv_18d330*)(((hulkfight::motion::TimerCondition*)(((hulkfight::motion::TimerCondition*)((char*)p + 0x10))))))->f1();
    ((TimerCondition_nv_18d330*)(((hulkfight::motion::TimerCondition*)(((hulkfight::motion::TimerCondition*)p)))))->f2();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::TimerCondition*)p);
    return p;
}