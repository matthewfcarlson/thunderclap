// Same code shape as 0x0024e6f0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int u32_250310;
extern void* __cdecl Acquire(void*);
extern char gPool_250310;
extern const char gName_250310[];
extern int gVtable_250310;
class NameObj_250310 {
  public:
    void set(const char*, int);
};
class NestTrack_250310 {
  public:
    u32_250310 vf;
    char pad[4];
    NameObj_250310 name;
    void init();
};

void* audio::SeqEventWaitType::vfunc_3() {
    NestTrack_250310* p = (NestTrack_250310*)Acquire(&gPool_250310);
    if (p) {
        p->init();
        p->vf = (hulk_uintptr)&gVtable_250310;
        p->name.set(gName_250310, 2);
        return (void*)(p);
    }
    return (void*)(0);
}
