// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00325f30..0x00326d60 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dTexture
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff6ae8d9 {
#define TREE_TU_END }
namespace fn_ff6ae8d9 {} using namespace fn_ff6ae8d9;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff6ae8d9 {
class Device_325fd0 {
  public:
};
extern int g_formatTable[];
class pddiObject_3260f0 {
  public:
    pddiObject_3260f0();
    virtual void g();
};
class pddiTexture : public pddiObject_3260f0 {
  public:
    pddiTexture();
    virtual void f();
};
class d3dTexture_326240 {
    char pad[0xd8];

  public:
    int vfunc_6();
};
} // namespace fn_ff6ae8d9
namespace pure3d {
class pddiObject_326250 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
}
namespace pure3d {
class pddiTexture_326250 : public pddiObject_326250 {
  public:
    virtual void vfunc_15();
    virtual void vfunc_20();
};
}
namespace fn_ff6ae8d9 {
class pddiTexture_326260 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
};
extern "C" char DAT_00433354[];
extern "C" char DAT_004333ac[];
typedef unsigned int U_326290;
extern void __stdcall Release(U_326290);
extern "C" void __cdecl FUN_0031e210(U_326290);
struct d3dTexture_326290 {
    hulk_uintptr vt;
    char pad[12];
    U_326290 a;
    U_326290 b;
    U_326290 c;
    char gap[0x68 - 0x1c];
    U_326290 d;
    void BaseDestroy();
};
struct D3DResource {};
void __stdcall D3DResource_AddRef(D3DResource*);
void __stdcall D3DResource_Release(D3DResource*);
struct Owner_326300 {
    char pad[0x10];
    D3DResource* resource;
    void Set(D3DResource*);
};
extern "C" void* __stdcall D3DPalette_Lock2(void*, int);
} // namespace fn_ff6ae8d9
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_ff6ae8d9 {
typedef unsigned int u32_3268d0;
namespace D3D8 {
void* __stdcall D3DPalette_Lock2(u32_3268d0, int);
}


// 0x00325f30 FUN_00325f30 (43 B): equivalent/0x00325f30.cpp
// sym: _FUN_00325f30 @fccd57a6909a @w1a7e1db73e1d
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 6/6)
// FUN_00325f30 @ 0x00325f30
// equiv-conv: FUN_00325f30 eax
extern "C" int FUN_00325f30(int value)
{
    switch (value) {
    case 2: case 3: case 4: case 5:
    case 0x10: case 0x11: case 0x1d: case 0x28:
        return 0x10;
    case 6: case 7: case 0x12: case 0x1e:
        return 0x20;
    case 0xb:
        return 8;
    default:
        return 0;
    }
}


// 0x00325fb0 FUN_00325fb0 (25 B): matches/0x00325fb0.cpp
// sym: ?count@fn_ff6ae8d9@@YIHII@Z
int __fastcall count(unsigned int ignored, unsigned int value) {
    int n = 0;
    for (int i = 0; i < 32; ++i) {
        if (value & (1 << i))
            ++n;
    }
    return n;
}


// 0x00325fd0 FUN_00325fd0 (228 B): equivalent/0x00325fd0.cpp
// sym: ?FUN_00325fd0@fn_ff6ae8d9@@YAHHHHPAVDevice_325fd0@1@@Z @69f54cdfb770 @wd5e598858790
// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 36/36)
// FUN_00325fd0 @ 0x00325fd0
// equiv-conv: FUN_00325fd0 ecx edx eax stack
      // 0x4d3e14
// equiv-map: ?g_formatTable@@3PAHA = 0x004d3e14
int FUN_00325fd0(int fmt, int depth, int bits, Device_325fd0* dev) {
    int idx = -1;
    switch (fmt) {
    case 0:
        if (depth == 0)
            idx = bits == 16 ? 0 : 3;
        else if (depth == 1)
            idx = bits != 16 ? 5 : 1;
        else
            idx = bits != 16 ? 4 : 2;
        break;
    case 1: idx = 6; break;
    case 2: idx = 7; break;
    case 3: idx = 8; break;
    case 4: return 12;
    case 5: case 6: return 14;
    case 7: case 8: return 15;
    case 9: case 10: break;
    case 11:
        if (depth == 0)
            idx = bits > 16 ? 12 : 9;
        else if (depth == 1)
            idx = bits > 16 ? 14 : 10;
        else
            idx = bits > 16 ? 13 : 11;
        break;
    }
    if (!((owners::Holder_320d00 *)dev)->FUN_00320d00(g_formatTable[idx]))
        return -1;
    return g_formatTable[idx];
}


