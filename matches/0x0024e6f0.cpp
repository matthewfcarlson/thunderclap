#include "decls/data/engine/audio.h"
// data: gName_24e6f0 = DAT_0042989c, gPool_24e6f0 = DAT_004e6698

#include "compat/ptr.h"
#include "gen/audio.h"
#include "gen/owners.h"

typedef unsigned int u32_24e6f0;
extern void* __cdecl Acquire(void*);
extern int gVtable_24e6f0;
class NameObj_24e6f0 {
  public:
};
class NestTrack_24e6f0 {
  public:
    hulk_uintptr vf;
    char pad[4];
    NameObj_24e6f0 name;
    void init();
};

void* audio::SeqEventNestTrackType::vfunc_3() {
    NestTrack_24e6f0* p = (NestTrack_24e6f0*)Acquire(((char*)&DAT_004e6698));
    if (p) {
        p->init();
        p->vf = (hulk_uintptr)&gVtable_24e6f0;
        ((owners::String_23fc40 *)&(p->name))->FUN_0023fc40(DAT_0042989c, (hulk_intptr)2);
        return (void*)(p);
    }
    return (void*)(0);
}
