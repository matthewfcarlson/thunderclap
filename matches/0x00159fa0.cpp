#include "gen/fight.h"

extern "C" char DAT_00414390[];
struct HitFloatTrack_159fa0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    int x;
};
struct Initializer_159fa0 {
    void Init();
};
extern void* __cdecl Allocate(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitFloatTrack>::vfunc_5() {
    HitFloatTrack_159fa0* p = (HitFloatTrack_159fa0*)Allocate(0x28);
    if (p) {
        ((Initializer_159fa0*)p)->Init();
        *(int*)((char*)p + 12) = 0;
        *((char*)p + 20) = 0;
        *(int*)((char*)p + 24) = 0;
        *(int*)((char*)p + 32) = 0;
        *(int*)((char*)p + 36) = 0;
        *(void**)p = (void*)((int)DAT_00414390);
        *(unsigned int*)((char*)p + 16) = 0xbf800000;
        *(int*)((char*)p + 28) = -5;
        return (void*)(p);
    }
    return (void*)((HitFloatTrack_159fa0*)0);
}
