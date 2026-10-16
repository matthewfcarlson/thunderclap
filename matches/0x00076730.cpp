#include "gen/fight.h"

extern "C" char DAT_003fe778[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CGrappleDrainHealthTrack_76730 {
  public:
    void Init();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

template <> void* fight::TrackFactoryTemplate<CGrappleDrainHealthTrack>::vfunc_5() {
    CGrappleDrainHealthTrack_76730* p = (CGrappleDrainHealthTrack_76730*)FUN_0008d690(0x18);
    if (p) {
        p->Init();
        *(unsigned int*)p = ((int)DAT_003fe778);
        return (void*)(p);
    }
    return (void*)(0);
}
