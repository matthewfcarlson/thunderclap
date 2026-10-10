typedef unsigned long DWORD;
struct SurfaceDesc {
    DWORD Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
struct Rect {
    long left, top, right, bottom;
};
struct Texture;
struct Surface;
namespace D3D8 {
void __stdcall D3DResource_AddRef(Texture*);
void __stdcall D3DResource_Release(void*);
Surface* __stdcall D3DTexture_GetSurfaceLevel2(Texture*, DWORD);
void __stdcall D3DSurface_GetDesc(Surface*, SurfaceDesc*);
Surface* __stdcall D3DDevice_GetRenderTarget2();
void __stdcall D3DDevice_CopyRects(Surface*, Rect*, DWORD, Surface*, void*);
} // namespace D3D8
void FUN_0031c230(long hr);
void __stdcall FUN_00320aa0(Texture* tex) {
    if (!tex)
        return;
    D3D8::D3DResource_AddRef(tex);
    Surface* src = D3D8::D3DTexture_GetSurfaceLevel2(tex, 0);
    FUN_0031c230(src ? 0 : 0x8007000e);
    SurfaceDesc desc;
    D3D8::D3DSurface_GetDesc(src, &desc);
    FUN_0031c230(0);
    Rect r;
    r.left = 0;
    r.top = 0;
    r.right = desc.Width;
    r.bottom = desc.Height;
    Surface* rt = D3D8::D3DDevice_GetRenderTarget2();
    FUN_0031c230(0);
    D3D8::D3DDevice_CopyRects(rt, &r, 1, src, 0);
    FUN_0031c230(0);
    D3D8::D3DResource_Release(rt);
    D3D8::D3DResource_Release(src);
    D3D8::D3DResource_Release(tex);
}
