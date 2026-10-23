// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<HUDOverlay,void,int,math::Vector>::vfunc_2 @ 0x000cee60
#include "gen/global.h"

struct Vector_cee60 { float x, y, z; };
struct HUDOverlay_cee60 { void FUN_000cee60(int, Vector_cee60); };
struct Arguments { int index; Vector_cee60 position; };

template <> void Method2<HUDOverlay, void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cee60 * owner = (HUDOverlay_cee60 *)__p0; const Arguments * args = (const Arguments *)__p1; int unused = (int)__p2;

    (owner->*(*(void (HUDOverlay_cee60::**)(int, Vector_cee60))&this->f_1c))(args->index, args->position);
}
