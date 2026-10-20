#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fba00[];
struct CScrubberTrack_77d90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    void Ctor();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CScrubberTrack>::vfunc_5() {
    CScrubberTrack_77d90* p = (CScrubberTrack_77d90*)operator_new(0x0c);
    if (p) {
        p->Ctor();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fba00);
        return (void*)(p);
    }
    return (void*)(0);
}
