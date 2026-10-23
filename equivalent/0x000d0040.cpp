// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<HUDOverlay,void,int,int,math::Vector>::vfunc_2 @ 0x000d0040
#include "gen/global.h"

namespace math { struct Vector_d0040 { float x,y,z; }; }
struct HUDOverlay_d0040 { void invoked(int, int, math::Vector_d0040); };

template <> void Closure3<HUDOverlay, void, int, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const int * args = (const int *)__p1; void * unused2 = (void *)__p2;

    math::Vector_d0040 v;
    const math::Vector_d0040* source = (const math::Vector_d0040*)(args+2);
    v = *source;
    ((*(HUDOverlay_d0040 * *)&this->f_20)->*(*(void (HUDOverlay_d0040::**)(int, int, math::Vector_d0040))&this->f_1c))(args[0],args[1],v);
}
