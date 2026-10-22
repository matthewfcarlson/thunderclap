#include "compat/ptr.h"
extern "C" char DAT_00410c34[];
extern "C" void* __cdecl alloc(hulk_uintptr);
struct ThreatDistanceCondition_12d530 {
    void* vt;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float d;
    void Init(int x);
};
ThreatDistanceCondition_12d530* target() {
    ThreatDistanceCondition_12d530* p = (ThreatDistanceCondition_12d530*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = (void*)((hulk_intptr)DAT_00410c34);
        p->c = 0;
        p->d = 1.0f;
        return p;
    }
    return 0;
}