// 0x003260f0 FUN_003260f0 (18 B): matches/0x003260f0.cpp
// sym: ??0pddiTexture@fn_ff6ae8d9@@QAE@XZ
pddiTexture::pddiTexture() : pddiObject_3260f0() {}

} // namespace fn_ff6ae8d9

// 0x00326110 FUN_00326110 (270 B): equivalent/0x00326110.cpp [wrapped: conflict: pure3d::d3dTexture; pure3d::pddiObject]
// sym: ??0d3dTexture@pure3d@fn_00326110@@QAE@PAUCtx@2@H@Z @b49306bea547 @w4b501323f38e
namespace fn_00326110 {
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 2/2)
// FUN_00326110 @ 0x00326110
namespace D3D8 {
void __stdcall D3DResource_AddRef(int);
}
struct Ctx;
namespace pure3d {
class pddiObject {
  public:
    pddiObject() throw();
    virtual void p0();
    int field4;
    int field8;
};
class d3dTexture : public pddiObject {
  public:
    d3dTexture(Ctx* ctx, hulk_intptr resource) throw();
    virtual void v1();
    Ctx* ctx;
    int resource;
    int f14, f18;
    char pad1c[0x68 - 0x1c];
    int f68;
    char pad6c[4];
    int f70, f74, f78, f7c, f80;
    unsigned char f84;
    char pad85[0x88 - 0x85];
    int f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0;
    int fc4;
    int fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8;
    unsigned char fec, fed, fee, fef;
    int ff0, ff4;
};
d3dTexture::d3dTexture(Ctx* c, hulk_intptr res) throw() {
    f70 = 0;
    f74 = 0;
    f78 = 0;
    f7c = 0;
    f80 = 0;
    f84 = 0;
    fb8 = 0;
    fbc = 0;
    fc0 = 0;
    f94 = 0;
    f90 = 0;
    f8c = 0;
    f88 = 0;
    fa4 = 0;
    fa0 = 0;
    f9c = 0;
    f98 = 0;
    fb4 = 0;
    fb0 = 0;
    fac = 0;
    fa8 = 0;
    ctx = c;
    f14 = 0;
    f18 = 0;
    resource = res;
    if (res)
        D3D8::D3DResource_AddRef(res);
    fcc = 1;
    fef = 1;
    f68 = 0;
    ff4 = 0;
    fc8 = 0;
    fd0 = 0;
    fd4 = 0;
    fd8 = 0;
    fdc = 0;
    fe0 = 0;
    fe4 = 0;
    fec = 0;
    fed = 0;
    fee = 0;
    fe8 = 0;
    ff0 = 0xf;
}
}
} // namespace fn_00326110


// 0x00326220 pure3d::d3dTexture::vfunc_4 (7 B): matches/0x00326220.cpp
// sym: ?vfunc_4@d3dTexture@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dTexture::vfunc_4() {
    return this->f_d0;
}


// 0x00326230 pure3d::d3dTexture::vfunc_5 (7 B): matches/0x00326230.cpp
// sym: ?vfunc_5@d3dTexture@pure3d@@UAEIXZ
unsigned int pure3d::d3dTexture::vfunc_5() {
    return *(unsigned int*)((char*)this + 0xd4);
}

namespace fn_ff6ae8d9 {

// 0x00326240 pure3d::d3dTexture::vfunc_6 (7 B): matches/0x00326240.cpp
// sym: ?vfunc_6@d3dTexture_326240@fn_ff6ae8d9@@QAEHXZ
int d3dTexture_326240::vfunc_6() {
    return *(int*)(this->pad + 0xd8);
}

} // namespace fn_ff6ae8d9

// 0x00326250 pure3d::d3dTexture::vfunc_7 (7 B): matches/0x00326250.cpp
// sym: ?vfunc_7@d3dTexture@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dTexture::vfunc_7() {
    return this->f_dc;
}


// 0x00326260 pure3d::d3dTexture::vfunc_8 (7 B): matches/0x00326260.cpp
// sym: ?vfunc_8@d3dTexture@pure3d@@UAEHXZ
int pure3d::d3dTexture::vfunc_8() {
    return *(int*)((char*)this + 0xe0);
}


