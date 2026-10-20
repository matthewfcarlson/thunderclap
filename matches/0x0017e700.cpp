#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00417b68[];
class TeleportTrackBase {
  public:
    void Ctor();
};
struct TeleportTrack_17e700 {
    void* vt;
    int pad;
    int one;
    int z1;
    int z2;
    int z3;
    float last;
};
extern void* Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TeleportTrack>::vfunc_5() {
    TeleportTrack_17e700* p = (TeleportTrack_17e700*)Alloc(0x1c);
    if (p) {
        ((TeleportTrackBase*)p)->Ctor();
        p->vt = (void*)((hulk_intptr)DAT_00417b68);
        p->z1 = 0;
        p->z2 = 0;
        p->z3 = 0;
        p->last = -1.0f;
        p->one = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
