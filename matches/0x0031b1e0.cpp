typedef unsigned int U_31b1e0;
struct Obj_31b1e0 {
    char pad[0x498];
    U_31b1e0 texture;
};
extern U_31b1e0 __stdcall D3DDevice_GetRenderTarget2();
extern U_31b1e0 __stdcall D3DTexture_GetSurfaceLevel2(U_31b1e0, U_31b1e0);
extern U_31b1e0 __stdcall D3DDevice_CopyRects(U_31b1e0, U_31b1e0, U_31b1e0, U_31b1e0, U_31b1e0);
extern U_31b1e0 __stdcall D3DResource_Release(U_31b1e0);
void __fastcall target(Obj_31b1e0* self, void*) {
    if (self->texture) {
        U_31b1e0 a = D3DDevice_GetRenderTarget2();
        U_31b1e0 b = D3DTexture_GetSurfaceLevel2(self->texture, 0);
        D3DDevice_CopyRects(a, 0, 0, b, 0);
        D3DResource_Release(a);
        D3DResource_Release(b);
    }
}