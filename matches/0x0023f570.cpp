#include "gen/fight.h"

class Base_23f570 {
  public:
    void init();
};
class Sub_23f570 {
  public:
    void init2();
};
struct Obj_23f570 {
    int vf;
    int a;
    int b;
    int c;
};
extern int breakpoint_vftable;
extern "C" void* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<fight::BreakPointTrack>::vfunc_5() {
    Obj_23f570* p = (Obj_23f570*)alloc(0x14);
    if (p) {
        ((Base_23f570*)p)->init();
        p->vf = (int)&breakpoint_vftable;
        p->c = 0;
        ((Sub_23f570*)((char*)p + 0x10))->init2();
        p->b = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
