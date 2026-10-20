#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_1a1120;
struct Obj_1a1120 {
    hulk_uintptr Init();
};
extern void* __cdecl Alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FireBeamTrack>::vfunc_5() {
    Obj_1a1120* p = (Obj_1a1120*)Alloc(0x138);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}
