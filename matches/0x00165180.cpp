#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_165180;
struct Factory_165180 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_165180 vfunc_5();
};
extern "C" void* FUN_0008d690(unsigned int);
struct Product {
    hulk_uintptr Initialize();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HeliLocomotionTrack>::vfunc_5() {
    Product* p = (Product*)FUN_0008d690(0xd8);
    if (p)
        return (void*)(p->Initialize());
    return (void*)(0);
}
