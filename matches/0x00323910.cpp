struct SurfaceDesc {
    unsigned int Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
namespace D3D8 {
int __stdcall D3DDevice_GetRenderTarget2();
void __stdcall D3DSurface_GetDesc(int, SurfaceDesc*);
void __stdcall D3DResource_Release(int);
int __stdcall D3DDevice_CreateTexture2(int, int, int, int, int, unsigned int, int);
} // namespace D3D8
class Viewport {
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
struct Parent {
    char pad[0x154];
    Viewport* viewport;
};
class RenderEffect {
  public:
    bool FUN_00320540();
    void Setup();
    char pad0[4];
    Parent* parent;
    char pad8[0x20 - 8];
    int tex;
    char pad24[0x7c - 0x24];
    unsigned char busy;
    char pad7d[0xd0 - 0x7d];
    float scaleX;
    float scaleY;
};
void RenderEffect::Setup() {
    if (tex != 0)
        return;
    busy = 1;
    if (!FUN_00320540())
        return;
    int rt = D3D8::D3DDevice_GetRenderTarget2();
    SurfaceDesc desc;
    D3D8::D3DSurface_GetDesc(rt, &desc);
    D3D8::D3DResource_Release(rt);
    scaleX = (float)parent->viewport->GetWidth() / (float)desc.Width;
    scaleY = (float)parent->viewport->GetHeight() / (float)desc.Height;
    tex = D3D8::D3DDevice_CreateTexture2(desc.Width, desc.Height, 1, 1, 0, desc.Format, 3);
    if (tex)
        busy = 0;
}
