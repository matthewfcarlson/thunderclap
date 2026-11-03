// Same code shape as 0x0024e6f0 (propagated; names are from that function)
#include "decls/data/engine/audio.h"
// data: gName_250ba0 = DAT_00429ca4, gPool_250ba0 = DAT_004e6b18

#include "compat/ptr.h"
#include "gen/audio.h"
#include "gen/owners.h"

typedef unsigned int u32_250ba0;
extern "C" void* __cdecl FUN_00247530(void*);
extern int gVtable_250ba0;
class NameObj_250ba0 {
  public:
};
class NestTrack_250ba0 {
  public:
    hulk_uintptr vf;
    char pad[4];
    NameObj_250ba0 name;
    void init();
};

void* audio::SeqEventExpressionType::vfunc_3() {
    NestTrack_250ba0* p = (NestTrack_250ba0*)FUN_00247530(((char*)&DAT_004e6b18));
    if (p) {
        p->init();
        p->vf = (hulk_uintptr)&gVtable_250ba0;
        ((owners::String_23fc40 *)&(p->name))->FUN_0023fc40(DAT_00429ca4, (hulk_intptr)2);
        return (void*)(p);
    }
    return (void*)(0);
}
