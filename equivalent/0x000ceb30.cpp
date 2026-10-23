// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_2 @ 0x000ceb30
#include "gen/global.h"

struct Vector_ceb30 { float x,y,z; };
struct HUDOverlay_ceb30 {};

template <> void Method4<HUDOverlay, void, const char *, float, float,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_ceb30 * object = (HUDOverlay_ceb30 *)__p0; const unsigned int * args = (const unsigned int *)__p1; void * unused = (void *)__p2;

    union Bits { unsigned int u; float f; } a, b, x, y, z;
    a.u=args[1]; b.u=args[2];
    x.u=args[3]; y.u=args[4]; z.u=args[5];
    Vector_ceb30 v; v.x=x.f; v.y=y.f; v.z=z.f;
    (object->*(*(void (HUDOverlay_ceb30::**)(const char *, float, float, Vector_ceb30))&this->f_1c))((const char*)args[0], a.f, b.f, v);
}