// 0x00326270 pure3d::d3dTexture::vfunc_9 (7 B): matches/0x00326270.cpp
// sym: ?vfunc_9@d3dTexture@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dTexture::vfunc_9() {
    return this->f_e4;
}


// 0x00326280 pure3d::d3dTexture::vfunc_19 (7 B): matches/0x00326280.cpp
// sym: ?vfunc_19@d3dTexture@pure3d@@UAEIXZ
// Same code shape as 0x000fe220 (propagated; names are from that function)
unsigned int pure3d::d3dTexture::vfunc_19() {
    return this->f_f0;
}

namespace fn_ff6ae8d9 {

// 0x00326290 FUN_00326290 (99 B): matches/0x00326290.cpp
// sym: ?FUN_00326290@fn_ff6ae8d9@@YIXPAUd3dTexture_326290@1@@Z
void __fastcall FUN_00326290(d3dTexture_326290* self) {
    self->vt = ((hulk_intptr)DAT_004333ac);
    if (self->a)
        Release(self->a);
    if (self->b) {
        Release(self->b);
        FUN_0031e210(self->b);
    }
    if (self->c) {
        Release(self->c);
        FUN_0031e210(self->c);
    }
    if (self->d)
        Release(self->d);
    self->vt = ((hulk_intptr)DAT_00433354);
    self->BaseDestroy();
}


// 0x00326300 FUN_00326300 (39 B): matches/0x00326300.cpp
// sym: ?Set@Owner_326300@fn_ff6ae8d9@@QAEXPAUD3DResource@2@@Z
void Owner_326300::Set(D3DResource* value) {
    if (value)
        D3DResource_AddRef(value);
    if (resource)
        D3DResource_Release(resource);
    resource = value;
}

} // namespace fn_ff6ae8d9

// 0x00326330 FUN_00326330 (665 B): equivalent/0x00326330.cpp [wrapped: compile error C2440: '=' : cannot convert from 'int (__stdcall *)(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsig]
// sym: ?Create@TextureResource@fn_00326330@@QAE_NHHHHHHH@Z @3af5232999c1 @w091c74803fa3
namespace fn_00326330 {
// STATUS: equivalent (tools/equiv.py level 3: 4904 inputs, branch coverage 46/46)
// FUN_00326330 @ 0x00326330
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
int __fastcall FUN_00325fb0(int ignored, int field);
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
    field0e0 = FUN_00325fb0(0, field0b4);
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
} // namespace fn_00326330


