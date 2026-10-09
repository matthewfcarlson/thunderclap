typedef unsigned int u32;
extern void __cdecl D3DDevice_Release();
extern void __stdcall D3DResource_Release(u32);
struct Display { u32 vptr; char pad[0x0c]; u32 device; char pad2[0x484]; u32 resource; void Finish(); };
void __fastcall FUN_0031acf0(Display* self) {
    u32 d = self->device;
    self->vptr = 0x43242c;
    if (d) D3DDevice_Release();
    u32 r = self->resource;
    if (r) D3DResource_Release(r);
    self->vptr = 0x4323e4;
    self->Finish();
}