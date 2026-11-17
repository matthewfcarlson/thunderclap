// The XDK shim's textures, surfaces, palettes and render targets (src/platform/sdl/xdk/graphics_d3d8.cpp,
// graphics_xgraphics.cpp; x64t18, D89): create, describe, lock, copy in, reference counts.
//
//   R=src/platform/sdl; xcrun clang++ -arch arm64 -std=c++17 -g -fsanitize=address,undefined -I $R -I $R/xdk \
//     tests/native_host/d3d_texture_test.cpp $R/xdk/graphics_d3d8.cpp $R/xdk/graphics_xgraphics.cpp -o build/d3dtex && build/d3dtex
//
// (the shim's trace hook and the three host functions it calls come from libc here)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xdk/imports.h"
extern "C" {
void hulk_xdk_trace_from(const char*, hulk_u32* c, const void*) { ++*c; }
void* hulk_host_calloc(hulk_u32 n, hulk_u32 s) { return calloc(n, s); }
void hulk_host_free(void* p) { free(p); }
void* hulk_host_memcpy(void* d, const void* s, hulk_u32 n) { return memcpy(d, s, n); }
}
struct LR { int pitch; unsigned char* bits; };
int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #c); fails++; } } while (0)
int main() {
    hulk_uptr t = hulk_xdk_D3DDevice_CreateTexture2(64, 32, 1, 0, 0, 6, 3);   // A8R8G8B8, full chain
    CHECK(t);
    hulk_u32 d[7];
    hulk_xdk_D3DTexture_GetLevelDesc(t, 0, (hulk_uptr)d);
    CHECK(d[0] == 6 && d[1] == 1 && d[5] == 64 && d[6] == 32 && d[3] == 64 * 32 * 4);
    hulk_xdk_D3DTexture_GetLevelDesc(t, 6, (hulk_uptr)d);
    CHECK(d[5] == 1 && d[6] == 1);
    LR lr = { 0, 0 };
    hulk_xdk_D3DTexture_LockRect(t, 1, (hulk_uptr)&lr, 0, 0);
    CHECK(lr.pitch == 32 * 4 && lr.bits);
    unsigned char src[32 * 16 * 4];
    for (unsigned i = 0; i < sizeof src; i++) src[i] = (unsigned char)i;
    hulk_xdk_XGSwizzleRect((hulk_uptr)src, 0, 0, (hulk_uptr)lr.bits, 32, 16, 0, 4);
    CHECK(memcmp(src, lr.bits, sizeof src) == 0);
    hulk_uptr s = hulk_xdk_D3DTexture_GetSurfaceLevel2(t, 1);
    hulk_xdk_D3DSurface_GetDesc(s, (hulk_uptr)d);
    CHECK(d[5] == 32 && d[6] == 16);
    LR sl = { 0, 0 };
    hulk_xdk_D3DSurface_LockRect(s, (hulk_uptr)&sl, 0, 0);
    CHECK(sl.bits == lr.bits && sl.pitch == lr.pitch);
    CHECK(hulk_xdk_D3DResource_Release(t) == 1);         // the surface holds the texture
    CHECK(hulk_xdk_D3DResource_Release(s) == 0);         // frees both
    hulk_uptr x = hulk_xdk_D3DDevice_CreateTexture2(16, 8, 1, 2, 0, 0xc, 3);  // DXT1
    hulk_xdk_D3DTexture_GetLevelDesc(x, 0, (hulk_uptr)d);
    CHECK(d[3] == 4 * 2 * 8);
    hulk_xdk_D3DTexture_LockRect(x, 0, (hulk_uptr)&lr, 0, 0);
    CHECK(lr.pitch == 4 * 8);
    hulk_xdk_D3DResource_Release(x);
    hulk_uptr v = hulk_xdk_D3DDevice_CreateTexture2(8, 8, 4, 1, 0, 6, 4);     // volume
    hulk_xdk_D3D_GetSurfaceDesc_helper(v, 0, (hulk_uptr)d);
    CHECK(d[1] == 2 && d[4] == 8 && d[5] == 8 && d[6] == 4 && d[3] == 8 * 8 * 4 * 4);
    hulk_xdk_D3DResource_Release(v);
    hulk_uptr p = hulk_xdk_D3DDevice_CreatePalette2(0);
    CHECK(hulk_xdk_D3DPalette_Lock2(p, 0));
    hulk_xdk_D3DResource_Release(p);
    hulk_u32 pp[17] = { 640, 480, 6, 1, 0, 1, 0, 0, 1, 0x2a };
    hulk_uptr dev = 0;
    hulk_xdk_Direct3D_CreateDevice(0, 1, 0, 0x40, (hulk_uptr)pp, (hulk_uptr)&dev);
    CHECK(dev);
    hulk_uptr rt = hulk_xdk_D3DDevice_GetRenderTarget2();
    hulk_xdk_D3DSurface_GetDesc(rt, (hulk_uptr)d);
    CHECK(d[5] == 640 && d[6] == 480 && d[0] == 6);
    hulk_xdk_D3DResource_Release(rt);
    hulk_uptr ds = hulk_xdk_D3DDevice_GetDepthStencilSurface2();
    hulk_xdk_D3DSurface_GetDesc(ds, (hulk_uptr)d);
    CHECK(d[0] == 0x2a && d[5] == 640);
    hulk_xdk_D3DResource_Release(ds);
    printf("%s (%d failures)\n", fails ? "FAIL" : "ok", fails);
    return fails != 0;
}
