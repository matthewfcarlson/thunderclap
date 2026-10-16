#include "gen/fight.h"

class CIntangibleToActorsTrack_76c90 {
  public:
    void Init();
    int* vptr;
    char pad[4];
    int one;
    int zero;
    float minus;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int trackVtable;

template <> void* fight::TrackFactoryTemplate<CIntangibleToActorsTrack>::vfunc_5() {
    CIntangibleToActorsTrack_76c90* p = (CIntangibleToActorsTrack_76c90*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        p->vptr = &trackVtable;
        p->zero = 0;
        p->minus = -1.0f;
        p->one = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
