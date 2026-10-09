typedef unsigned int U;
struct Obj { char pad[0x498]; U texture; };
extern U __stdcall D3DDevice_GetRenderTarget2();
extern U __stdcall D3DTexture_GetSurfaceLevel2(U, U);
extern U __stdcall D3DDevice_CopyRects(U,U,U,U,U);
extern U __stdcall D3DResource_Release(U);
void __fastcall target(Obj* self, void*) {
    if (self->texture) {
        U a = D3DDevice_GetRenderTarget2();
        U b = D3DTexture_GetSurfaceLevel2(self->texture, 0);
        D3DDevice_CopyRects(a, 0, 0, b, 0);
        D3DResource_Release(a);
        D3DResource_Release(b);
    }
}