#include "gen/fight.h"

extern "C" char DAT_0040dc74[];
typedef unsigned int u32_114bf0;
struct ButtonTrack_114bf0 {
    u32_114bf0 vft;
    u32_114bf0 q0;
    u32_114bf0 q1;
    u32_114bf0 a;
    u32_114bf0 b;
    u32_114bf0 c;
    u32_114bf0 d;
    u32_114bf0 e;
    u32_114bf0 f;
    void Init();
};
extern void* operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::ButtonTrack>::vfunc_5() {
    ButtonTrack_114bf0* p = (ButtonTrack_114bf0*)operator_new(0x24);
    if (p != 0) {
        p->Init();
        p->a = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->vft = ((int)DAT_0040dc74);
        p->b = 0xbf800000;
        return (void*)(p);
    }
    return (void*)(0);
}
