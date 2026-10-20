#include "gen/hulkfight.h"
extern "C" char DAT_00410c14[];
void* __cdecl alloc28(unsigned int);
struct Sub_12d750 {
    int a;
    int b;
    void Init();
};
struct ThreatDistanceCondition_nv_12d750 {
    void Init(int);
};
class ThreatAngleCondition_12d750 {
  public:
    int vtable;
    char pad4[8];
    int c;
    int f;
    char pad14[4];
    Sub_12d750 sub;
    char enabled;
    char pad21[7];
};
ThreatAngleCondition_12d750* factory_vfunc5() {
    ThreatAngleCondition_12d750* p = (ThreatAngleCondition_12d750*)alloc28(0x28);
    if (p) {
        ((ThreatDistanceCondition_nv_12d750*)(((hulkfight::ai::ThreatDistanceCondition*)p)))->Init(0);
        p->vtable = ((int)DAT_00410c14);
        p->c = 0;
        p->f = 0x3fc90fdb;
        p->sub.Init();
        p->enabled = 1;
        return p;
    }
    return 0;
}
