#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Obj_6f190 {
  public:
    void* Initialize();
};

template <> void* fight::TrackFactoryTemplate<CCollisionTrack>::vfunc_5() {
    Obj_6f190* p = (Obj_6f190*)FUN_0008d690(0x120);
    if (p)
        return (void*)(p->Initialize());
    return (void*)(0);
}
