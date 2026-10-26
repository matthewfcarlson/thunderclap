#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int u32_2c2670;
struct Result_2c2670 {
    char pad[8];
    u32_2c2670 a;
    u32_2c2670 b;
};
struct This_FUN_002c2370 {
    Result_2c2670* FUN_002c2370(hulk_uintptr);
};

void pure3d::TextureLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { u32_2c2670 * p2 = (u32_2c2670 *)__p0; u32_2c2670 * p3 = (u32_2c2670 *)__p1; hulk_uintptr p4 = (hulk_uintptr)__p2; u32_2c2670 unused = (u32_2c2670)__p3;

    Result_2c2670* r = ((This_FUN_002c2370*)this)->FUN_002c2370(p4);
    if (r) {
        *(hulk_uintptr*)p2 = (hulk_uintptr)r;
        *p3 = r->a;
        p3[1] = r->b;
    }
}
