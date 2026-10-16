#include "gen/fight.h"

extern "C" char DAT_004112e4[];
typedef unsigned int u32_132b60;
extern "C" void* __cdecl alloc(unsigned int);
class Track_132b60 {
  public:
    Track_132b60();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::StatBeginTrialTrack>::vfunc_5() {
    Track_132b60* p = (Track_132b60*)alloc(0x14);
    if (p) {
        p->Track_132b60::Track_132b60();
        *(u32_132b60*)p = ((int)DAT_004112e4);
        *(u32_132b60*)((char*)p + 0xc) = 0;
        *(u32_132b60*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
