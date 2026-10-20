#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040d854[];
extern "C" void* __cdecl alloc(hulk_uintptr);
class Face {
  public:
    Face();
    hulk_intptr vf;
    int pad4;
    int m8;
    int mc;
    float m10;
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_5() {
    Face* p = (Face*)alloc(0x14);
    if (p) {
        p->Face::Face();
        p->vf = ((hulk_intptr)DAT_0040d854);
        p->mc = 0;
        p->m10 = -1.0f;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
