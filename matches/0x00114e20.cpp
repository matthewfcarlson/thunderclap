#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040dd04[];
class SemaphoreWaitTrack_114e20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl alloc(unsigned int);
struct BaseInit {
    void go();
};
struct MemberInit {
    void go();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_5() {
    SemaphoreWaitTrack_114e20* p = (SemaphoreWaitTrack_114e20*)alloc(0x28);
    if (p != 0) {
        ((BaseInit*)p)->go();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040dd04);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        ((MemberInit*)((char*)p + 0x18))->go();
        *((char*)p + 0x20) = 1;
        *((char*)p + 0x21) = 1;
        *(unsigned int*)((char*)p + 0x24) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
