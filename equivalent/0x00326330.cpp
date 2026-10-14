// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 43/46, incomplete)
// FUN_00326330 @ 0x00326330
namespace D3D8 {
int __stdcall D3DDevice_CreateTexture2(unsigned long w, unsigned long h, unsigned long depth, unsigned long levels, unsigned long usage, unsigned long format, unsigned long type);
int __stdcall D3DDevice_CreatePalette2(unsigned long size);
void __stdcall Get2DSurfaceDesc(int tex, unsigned long level, void* desc);
}
struct SurfaceDesc_326330 {
    unsigned long format;
    unsigned long type;
    unsigned long usage;
    unsigned long size;
    unsigned long multiSample;
    unsigned long width;
    unsigned long height;
};
class GfxDevice {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual int GetMaxTextureSize();
};
void __cdecl FUN_0031c230(unsigned long code);
void __cdecl FUN_0031c570(SurfaceDesc_326330* desc, int a, void* out, int b);
void __cdecl FUN_0031e1f0(int tex, int bytes);
// equiv-conv: FUN_00325fb0 edx
int __cdecl FUN_00325fb0(int field);
// equiv-conv: FUN_00325fd0 ecx edx eax stack
int __cdecl FUN_00325fd0(int fmt, int a3, int a2, GfxDevice* dev);

class TextureResource {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void SetDirty(int value);
    int field4;
    int errorCode;
    GfxDevice* device;
    int field10;
    int texture;
    char pad18[0x68 - 0x18];
    int palette;
    char pad6c[0x70 - 0x6c];
    char layoutInfo[0x8];
    unsigned int field78;
    char pad7c[0x80 - 0x7c];
    int field80;
    char pad84[0xb4 - 0x84];
    int field0b4;
    char padb8[0xc8 - 0xb8];
    int format;
    int arg6;
    int field0d0;
    unsigned int width;
    unsigned int height;
    unsigned int field0dc;
    int field0e0;
    int levels;
    int totalBytes;
    char isCompressed;
    char isPalettized;
    char isLinear;
    char pad0ef;
    int field0f0;
    bool Create(int width, int height, int a2, int a3, int mips, int fmt, int a6);
};
bool TextureResource::Create(int w, int h, int a2, int a3, int mips, int fmt, int a6) {
    int usage = 0;
    if (fmt != 0) {
        if (fmt == 12) {
            usage = 1;
            fmt = 11;
            isLinear = 1;
        }
    } else {
        if ((w & (w - 1)) != 0 || (h & (h - 1)) != 0) {
            errorCode = 0xc8;
            return false;
        }
    }
    if (w > device->GetMaxTextureSize() || h > device->GetMaxTextureSize()) {
        errorCode = 0xc9;
        return false;
    }
    if (fmt == 1)
        fmt = 0;
    int mapped = FUN_00325fd0(fmt, a3, a2, device);
    if (mapped == -1) {
        errorCode = 0xca;
        return false;
    }
    if (isLinear) {
        switch (mapped) {
        case 3: case 5: case 6: case 7: case 17: case 18: case 28: case 30:
            break;
        default:
            errorCode = 0xca;
            return false;
        }
    }
    arg6 = a6;
    format = fmt;
    field0d0 = 0;
    levels = mips;
    width = w;
    height = h;
    isCompressed = (fmt == 4 || fmt == 5 || fmt == 6 || fmt == 7 || fmt == 8);
    isPalettized = (fmt == 11);
    texture = D3D8::D3DDevice_CreateTexture2(w, h, 1, mips + 1, usage, mapped, 3);
    FUN_0031c230(texture != 0 ? 0 : 0x8007000e);
    if (mapped == 11)
        palette = D3D8::D3DDevice_CreatePalette2(0);
    SurfaceDesc_326330 desc;
    D3D8::Get2DSurfaceDesc(texture, 0, &desc);
    FUN_0031c230(0);
    SetDirty(field0f0);
    FUN_0031c570(&desc, 0, layoutInfo, 1);
    field0d0 = field80;
    unsigned int bitsPerPixel = field78;
    field0dc = bitsPerPixel;
    field0e0 = FUN_00325fb0(field0b4);
    totalBytes = 0;
    float bytesPer;
    if (isCompressed)
        bytesPer = 0.5f;
    else
        bytesPer = (float)((int)bitsPerPixel / 8);
    unsigned int mw = width;
    unsigned int mh = height;
    for (int i = 0; i < levels + 1; i++) {
        totalBytes += (int)((float)(mw * mh) * bytesPer);
        mw >>= 1;
        mh >>= 1;
    }
    FUN_0031e1f0(texture, totalBytes);
    return true;
}
