// Same code shape as 0x000521a0 (propagated; names are from that function)
#include "gen/fight.h"

struct CFightNodeTimeCondition_76800 {
    virtual ~CFightNodeTimeCondition_76800();
    char pad[0x10];
    void Initialize();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* conditionVtable;

template <> void* fight::TrackFactoryTemplate<CGrappleIntangibleTrack>::vfunc_5() {
    CFightNodeTimeCondition_76800* p = (CFightNodeTimeCondition_76800*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_76800));
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
