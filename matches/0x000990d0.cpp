#include "gen/global.h"
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
struct CNISCamera_nv_990d0 {
    CNISCamera* FUN_000ac3c0();
    void FUN_000a90f0(int index, unsigned int value);
    void FUN_000a9130(int index, unsigned int value);
    void FUN_000a9110(int index, unsigned int value);
};
struct Owner_990d0 {
    char padding[0xc0];
    CNISCamera* resource;
    void FUN_000990d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                      unsigned int f);
};
void Owner_990d0::FUN_000990d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                         unsigned int f) {
    if (!resource) {
        CNISCamera* allocated = static_cast<CNISCamera*>(thunk_FUN_0008d690(0x178));
        resource = allocated ? ((CNISCamera_nv_990d0*)(((CNISCamera*)(allocated))))->FUN_000ac3c0() : 0;
        resource->vfunc_0();
        resource->vfunc_28();
    }
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a90f0(0, a);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a9130(0, b);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a9110(0, c);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a90f0(1, d);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a9130(1, e);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a9110(1, f);
}
