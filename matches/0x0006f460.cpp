#include "compat/ptr.h"
#include "gen/fight.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
class Dummy_6f460 {
  public:
    hulk_intptr FUN_0005aa00();
};

template <> void* fight::TrackFactoryTemplate<CGrappleAttachTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return (void*)(((Dummy_6f460*)p)->FUN_0005aa00());
    return (void*)(0);
}
