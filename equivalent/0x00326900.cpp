// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 10/10)
// pure3d::d3dTexture::vfunc_13 @ 0x00326900
namespace pure3d {
struct ImageInfo {
    int width;
    int height;
    int bitsPerPixel;
    int depth;
};
}
struct D3DTextureHandle;
struct D3DVolumeTextureHandle;
struct LockedRect {
    int pitch;
    void* bits;
};
struct LockedBox {
    int rowPitch;
    int slicePitch;
    void* bits;
};
struct SurfaceDesc {
    char data[0x1c];
};
struct VolumeDesc {
    char data[0x24];
};
namespace D3D8 {
void __stdcall Get2DSurfaceDesc(D3DTextureHandle* tex, unsigned int level, SurfaceDesc* desc);
void __stdcall D3DTexture_LockRect(D3DTextureHandle* tex, unsigned int level, LockedRect* locked, const void* rect, unsigned int flags);
void __stdcall D3DVolumeTexture_LockBox(D3DVolumeTextureHandle* tex, unsigned int level, LockedBox* locked, const void* box, unsigned int flags);
}
void __stdcall thunk_FUN_0038acb0(D3DVolumeTextureHandle* tex, unsigned int level, VolumeDesc* desc);
void FUN_0031c230(int arg);
void FUN_0031c570(SurfaceDesc* desc, LockedRect* locked, pure3d::ImageInfo* info, int flag);
void FUN_0031c600(VolumeDesc* desc, LockedBox* locked, pure3d::ImageInfo* info, int flag);
void* FUN_0008d690(int size);

namespace pure3d {
class pddiObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class d3dTexture {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual ImageInfo* vfunc_13(unsigned int level, int unused);

    char pad_04[0xc];
    int locked;
    D3DTextureHandle* texture2D;
    D3DVolumeTextureHandle* texture3D;
    LockedRect lockedRect;
    LockedBox lockedBox;
    SurfaceDesc surfaceDesc;
    VolumeDesc volumeDesc;
    ImageInfo info;
    char pad_80[0xb8 - 0x80];
    int rowStride;
    char pad_bc[4];
    char* dataEnd;
    char pad_c4[0xec - 0xc4];
    char flag_ec;
    char flag_ed;
    char pad_ee[0xf4 - 0xee];
    void* buffer;
};
}

pure3d::ImageInfo* pure3d::d3dTexture::vfunc_13(unsigned int level, int unused) {
    if (locked == 0) {
        if (texture2D != 0) {
            D3D8::Get2DSurfaceDesc(texture2D, level, &surfaceDesc);
            FUN_0031c230(0);
            D3D8::D3DTexture_LockRect(texture2D, level, &lockedRect, 0, 0);
            FUN_0031c230(0);
            FUN_0031c570(&surfaceDesc, &lockedRect, &info, 1);
        } else if (texture3D != 0) {
            thunk_FUN_0038acb0(texture3D, level, &volumeDesc);
            FUN_0031c230(0);
            D3D8::D3DVolumeTexture_LockBox(texture3D, level, &lockedBox, 0, 0);
            FUN_0031c230(0);
            FUN_0031c600(&volumeDesc, &lockedBox, &info, 1);
        }
        if (flag_ec == 0 && flag_ed == 0) {
            buffer = FUN_0008d690((info.bitsPerPixel >> 3) * info.depth * info.height * info.width + 0x10);
            int bytesPerPixel = info.bitsPerPixel >> 3;
            dataEnd = (char*)(((unsigned int)buffer + 0xf) & 0xfffffff0) + (info.height - 1) * info.width * bytesPerPixel;
            rowStride = -(info.width * bytesPerPixel);
        }
    }
    return &info;
}
