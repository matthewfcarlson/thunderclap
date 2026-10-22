// STATUS: equivalent (tools/equiv.py level 3: 20053 inputs, branch coverage 16/16)
// FUN_00320330 @ 0x00320330
#include "compat/ptr.h"
struct SurfaceDesc_320330 {
    unsigned int Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
namespace D3D8 {
int __stdcall D3DDevice_GetRenderTarget2();
void __stdcall D3DSurface_GetDesc(int, SurfaceDesc_320330*);
void __stdcall D3DResource_Release(hulk_intptr);
int __stdcall D3DDevice_CreateTexture2(int, int, int, int, int, unsigned int, int);
}
class Viewport_320330 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int GetHeight();
    virtual int GetWidth();
};
struct Parent_320330 {
    char pad[0x154];
    Viewport_320330* viewport;
};
class d3dExtFramebufferEffects_320330 {
  public:
    unsigned char FUN_003202b0(const char* src, int* out);
    void Setup();
    char pad0[4];
    Parent_320330* parent;
    char pad8[0x8c - 8];
    int ps0, ps1, ps2, ps3;
    int pad9c;
    int ps4;
    int pada4;
    int tex2;
    int tex0;
    int tex1;
    unsigned char busy;
    char padb5[0xd0 - 0xb5];
    float scaleX;
    float scaleY;
};
void d3dExtFramebufferEffects_320330::Setup() {
    if (tex0 != 0)
        return;
    if (busy)
        return;
    busy = 1;
    unsigned char ok = FUN_003202b0("    ps.1.1 \n    tex t0 \n    mul r0, t0, c0 \n", &ps0) & 1;
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n", &ps1);
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    tex t2 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n    mad r0, t2, c2, r0 \n", &ps2);
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    tex t2 \n    tex t3 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n    mad r0, t2, c2, r0 \n    mad r0, t3, c3, r0 \n", &ps3);
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    mul_x2 r0, t0, c0 \n    mad r0, t1, c1, r0 \n", &ps4);
    unsigned char last = ok;
    if (!(ok & last))
        return;
    int rt = D3D8::D3DDevice_GetRenderTarget2();
    SurfaceDesc_320330 desc;
    D3D8::D3DSurface_GetDesc(rt, &desc);
    D3D8::D3DResource_Release(rt);
    scaleX = (float)parent->viewport->GetWidth() / (float)desc.Width;
    scaleY = (float)parent->viewport->GetHeight() / (float)desc.Height;
    Viewport_320330* vp = parent->viewport;
    int h = vp->GetHeight() / 4;
    int w = vp->GetWidth() / 4;
    tex0 = D3D8::D3DDevice_CreateTexture2(w, h, 1, 1, 0, desc.Format, 3);
    if (!tex0)
        return;
    vp = parent->viewport;
    h = vp->GetHeight() / 4;
    w = vp->GetWidth() / 4;
    tex1 = D3D8::D3DDevice_CreateTexture2(w, h, 1, 1, 0, desc.Format, 3);
    if (!tex1)
        return;
    vp = parent->viewport;
    h = vp->GetHeight() / 2;
    w = vp->GetWidth() / 2;
    tex2 = D3D8::D3DDevice_CreateTexture2(w, h, 1, 1, 0, desc.Format, 3);
    if (!tex2)
        return;
    busy = 0;
}
