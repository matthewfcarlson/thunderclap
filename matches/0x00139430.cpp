#include "gen/fight.h"

extern "C" char DAT_00411bb8[];
class FlyingDashTrack_139430 {
  public:
    unsigned int vt;
    unsigned int pad[2];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    void Init();
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_5() {
    FlyingDashTrack_139430* p = (FlyingDashTrack_139430*)Alloc(0x24);
    if (p) {
        p->Init();
        p->vt = ((int)DAT_00411bb8);
        p->a = 0;
        p->b = 0xbf800000;
        p->c = 0x42480000;
        p->d = 0xfffffffb;
        p->e = 0;
        p->f = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
