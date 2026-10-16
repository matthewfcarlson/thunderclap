#include "gen/fight.h"

extern "C" char DAT_003fbf68[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_77320 {
  public:
    void Init();
};
struct Orient_77320 {
    void* vptr;
    int x4;
    int x8;
    int xC;
    int x10;
    int x14;
    int x18;
    unsigned char x1c;
    char pad[3];
    int x20;
    int x24;
    int x28;
};

template <> void* fight::TrackFactoryTemplate<COrientTrack>::vfunc_5() {
    Orient_77320* p = (Orient_77320*)FUN_0008d690(0x2c);
    if (p) {
        ((Helper_77320*)p)->Init();
        p->xC = 0;
        p->x18 = 0;
        p->x1c = 0;
        p->x20 = 0;
        p->x24 = 0;
        p->x28 = 0;
        p->vptr = (void*)((int)DAT_003fbf68);
        p->x10 = 0xbf800000;
        p->x14 = 0xbc8efa35;
        p->x8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
