#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00417c28[];
struct Base_17e910 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct CriticalMassDrainTrack_17e910 : Base_17e910 {
    int pad4;
    int m8;
    int mC;
    int m10;
    void Init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_5() {
    CriticalMassDrainTrack_17e910* p = (CriticalMassDrainTrack_17e910*)operator_new(0x14);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00417c28);
        p->mC = 0;
        p->m10 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
