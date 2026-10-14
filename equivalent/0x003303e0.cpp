// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_003303e0 @ 0x003303e0
namespace D3D8 {
void* __stdcall D3DDevice_GetBackBuffer2(unsigned int index);
void __stdcall D3DSurface_GetDesc(void* surface, void* description);
unsigned int __stdcall D3DResource_Release(void* resource);
void* __stdcall D3DDevice_CreateTexture2(unsigned int width, unsigned int height, unsigned int depth, unsigned int levels, unsigned int usage, unsigned int format, unsigned int pool);
}
void* __cdecl FUN_0008d690(unsigned int size);
struct Resource_3303e0 {
    char pad[0xf8];
    Resource_3303e0* FUN_00326110(void* device, void* texture);
};
struct Owner_3303e0 {
    char pad0[0x10];
    void* device;
    char pad1[0x6c];
    Resource_3303e0* texture;
    void FUN_0032fe00();
    void FUN_003303e0();
};
void Owner_3303e0::FUN_003303e0() {
    if (texture == 0) {
        unsigned int description[7];
        void* surface = D3D8::D3DDevice_GetBackBuffer2(0);
        D3D8::D3DSurface_GetDesc(surface, description);
        D3D8::D3DResource_Release(surface);
        void* createdTexture = D3D8::D3DDevice_CreateTexture2(0x40, 1, 1, 1, 0, description[0], 3);
        Resource_3303e0* memory = (Resource_3303e0*)FUN_0008d690(0xf8);
        if (memory != 0)
            texture = memory->FUN_00326110(device, createdTexture);
        else
            texture = 0;
        FUN_0032fe00();
    }
}