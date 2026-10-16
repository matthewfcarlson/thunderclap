#include "gen/audio.h"

typedef unsigned int u32_24e6f0;
extern void* __cdecl Acquire(void*);
extern char gPool_24e6f0;
extern const char gName_24e6f0[];
extern int gVtable_24e6f0;
class NameObj_24e6f0 {
  public:
    void set(const char*, int);
};
class NestTrack_24e6f0 {
  public:
    u32_24e6f0 vf;
    char pad[4];
    NameObj_24e6f0 name;
    void init();
};

void* audio::SeqEventNestTrackType::vfunc_3() {
    NestTrack_24e6f0* p = (NestTrack_24e6f0*)Acquire(&gPool_24e6f0);
    if (p) {
        p->init();
        p->vf = (u32_24e6f0)&gVtable_24e6f0;
        p->name.set(gName_24e6f0, 2);
        return (void*)(p);
    }
    return (void*)(0);
}
