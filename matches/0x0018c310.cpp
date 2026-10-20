#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* __cdecl alloc(hulk_uintptr);
extern int vtable_18c310;
class Prop_18c310 {
  public:
    hulk_intptr vptr;
    int pad;
    int x;
    int a;
    int b;
    int c;
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_5() {
    Prop_18c310* p = (Prop_18c310*)alloc(0x18);
    if (p) {
        p->Init();
        p->vptr = (hulk_intptr)&vtable_18c310;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->x = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
