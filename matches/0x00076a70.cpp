#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fe8d8[];
typedef unsigned int u32_76a70;
void* operator_new(unsigned int);
struct Track_76a70 {
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CGrappleSoundTrack>::vfunc_5() {
    Track_76a70* p = (Track_76a70*)operator_new(0x54);
    if (p != 0) {
        p->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fe8d8);
        return (void*)(p);
    }
    return (void*)(0);
}
