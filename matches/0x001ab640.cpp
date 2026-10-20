// Same code shape as 0x0012bc00 (propagated; names are from that function)
#include "gen/hulkfight.h"
extern char threat_vftable_1ab640;
struct Event_PathNameCondition_nv_1ab640 {
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(hulkfight::scenario::Event_PathNameCondition*);
class Event_TriggerVolumeNameCondition_1ab640 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_TriggerVolumeNameCondition_1ab640* vfunc_5(unsigned char);
};
Event_TriggerVolumeNameCondition_1ab640* Event_TriggerVolumeNameCondition_1ab640::vfunc_5(unsigned char param) {
    Event_TriggerVolumeNameCondition_1ab640* p = this;
    *(char**)p = &threat_vftable_1ab640;
    ((Event_PathNameCondition_nv_1ab640*)(((hulkfight::scenario::Event_PathNameCondition*)((char*)p + 0x10))))->f1();
    ((Event_PathNameCondition_nv_1ab640*)(((hulkfight::scenario::Event_PathNameCondition*)p)))->f2();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::scenario::Event_PathNameCondition*)p);
    return p;
}