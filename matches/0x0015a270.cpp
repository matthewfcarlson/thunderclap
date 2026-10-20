#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00414450[];
class HitDamageTrack_15a270 {
  public:
    virtual void f0();
    char pad[8];
    int x;
    float y;
    void init();
};
extern void* __cdecl operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitDamageTrack>::vfunc_5() {
    HitDamageTrack_15a270* p = (HitDamageTrack_15a270*)operator new(0x14);
    if (p) {
        p->init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414450);
        p->x = 0;
        p->y = 1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}
