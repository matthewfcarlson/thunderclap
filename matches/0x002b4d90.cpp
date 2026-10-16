#include "gen/pure3d.h"

extern "C" char DAT_0042e584[];
typedef unsigned int u32_2b4d90;
void* alloc(unsigned int);
struct ShadowMeshBufferImpl_nv_2b4d90 {
    void initialize();
};

void* pure3d::ShadowMeshBufferImpl::vfunc_4() {
    pure3d::ShadowMeshBufferImpl* p = (pure3d::ShadowMeshBufferImpl*)alloc(0x48);
    if (p) {
        ((ShadowMeshBufferImpl_nv_2b4d90*)(p))->initialize();
        *(u32_2b4d90*)p = ((int)DAT_0042e584);
        *(u32_2b4d90*)((char*)p + 0x40) = 0;
        *(u32_2b4d90*)((char*)p + 0x10) = 2;
        return (void*)(p);
    }
    return (void*)(0);
}