// 0x003265f0 FUN_003265f0 (659 B): equivalent/0x003265f0.cpp [wrapped: compile error in a shared declaration (C2556)]
// sym: ?Create@TextureBuilder@fn_003265f0@@QAE_NHHHHHHHH@Z @01ae64de44ad @w9cc4157ecfeb
namespace fn_003265f0 {
// STATUS: equivalent (tools/equiv.py level 3: 10590 inputs, branch coverage 38/38)
// FUN_003265f0 @ 0x003265f0
// FUN_003265f0 @ 0x003265f0
// FUN_003265f0 @ 0x003265f0
typedef unsigned long DWORD;
struct Texture;
struct Palette;
struct SurfaceDesc_3265f0 {
    DWORD Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
namespace D3D8 {
Texture* __stdcall D3DDevice_CreateTexture2(DWORD width, DWORD height, DWORD depth, DWORD levels, DWORD usage, DWORD format, DWORD type);
Palette* __stdcall D3DDevice_CreatePalette2(DWORD size);
}
void __stdcall thunk_FUN_0038acb0(Texture* tex, DWORD level, SurfaceDesc_3265f0* out);
void FUN_0031c230(long hr);
int __fastcall FUN_00325fb0(int ignored, int mask);
void FUN_0031e1f0(Texture* tex, int size);
struct Layout_3265f0 {
    int f0, f4, f8, fc, f10;
    char pad14[0x44 - 0x14];
    int mask;
    char pad48[0x54 - 0x48];
};
void FUN_0031c600(SurfaceDesc_3265f0* desc, int a, Layout_3265f0* out, int b);
struct Ctx_3265f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual int GetMaxTextureSize();
};
// equiv-conv: FUN_00325fd0 ecx edx eax stack
int FUN_00325fd0(int a7, int a5, int a4, Ctx_3265f0* ctx);
struct TextureBuilder {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void SetFormat(int);
    char pad4[4];
    int error;
    Ctx_3265f0* ctx;
    char pad10[0x18 - 0x10];
    Texture* tex;
    char pad1c[0x68 - 0x1c];
    Palette* palette;
    int format;
    Layout_3265f0 layout;
    int c4pad;
    int srcFormat;
    int usage;
    int field_d0;
    int width;
    int height;
    int field_dc;
    int field_e0;
    int levels;
    int totalSize;
    unsigned char hasAlpha;
    unsigned char isPaletted;
    char padee[2];
    int fieldf0;
    bool Create(int width, int height, int depth, int a4, int a5, int levels, int a7, int a8);
};
bool TextureBuilder::Create(int w, int h, int d, int a4, int a5, int lvls, int a7, int a8) {
    if ((w & (w - 1)) != 0 || (h & (h - 1)) != 0 || (d & (d - 1)) != 0) {
        error = 0xc8;
        return false;
    }
    if (w > ctx->GetMaxTextureSize() || h > ctx->GetMaxTextureSize() || d > ctx->GetMaxTextureSize()) {
        error = 0xc9;
        return false;
    }
    int fmt = FUN_00325fd0(a7, a5, a4, ctx);
    format = fmt;
    if (fmt == -1) {
        error = 0xca;
        return false;
    }
    srcFormat = a7;
    usage = a8;
    field_d0 = 0;
    this->levels = lvls;
    width = w;
    height = h;
    hasAlpha = (a7 == 4 || a7 == 5 || a7 == 6 || a7 == 7 || a7 == 8);
    isPaletted = (a7 == 0xb);
    tex = D3D8::D3DDevice_CreateTexture2(w, h, d, lvls + 1, a8, fmt, 4);
    FUN_0031c230(tex ? 0 : 0x8007000e);
    if (format == 0xb)
        palette = D3D8::D3DDevice_CreatePalette2(0);
    SurfaceDesc_3265f0 desc;
    thunk_FUN_0038acb0(tex, 0, &desc);
    FUN_0031c230(0);
    SetFormat(fieldf0);
    FUN_0031c600(&desc, 0, &layout, 1);
    int stride = layout.f8;
    field_d0 = layout.f10;
    field_dc = stride;
    field_e0 = FUN_00325fb0(0, layout.mask);
    totalSize = 0;
    float scale;
    if (hasAlpha)
        scale = 0.5f;
    else
        scale = (float)(stride / 8);
    int cw = width;
    int ch = height;
    int cd = d;
    for (int i = 0; i < this->levels + 1; i++) {
        unsigned int size = cd * ch * cw;
        totalSize += (int)((float)size * scale);
        cw = (unsigned int)cw >> 1;
        ch = (unsigned int)ch >> 1;
        cd = (unsigned int)cd >> 1;
    }
    FUN_0031e1f0(tex, totalSize);
    return true;
}
} // namespace fn_003265f0


// 0x00326890 pure3d::d3dTexture::vfunc_10 (6 B): matches/0x00326890.cpp
// sym: ?vfunc_10@d3dTexture@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dTexture::vfunc_10() {
    return 0x100;
}


// 0x003268a0 pure3d::d3dTexture::vfunc_11 (34 B): matches/0x003268a0.cpp
// sym: ?vfunc_11@d3dTexture@pure3d@@UAEXIPAX@Z
 // namespace pure3d
void pure3d::d3dTexture::vfunc_11(unsigned int count, void* __p1) { unsigned int * src = (unsigned int *)__p1;

    if ((*(void * *)&this->f_68)) {
        void* dst = D3DPalette_Lock2((*(void * *)&this->f_68), 0);
        volatile unsigned int* p = src;
        memcpy(dst, (const void*)p, count * 4);
    }
}


// 0x003268d0 pure3d::d3dTexture::vfunc_12 (40 B): matches/0x003268d0.cpp
// sym: ?vfunc_12@d3dTexture@pure3d@@UAEHH@Z
int pure3d::d3dTexture::vfunc_12(hulk_intptr __p0) { u32_3268d0 * out = (u32_3268d0 *)__p0;

    if ((*(u32_3268d0 *)&this->f_68)) {
        void* p = D3D8::D3DPalette_Lock2((*(u32_3268d0 *)&this->f_68), 0);
        memcpy(out, p, 0x400);
    }
    return (int)(256);
}


