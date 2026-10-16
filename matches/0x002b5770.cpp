#include "gen/pure3d.h"

typedef unsigned int u32_2b5770;
struct Helper_2b5770 {
    u32_2b5770 run(pure3d::ShadowSkinImpl*);
};
extern Helper_2b5770* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::ShadowSkinImpl::vfunc_4() {
    Helper_2b5770* p = thunk_FUN_0008d690(0x80);
    if (p)
        return (void*)(p->run(this));
    return (void*)(0);
}
