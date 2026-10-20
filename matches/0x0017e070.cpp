#include "compat/ptr.h"
#include "gen/fight.h"

struct ChargeTrack_17e070 {
    hulk_intptr vt;
    int pad4;
    int enabled;
    float padc;
    float value10;
    int pad14;
    char flag18;
    char pad19[3];
    float value1c;
    void Init();
};
extern int chargeVtable;
void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ChargeTrack>::vfunc_5() {
    ChargeTrack_17e070* p = (ChargeTrack_17e070*)operator new(0x20);
    if (p) {
        p->Init();
        p->vt = (hulk_intptr)&chargeVtable;
        p->padc = 0.0f;
        p->value10 = -1.0f;
        p->pad14 = 0;
        p->flag18 = 0;
        p->value1c = 1.0f;
        p->enabled = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
