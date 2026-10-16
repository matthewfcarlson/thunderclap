#include "gen/fight.h"

extern "C" char DAT_0041956c[];
extern "C" void* Alloc(unsigned int);
class Track_18c3d0 {
  public:
    Track_18c3d0();
    virtual void a();
    virtual void b();
    virtual void c();
};
class PropDamageTrack_18c3d0 : public Track_18c3d0 {
  public:
    int x4;
    int x8;
    int xc;
    int x10;
    int x14;
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropDamageTrack>::vfunc_5() {
    PropDamageTrack_18c3d0* p = (PropDamageTrack_18c3d0*)Alloc(0x18);
    if (p) {
        p->Track_18c3d0::Track_18c3d0();
        *(volatile unsigned int*)p = ((int)DAT_0041956c);
        p->xc = 0;
        p->x10 = 0;
        p->x14 = 0;
        p->x8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
