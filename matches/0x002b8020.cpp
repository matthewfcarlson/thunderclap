#include "compat/ptr.h"
#include "gen/pure3d.h"

struct Helper_2b8020 {
    hulk_intptr f(pure3d::PolySkin*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::PolySkin::vfunc_4() {
    Helper_2b8020* p = (Helper_2b8020*)thunk_FUN_0008d690(0x78);
    if (p)
        return (void*)(p->f(this));
    return (void*)(0);
}
