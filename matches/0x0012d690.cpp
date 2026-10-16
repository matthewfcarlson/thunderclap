#include "gen/fight.h"

extern "C" char DAT_00410bf4[];
typedef unsigned int u32_12d690;
extern void* Alloc(unsigned int);
struct Sub_12d690 {
    void Setup();
};
struct ThreatDistanceCondition_12d690 {
    u32_12d690 vf;
    char pad04[8];
    u32_12d690 mC;
    u32_12d690 mD;
    char pad14[4];
    Sub_12d690 sub;
    char pad1c[7];
    char flag;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::ThreatDistanceCondition>::vfunc_5() {
    ThreatDistanceCondition_12d690* p = (ThreatDistanceCondition_12d690*)Alloc(0x28);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_00410bf4);
        p->mC = 0;
        p->mD = 0;
        p->sub.Setup();
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
