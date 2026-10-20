#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int size_t;
void* Alloc(hulk_uintptr);
class Obj_1a1240 {
  public:
    void* Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_5() {
    Obj_1a1240* p = (Obj_1a1240*)Alloc(0xb0);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}