// 0x00326900 pure3d::d3dTexture::vfunc_13 (272 B): equivalent/0x00326900.cpp [wrapped: conflict: pure3d::d3dTexture; pure3d::pddiObject]
// sym: ?vfunc_13@d3dTexture@pure3d@fn_00326900@@UAEPAUImageInfo_326900@23@IH@Z @eeb9a2219205 @w88741c449fff
namespace fn_00326900 {
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 10/10)
// pure3d::d3dTexture::vfunc_13 @ 0x00326900
namespace pure3d {
struct ImageInfo_326900 {
    int width;
    int height;
    int bitsPerPixel;
    int depth;
};
}
struct D3DTextureHandle;
struct D3DVolumeTextureHandle;
struct LockedRect_326900 {
    int pitch;
    void* bits;
};
struct LockedBox {
    int rowPitch;
    int slicePitch;
    void* bits;
};
struct SurfaceDesc_326900 {
    char data[0x1c];
};
struct VolumeDesc {
    char data[0x24];
};
namespace D3D8 {
void __stdcall Get2DSurfaceDesc(D3DTextureHandle* tex, unsigned int level, SurfaceDesc_326900* desc);
void __stdcall D3DTexture_LockRect(D3DTextureHandle* tex, unsigned int level, LockedRect_326900* locked, const void* rect, unsigned int flags);
void __stdcall D3DVolumeTexture_LockBox(D3DVolumeTextureHandle* tex, unsigned int level, LockedBox* locked, const void* box, unsigned int flags);
}
void __stdcall thunk_FUN_0038acb0(D3DVolumeTextureHandle* tex, unsigned int level, VolumeDesc* desc);
void FUN_0031c230(int arg);
void FUN_0031c570(SurfaceDesc_326900* desc, LockedRect_326900* locked, pure3d::ImageInfo_326900* info, int flag);
void FUN_0031c600(VolumeDesc* desc, LockedBox* locked, pure3d::ImageInfo_326900* info, int flag);
extern "C" void* FUN_0008d690(int size);

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
    virtual ImageInfo_326900* vfunc_13(unsigned int level, int unused);

    char pad_04[0xc];
    int locked;
    D3DTextureHandle* texture2D;
    D3DVolumeTextureHandle* texture3D;
    LockedRect_326900 lockedRect;
    LockedBox lockedBox;
    SurfaceDesc_326900 surfaceDesc;
    VolumeDesc volumeDesc;
    ImageInfo_326900 info;
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

pure3d::ImageInfo_326900* pure3d::d3dTexture::vfunc_13(unsigned int level, int unused) {
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
            dataEnd = (char*)(((hulk_uintptr)buffer + 0xf) & 0xfffffff0) + (info.height - 1) * info.width * bytesPerPixel;
            rowStride = -(info.width * bytesPerPixel);
        }
    }
    return &info;
}
} // namespace fn_00326900


