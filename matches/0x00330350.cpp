// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_00330350 @ 0x00330350
struct SurfaceDesc_330350 {
    unsigned int format;
    unsigned int rest[6];
};
namespace D3D8 {
void* __stdcall D3DDevice_GetBackBuffer2(unsigned int index);
void __stdcall D3DSurface_GetDesc(void* surface, SurfaceDesc_330350* desc);
void __stdcall D3DResource_Release(void* surface);
void* __stdcall D3DDevice_CreateTexture2(unsigned int width, unsigned int height, unsigned int depth,
                                         unsigned int levels, unsigned int usage, unsigned int format,
                                         unsigned int pool);
} // namespace D3D8
void* __cdecl FUN_0008d690(unsigned int bytes);
struct d3dToon2VertexShader_330350 {
    char pad0[0x10];
    void* device;
    char pad1[0x70];
    void* texture;
    void FUN_0032ff00();
    void FUN_00330350();
};
struct d3dTexture_330350 {
    d3dTexture_330350* FUN_00326110(void* device, void* texture);
};
void d3dToon2VertexShader_330350::FUN_00330350() {
    if (texture == 0) {
        SurfaceDesc_330350 desc;
        void* backBuffer = D3D8::D3DDevice_GetBackBuffer2(0);
        D3D8::D3DSurface_GetDesc(backBuffer, &desc);
        D3D8::D3DResource_Release(backBuffer);
        void* newTexture = D3D8::D3DDevice_CreateTexture2(256, 1, 1, 1, 0, desc.format, 3);
        d3dTexture_330350* object = (d3dTexture_330350*)FUN_0008d690(0xf8);
        texture = object != 0 ? object->FUN_00326110(device, newTexture) : 0;
        FUN_0032ff00();
    }
}