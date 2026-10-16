#include "gen/fight.h"

extern "C" char DAT_00410bd4[];
typedef unsigned int u32_12d5e0;
typedef unsigned char u8;
extern void* __cdecl alloc(unsigned int);
struct Sub_12d5e0 {
    char pad[8];
    void init();
};
struct Threat_12d5e0 {
    u32_12d5e0 vptr;
    char pad4[8];
    u8 flagC;
    char padD[3];
    Sub_12d5e0 sub;
    u8 flag18;
    void init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::ThreatCondition>::vfunc_5() {
    Threat_12d5e0* p = (Threat_12d5e0*)alloc(0x20);
    if (p) {
        p->init(0);
        p->vptr = ((int)DAT_00410bd4);
        p->flagC = 1;
        p->sub.init();
        p->flag18 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
