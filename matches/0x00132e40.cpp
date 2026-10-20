#include "compat/ptr.h"
#include "gen/fight.h"

extern void* __cdecl Alloc(hulk_uintptr);
extern char statVftable[];
class TrackFactory_132e40 {
  public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
};
class StatEndTrialTrack_132e40 {
  public:
    int pad[3];
    int a;
    int b;
    StatEndTrialTrack_132e40();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::StatEndTrialTrack>::vfunc_5() {
    StatEndTrialTrack_132e40* p = (StatEndTrialTrack_132e40*)Alloc(0x14);
    if (p) {
        p->StatEndTrialTrack_132e40::StatEndTrialTrack_132e40();
        *(hulk_intptr*)p = (hulk_intptr)statVftable;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
