#include "gen/pure3d.h"

struct Texture_321d40 {
    char pad[0x14];
    void* surface;
};
extern "C" void* __stdcall D3DDevice_GetDepthStencilSurface2();
extern "C" void* __stdcall D3DDevice_GetBackBuffer2(int);
extern "C" void* __stdcall D3DTexture_GetSurfaceLevel2(void*, int);
extern "C" void __stdcall D3DDevice_SetRenderTarget(void*, void*);
extern "C" void __stdcall D3DResource_Release(void*);
namespace pure3d {
} // namespace pure3d
int pure3d::d3dContext::vfunc_92(void* __p0) { Texture_321d40 * p = (Texture_321d40 *)__p0;

    void* d = D3DDevice_GetDepthStencilSurface2();
    void* s;
    if (p == 0) {
        s = D3DDevice_GetBackBuffer2(0);
        goto set;
    }
    s = D3DTexture_GetSurfaceLevel2(p->surface, 0);
    if (s) {
    set:
        D3DDevice_SetRenderTarget(s, d);
    }
    D3DResource_Release(s);
    D3DResource_Release(d);
    return 0;
}
