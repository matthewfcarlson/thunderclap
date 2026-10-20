#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00411be8[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Track_1394f0 {
  public:
    hulk_intptr vptr;
    int pad;
    int m2;
    int m3;
    float m4;
    int m5;
    void Init();
};
class GrappleHoverTrack_1394f0 : public Track_1394f0 {};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_5() {
    GrappleHoverTrack_1394f0* p = (GrappleHoverTrack_1394f0*)Alloc(0x18);
    if (p) {
        p->Init();
        p->vptr = ((hulk_intptr)DAT_00411be8);
        p->m3 = 0;
        p->m4 = -1.0f;
        p->m5 = 0;
        p->m2 = 1;
        return (void*)(p);
    }
    return (void*)((GrappleHoverTrack_1394f0*)0);
}
