#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00414330[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class TrackBase_159e20 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_5() {
    char* p = (char*)Alloc(0x18);
    if (p) {
        ((TrackBase_159e20*)p)->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414330);
        *(int*)(p + 0xc) = 0;
        *(int*)(p + 0x10) = (int)0xbf800000;
        *(int*)(p + 0x14) = 0;
        *(int*)(p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
