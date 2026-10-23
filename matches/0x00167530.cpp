// Same code shape as 0x0012bc00 (propagated; names are from that function)
#include "gen/hulkfight.h"
extern char threat_vftable_167530;
struct RayCastConeCondition_nv_167530 {
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(hulkfight::motion::RayCastConeCondition*);
class RayCastTargetCondition_167530 {
  public:
    void* vftable;
    char pad[0x0c];
    RayCastTargetCondition_167530* vfunc_5(unsigned char);
};
RayCastTargetCondition_167530* RayCastTargetCondition_167530::vfunc_5(unsigned char param) {
    RayCastTargetCondition_167530* p = this;
    *(char**)p = &threat_vftable_167530;
    ((RayCastConeCondition_nv_167530*)(((hulkfight::motion::RayCastConeCondition*)(((hulkfight::motion::RayCastConeCondition*)((char*)p + 0x10))))))->f1();
    ((RayCastConeCondition_nv_167530*)(((hulkfight::motion::RayCastConeCondition*)(((hulkfight::motion::RayCastConeCondition*)p)))))->f2();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::RayCastConeCondition*)p);
    return p;
}