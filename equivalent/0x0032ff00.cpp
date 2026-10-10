// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0032ff00 @ 0x0032ff00
namespace D3D8 { struct LockedRect { int pitch; unsigned int* bits; }; void __stdcall D3DTexture_LockRect(void*, unsigned int, LockedRect*, void*, unsigned int); }
struct Texture { char pad[0x10]; void* texture; };
struct Object { char pad0[0x84]; Texture* texture; char pad1[0x50]; int count; void FUN_0032ff00(); };
void Object::FUN_0032ff00() {
    D3D8::LockedRect rect;
    D3D8::D3DTexture_LockRect(texture->texture, 0, &rect, 0, 0);
    for (int i = 0; i < 256; ++i) rect.bits[i] = i < count ? 0 : 0xffffffff;
}