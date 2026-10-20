#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040f500[];
class StrafeLateralHBTrack_122f70 {
  public:
    int vf;
    char pad4[8];
    int zc;
    int x10;
    int z14, z18, z1c, z20, x24;
    void init();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_5() {
    StrafeLateralHBTrack_122f70* p = (StrafeLateralHBTrack_122f70*)operator_new(0x28);
    if (p) {
        p->init();
        p->zc = 0;
        p->z14 = 0;
        p->z18 = 0;
        p->z1c = 0;
        p->z20 = 0;
        p->vf = ((hulk_intptr)DAT_0040f500);
        p->x10 = (int)0xbf800000;
        p->x24 = 0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}
