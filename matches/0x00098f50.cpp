#include "gen/global.h"
#include "gen/owners.h"
struct CDramaticCamera_nv_98f50 {
    CDramaticCamera* FUN_000a8400();
    void FUN_000a9110(int index, unsigned value);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned size);
struct Owner_98f50 {
    char padding[0xb0];
    CDramaticCamera* resource;
    void initialize(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f);
};
void Owner_98f50::initialize(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f) {
    if (!resource) {
        CDramaticCamera* memory = (CDramaticCamera*)thunk_FUN_0008d690(0x1c0);
        resource = memory ? ((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(memory))))->FUN_000a8400() : 0;
        resource->vfunc_0();
        resource->vfunc_28();
    }
    ((owners::Thing_a90f0 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a90f0(0, (int)a);
    ((owners::C_a9130 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a9130(0, (int)b);
    ((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))->FUN_000a9110(0, c);
    ((owners::Thing_a90f0 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a90f0(1, (int)d);
    ((owners::C_a9130 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a9130(1, (int)e);
    ((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))->FUN_000a9110(1, f);
}