// 0x00326a10 pure3d::d3dTexture::vfunc_14 (189 B): equivalent/0x00326a10.cpp [wrapped: conflict: pure3d::d3dTexture]
// sym: ?vfunc_14@d3dTexture@pure3d@fn_00326a10@@UAEXH@Z @da2ba997e707 @we7b13c583a05
namespace fn_00326a10 {
// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 10/10)
// pure3d::d3dTexture::vfunc_14 @ 0x00326a10
namespace XGRAPHC {
void __stdcall XGSwizzleRect(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __stdcall XGSwizzleBox(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
}
// equiv-conv: FUN_00325f30 eax
extern "C++" __declspec(nothrow) int FUN_00325f30(int format);
void __cdecl FUN_0008d330(unsigned);

namespace pure3d {
class d3dTexture {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void vfunc_14(int unused);
    char pad04[0x0c];
    unsigned f10, f14, f18;
    char pad1c[4];
    unsigned f20;
    char pad24[8];
    unsigned f2c, f30;
    char pad34[0x10];
    unsigned f44, f48, f4c;
    char pad50[0x0c];
    unsigned f5c, f60, f64;
    char pad68[0x84];
    unsigned char fEc, fEd;
    char padEE[6];
    unsigned fF4;
};

void d3dTexture::vfunc_14(int) {
    if (f10 == 0 && !fEc && !fEd) {
        if (f14 != 0) {
            int bytesPerPixel = FUN_00325f30(f30) >> 3;
            XGRAPHC::XGSwizzleRect((fF4 + 0xf) & 0xfffffff0, 0, 0, f20, f44, f48, 0, bytesPerPixel);
        } else if (f18 != 0) {
            int bytesPerPixel = FUN_00325f30(f4c) >> 3;
            XGRAPHC::XGSwizzleBox((fF4 + 0xf) & 0xfffffff0, 0, 0, 0, f2c, f5c, f60, f64, 0, bytesPerPixel);
        }
        FUN_0008d330(fF4);
        fF4 = 0;
    }
}
}
} // namespace fn_00326a10

namespace fn_ff6ae8d9 {

// 0x00326ad0 pure3d::d3dTexture::vfunc_16 (1 B): matches/0x00326ad0.cpp
// sym: ?FUN_00326ad0@fn_ff6ae8d9@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00326ad0() {}


// 0x00326ae0 pure3d::d3dTexture::vfunc_17 (1 B): matches/0x00326ae0.cpp
// sym: ?FUN_00326ae0@fn_ff6ae8d9@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00326ae0() {}

} // namespace fn_ff6ae8d9

// 0x00326af0 pure3d::d3dTexture::vfunc_18 (13 B): matches/0x00326af0.cpp
// sym: ?vfunc_18@d3dTexture@pure3d@@UAEXI@Z
 // namespace pure3d
void pure3d::d3dTexture::vfunc_18(unsigned int value) {
    this->f_f0 = value;
}


// 0x00326b00 FUN_00326b00 (63 B): matches/0x00326b00.cpp
// sym: ?FUN_00326b00@Obj_326b00@owners@@QAEXK@Z
 // namespace D3D8
void owners::Obj_326b00::FUN_00326b00(DWORD stage) {
    D3D8::D3DDevice_SetPalette(stage, palette);
    DWORD texture = texB;
    if (texture == 0)
        texture = texC;
    if (texture != 0)
        D3D8::D3DDevice_SetTexture(stage, texture);
    else if (texA != 0)
        D3D8::D3DDevice_SetTexture(stage, texA);
}


// 0x00326b40 FUN_00326b40 (254 B): equivalent/0x00326b40.cpp [wrapped: conflict: pure3d::d3dTexture]
// sym: ??0d3dTexture@pure3d@fn_00326b40@@QAE@I@Z @e2c243482144 @w1657151d0512
namespace fn_00326b40 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00326b40 @ 0x00326b40
namespace pure3d {
class d3dBase {
  public:
    d3dBase();
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class d3dTexture : public d3dBase {
  public:
    d3dTexture(hulk_uintptr arg);
    unsigned int f04, f08;
    unsigned int f0c, f10, f14, f18;
    char pad1c[0x68 - 0x1c];
    unsigned int f68;
    char pad6c[4];
    unsigned int f70, f74, f78, f7c, f80;
    unsigned char f84;
    char pad85[3];
    unsigned int f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0;
    unsigned int fc4;
    unsigned int fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8;
    unsigned char fec, fed, fee, fef;
    unsigned int ff0, ff4;
};
d3dTexture::d3dTexture(hulk_uintptr arg) : d3dBase() {
    f70 = 0; f74 = 0; f78 = 0; f7c = 0; f80 = 0;
    f84 = 0;
    fb8 = 0; fbc = 0; fc0 = 0;
    f94 = 0; f90 = 0; f8c = 0; f88 = 0;
    fa4 = 0; fa0 = 0; f9c = 0; f98 = 0;
    fb4 = 0; fb0 = 0; fac = 0; fa8 = 0;
    f0c = arg;
    f14 = 0; f18 = 0; f10 = 0;
    f68 = 0;
    ff4 = 0;
    fc8 = 0; fd0 = 0; fd4 = 0; fd8 = 0; fdc = 0; fe0 = 0; fe4 = 0;
    fec = 0; fed = 0; fee = 0;
    fe8 = 0;
    fcc = 1;
    ff0 = 0xf;
    fef = 1;
}
}
} // namespace fn_00326b40


// 0x00326c40 pure3d::d3dTexture::vfunc_3 (30 B): matches/0x00326c40.cpp
// sym: ??_Gd3dTexture@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::d3dTexture::~d3dTexture() {}

