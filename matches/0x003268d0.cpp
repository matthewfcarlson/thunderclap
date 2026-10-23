#include "gen/pure3d.h"

typedef unsigned int u32_3268d0;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
namespace D3D8 {
void* __stdcall D3DPalette_Lock2(u32_3268d0, int);
}

int pure3d::d3dTexture::vfunc_12(int __p0) { u32_3268d0 * out = (u32_3268d0 *)__p0;

    if ((*(u32_3268d0 *)&this->f_68)) {
        void* p = D3D8::D3DPalette_Lock2((*(u32_3268d0 *)&this->f_68), 0);
        memcpy(out, p, 0x400);
    }
    return (int)(256);
}
