#include "gen/fight.h"

extern "C" char DAT_004144b0[];
class HitPushbackTrack_15a3b0 {
  public:
    int vptr;
    int x04;
    int x08;
    int x0c;
    float x10;
    float x14;
    float x18;
    unsigned char x1c;
    char x1d[3];
    int x20;
    int x24;
    int x28;
    int x2c;
    int x30;
    void init();
};
extern HitPushbackTrack_15a3b0* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_5() {
    HitPushbackTrack_15a3b0* p = alloc(0x34);
    if (p) {
        p->init();
        p->x10 = -1.0f;
        p->x18 = -1.0f;
        p->x0c = 0;
        p->x1c = 0;
        p->x20 = 0;
        p->x24 = 0;
        p->x2c = 0;
        p->x30 = 0;
        p->vptr = ((int)DAT_004144b0);
        p->x14 = 1.0f;
        p->x28 = -5;
        return (void*)(p);
    }
    return (void*)(0);
}
