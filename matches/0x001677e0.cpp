// Same code shape as 0x0012bc00 (propagated; names are from that function)
#include "gen/hulkfight.h"
extern char threat_vftable_1677e0;
struct RayCastCondition_nv_1677e0 {
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(hulkfight::motion::RayCastCondition*);
class RayCastCondition_1677e0 {
  public:
    void* vftable;
    char pad[0x0c];
    RayCastCondition_1677e0* vfunc_5(unsigned char);
};
RayCastCondition_1677e0* RayCastCondition_1677e0::vfunc_5(unsigned char param) {
    RayCastCondition_1677e0* p = this;
    *(char**)p = &threat_vftable_1677e0;
    ((RayCastCondition_nv_1677e0*)(((hulkfight::motion::RayCastCondition*)((char*)p + 0x10))))->f1();
    ((RayCastCondition_nv_1677e0*)(((hulkfight::motion::RayCastCondition*)p)))->f2();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::RayCastCondition*)p);
    return p;
}