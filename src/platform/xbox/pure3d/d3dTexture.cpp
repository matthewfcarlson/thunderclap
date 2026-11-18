// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00325f30..0x00326d60 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dTexture
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#include "decls/pddi_texture.h"
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
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture)
struct d3dTexture_326240 : HulkD3dTexture {
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
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture): the D3D handles are pointers
extern "C" void __cdecl FUN_0031e210(hulk_intptr);
// (x64t20) the XDK's D3DResource_Release and pddiObject's destructor body 0x0031bae0 as defined (d3dDevice.cpp), by
// their names (a local `Release` and `BaseDestroy` had no native definition: the texture's release stopped there)
extern "C" void __fastcall FUN_0031bae0(void* self);
struct d3dTexture_326290 : HulkD3dTexture {
};
struct D3DResource {};
void __stdcall D3DResource_AddRef(D3DResource*);
void __stdcall D3DResource_Release(D3DResource*);
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture): the wrapped resource
struct Owner_326300 : HulkD3dTexture {
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
void* __stdcall D3DPalette_Lock2(void*, int);
}


// 0x00325f30 FUN_00325f30 (43 B): equivalent/0x00325f30.cpp
// sym: _FUN_00325f30 @fccd57a6909a @w1a7e1db73e1d @v9c498d87c8f5
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
// sym: ?FUN_00325fd0@fn_ff6ae8d9@@YAHHHHPAVDevice_325fd0@1@@Z @69f54cdfb770 @wd5e598858790 @vf8f13d66e44a
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
// sym: ?FUN_00326110@d3dTexture@pure3d@fn_00326110@@QAEPAU123@PAUCtx@3@PAX@Z @73375809c2a3 @wc255c9155ada @vd59636a4d691
namespace fn_00326110 {
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 2/2)
// FUN_00326110 @ 0x00326110
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture): the constructor is a member named by its
// address (it returns this), pddiObject's 0x0031bac0 is called by its address name and the vftable stored by address
// (the local stand-in's constructor had no definition natively and its vftable was clang's)
namespace D3D8 {
void __stdcall D3DResource_AddRef(void*);
}
struct Ctx;
extern "C" char DAT_004333ac[];   // pure3d::d3dTexture's vftable
namespace pure3d {
struct d3dTexture : HulkD3dTexture {
    d3dTexture* FUN_00326110(Ctx* ctx, void* resource);
    HulkD3dTexture* FUN_0031bac0();   // pure3d::pddiObject's constructor
};
d3dTexture* d3dTexture::FUN_00326110(Ctx* c, void* res) {
    FUN_0031bac0();
    vftable = (void*)DAT_004333ac;
    lock.width = 0;
    lock.height = 0;
    lock.bitsPerPixel = 0;
    lock.depth = 0;
    lock.type = 0;
    lock.direct = 0;
    lock.stride = 0;
    lock.slicePitch = 0;
    lock.bits = 0;
    lock.left[3] = 0;
    lock.left[2] = 0;
    lock.left[1] = 0;
    lock.left[0] = 0;
    lock.right[3] = 0;
    lock.right[2] = 0;
    lock.right[1] = 0;
    lock.right[0] = 0;
    lock.mask[3] = 0;
    lock.mask[2] = 0;
    lock.mask[1] = 0;
    lock.mask[0] = 0;
    context = c;
    texture = 0;
    volume = 0;
    resource = res;
    if (res)
        D3D8::D3DResource_AddRef(res);
    usage = 1;
    fef = 1;
    palette = 0;
    buffer = 0;
    format = 0;
    type = 0;
    width = 0;
    height = 0;
    bitsPerPixel = 0;
    alphaBits = 0;
    mips = 0;
    compressed = 0;
    palettized = 0;
    linear = 0;
    bytes = 0;
    priority = 0xf;
    return this;
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
    return this->f_d4;
}

namespace fn_ff6ae8d9 {

// 0x00326240 pure3d::d3dTexture::vfunc_6 (7 B): matches/0x00326240.cpp
// sym: ?vfunc_6@d3dTexture_326240@fn_ff6ae8d9@@QAEHXZ
int d3dTexture_326240::vfunc_6() {
    return height;
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
    return this->f_e0;
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
    self->vftable = (void*)DAT_004333ac;
    if (self->resource)
        D3DResource_Release((D3DResource*)self->resource);
    if (self->texture) {
        D3DResource_Release((D3DResource*)self->texture);
        FUN_0031e210((hulk_intptr)self->texture);
    }
    if (self->volume) {
        D3DResource_Release((D3DResource*)self->volume);
        FUN_0031e210((hulk_intptr)self->volume);
    }
    if (self->palette)
        D3DResource_Release((D3DResource*)self->palette);
    self->vftable = (void*)DAT_00433354;
    FUN_0031bae0(self);
}


// 0x00326300 FUN_00326300 (39 B): matches/0x00326300.cpp
// sym: ?Set@Owner_326300@fn_ff6ae8d9@@QAEXPAUD3DResource@2@@Z
void Owner_326300::Set(D3DResource* value) {
    if (value)
        D3DResource_AddRef(value);
    if (resource)
        D3DResource_Release((D3DResource*)resource);
    resource = value;
}

} // namespace fn_ff6ae8d9

// 0x00326330 FUN_00326330 (665 B): equivalent/0x00326330.cpp [wrapped: compile error C2440: '=' : cannot convert from 'int (__stdcall *)(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsig]
// sym: ?Create@TextureResource@fn_00326330@@QAE_NHHHHHHH@Z @e46dc6dbab35 @w13b03879fbc3 @v23863f97e4c9
namespace fn_00326330 {
// STATUS: equivalent (tools/equiv.py level 3: 4904 inputs, branch coverage 46/46)
// FUN_00326330 @ 0x00326330
// FUN_00326330 @ 0x00326330
namespace D3D8 {
void* __stdcall D3DDevice_CreateTexture2(unsigned long w, unsigned long h, unsigned long depth, unsigned long levels, unsigned long usage, unsigned long format, unsigned long type);
void* __stdcall D3DDevice_CreatePalette2(unsigned long size);
void __stdcall Get2DSurfaceDesc(void* tex, unsigned long level, void* desc);   // (x64t17) the texture a pointer
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
void __cdecl FUN_0031c570(SurfaceDesc_326330* desc, HULK_TYPE64(int, const void*) a, void* out, HULK_TYPE64(int, char) b);   // (x64t18) natively the definition's types (D71)
void __cdecl FUN_0031e1f0(void* tex, int bytes);   // (x64t17) the texture a pointer
int __fastcall FUN_00325fb0(int ignored, int field);
// equiv-conv: FUN_00325fd0 ecx edx eax stack
int __cdecl FUN_00325fd0(int fmt, int a3, int a2, GfxDevice* dev);

// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture); slot 18 (the priority) through the vftable
class TextureSlots_326330 {
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
};
struct TextureResource : HulkD3dTexture {
    GfxDevice* device() { return (GfxDevice*)context; }
    bool Create(int width, int height, int a2, int a3, int mips, int fmt, int a6);
};
bool TextureResource::Create(int w, int h, int a2, int a3, int mips, int fmt, int a6) {
    int usage = 0;
    if (fmt != 0) {
        if (fmt == 12) {
            usage = 1;
            fmt = 11;
            linear = 1;
        }
    } else {
        if ((w & (w - 1)) != 0 || (h & (h - 1)) != 0) {
            error = 0xc8;
            return false;
        }
    }
    if (w > device()->GetMaxTextureSize() || h > device()->GetMaxTextureSize()) {
        error = 0xc9;
        return false;
    }
    if (fmt == 1)
        fmt = 0;
    int mapped = FUN_00325fd0(fmt, a3, a2, device());
    if (mapped == -1) {
        error = 0xca;
        return false;
    }
    if (linear) {
        switch (mapped) {
        case 3: case 5: case 6: case 7: case 17: case 18: case 28: case 30:
            break;
        default:
            error = 0xca;
            return false;
        }
    }
    this->usage = a6;
    format = fmt;
    type = 0;
    this->mips = mips;
    width = w;
    height = h;
    compressed = (fmt == 4 || fmt == 5 || fmt == 6 || fmt == 7 || fmt == 8);
    palettized = (fmt == 11);
    texture = D3D8::D3DDevice_CreateTexture2(w, h, 1, mips + 1, usage, mapped, 3);
    FUN_0031c230(texture != 0 ? 0 : 0x8007000e);
    if (mapped == 11)
        palette = D3D8::D3DDevice_CreatePalette2(0);
    SurfaceDesc_326330 desc;
    D3D8::Get2DSurfaceDesc(texture, 0, &desc);
    FUN_0031c230(0);
    ((TextureSlots_326330*)this)->SetDirty(priority);
    FUN_0031c570(&desc, 0, &lock, 1);
    type = lock.type;
    unsigned int bitsPerPixel = lock.bitsPerPixel;
    this->bitsPerPixel = bitsPerPixel;
    alphaBits = FUN_00325fb0(0, lock.mask[3]);
    bytes = 0;
    hulk_freg bytesPer;             // kept in st (fild of the byte count: exact)
    if (compressed)
        bytesPer = 0.5f;
    else
        bytesPer = (hulk_freg)((int)bitsPerPixel / 8);
    unsigned int mw = width;
    unsigned int mh = height;
    for (int i = 0; i < this->mips + 1; i++) {
        bytes += (int)(__int64)((hulk_freg)(mw * mh) * bytesPer);   // fild (unsigned) * bytesPer in st, _ftol
        mw >>= 1;
        mh >>= 1;
    }
    FUN_0031e1f0(texture, bytes);
    return true;
}
} // namespace fn_00326330


// 0x003265f0 FUN_003265f0 (659 B): equivalent/0x003265f0.cpp [wrapped: compile error in a shared declaration (C2556)]
// sym: ?Create@TextureBuilder@fn_003265f0@@QAE_NHHHHHHHH@Z @ef81fa798c61 @w2eb9e6ab04a3 @v23dbe6a34f9f
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
void FUN_0031c600(SurfaceDesc_3265f0* desc, HULK_TYPE64(int, const void*) a, HulkPixelLock* out, HULK_TYPE64(int, char) b);   // (x64t17) the lock record; (x64t18) natively the definition's types (D71)
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
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture); slot 18 (the priority) through the vftable
struct TextureSlots_3265f0 {
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
};
struct TextureBuilder : HulkD3dTexture {
    Ctx_3265f0* ctx() { return (Ctx_3265f0*)context; }
    bool Create(int width, int height, int depth, int a4, int a5, int levels, int a7, int a8);
};
bool TextureBuilder::Create(int w, int h, int d, int a4, int a5, int lvls, int a7, int a8) {
    if ((w & (w - 1)) != 0 || (h & (h - 1)) != 0 || (d & (d - 1)) != 0) {
        error = 0xc8;
        return false;
    }
    if (w > ctx()->GetMaxTextureSize() || h > ctx()->GetMaxTextureSize() || d > ctx()->GetMaxTextureSize()) {
        error = 0xc9;
        return false;
    }
    int fmt = FUN_00325fd0(a7, a5, a4, ctx());
    d3dFormat = fmt;
    if (fmt == -1) {
        error = 0xca;
        return false;
    }
    format = a7;
    usage = a8;
    type = 0;
    this->mips = lvls;
    width = w;
    height = h;
    compressed = (a7 == 4 || a7 == 5 || a7 == 6 || a7 == 7 || a7 == 8);
    palettized = (a7 == 0xb);
    volume = D3D8::D3DDevice_CreateTexture2(w, h, d, lvls + 1, a8, fmt, 4);
    FUN_0031c230(volume ? 0 : 0x8007000e);
    if (d3dFormat == 0xb)
        palette = D3D8::D3DDevice_CreatePalette2(0);
    SurfaceDesc_3265f0 desc;
    thunk_FUN_0038acb0((Texture*)volume, 0, &desc);
    FUN_0031c230(0);
    ((TextureSlots_3265f0*)this)->SetFormat(priority);
    FUN_0031c600(&desc, 0, &lock, 1);
    int stride = lock.bitsPerPixel;
    type = lock.type;
    bitsPerPixel = stride;
    alphaBits = FUN_00325fb0(0, lock.mask[3]);
    bytes = 0;
    hulk_freg scale; // st(1) through the loop in the original (fild, never stored)
    if (compressed)
        scale = 0.5f;
    else
        scale = (hulk_freg)(stride / 8);
    int cw = width;
    int ch = height;
    int cd = d;
    for (int i = 0; i < this->mips + 1; i++) {
        unsigned int size = cd * ch * cw;
        bytes += (int)(__int64)((hulk_freg)size * scale); // fild (+2^32); fmul st1; _ftol's low word
        cw = (unsigned int)cw >> 1;
        ch = (unsigned int)ch >> 1;
        cd = (unsigned int)cd >> 1;
    }
    FUN_0031e1f0((Texture*)volume, bytes);
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

    if (this->f_68) {
        void* dst = D3DPalette_Lock2(this->f_68, 0);
        volatile unsigned int* p = src;
        memcpy(dst, (const void*)p, count * 4);
    }
}


// 0x003268d0 pure3d::d3dTexture::vfunc_12 (40 B): matches/0x003268d0.cpp
// sym: ?vfunc_12@d3dTexture@pure3d@@UAEHH@Z
int pure3d::d3dTexture::vfunc_12(hulk_intptr __p0) { u32_3268d0 * out = (u32_3268d0 *)__p0;

    if (this->f_68) {   // (x64t17) the palette a pointer (was read as its low 32 bits)
        void* p = D3D8::D3DPalette_Lock2(this->f_68, 0);
        memcpy(out, p, 0x400);
    }
    return (int)(256);
}


// 0x00326900 pure3d::d3dTexture::vfunc_13 (272 B): equivalent/0x00326900.cpp [wrapped: conflict: pure3d::d3dTexture; pure3d::pddiObject]
// sym: ?vfunc_13@d3dTexture@pure3d@fn_00326900@@QAEPAUHulkPixelLock@@IH@Z @d373bccdd104 @w724fca37709c @vb362909e8da3
namespace fn_00326900 {
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 10/10)
// pure3d::d3dTexture::vfunc_13 @ 0x00326900
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture): slot 13 locks a level and returns the record's
// lock (HulkPixelLock); the formats the Xbox swizzles get a staging copy, written bottom-up
struct SurfaceDesc_326900 {
    char data[0x1c];
};
struct VolumeDesc {
    char data[0x1c];
};
namespace D3D8 {
void __stdcall Get2DSurfaceDesc(void* tex, unsigned int level, void* desc);
void __stdcall D3DTexture_LockRect(void* tex, unsigned int level, void* locked, const void* rect, unsigned int flags);
void __stdcall D3DVolumeTexture_LockBox(void* tex, unsigned int level, void* locked, const void* box, unsigned int flags);
}
void __stdcall thunk_FUN_0038acb0(void* tex, unsigned int level, void* desc);
void FUN_0031c230(int arg);
void FUN_0031c570(void* desc, void* locked, HulkPixelLock* info, HULK_TYPE64(int, char) flag);   // (x64t18) natively
void FUN_0031c600(void* desc, void* locked, HulkPixelLock* info, HULK_TYPE64(int, char) flag);   // the definition's (D71)
extern "C" void* FUN_0008d690(int size);

namespace pure3d {
struct d3dTexture : HulkD3dTexture {
    HulkPixelLock* vfunc_13(unsigned int level, int unused);
};
}

HulkPixelLock* pure3d::d3dTexture::vfunc_13(unsigned int level, int unused) {
    if (resource == 0) {
        if (texture != 0) {
            D3D8::Get2DSurfaceDesc(texture, level, surfaceDesc);
            FUN_0031c230(0);
            D3D8::D3DTexture_LockRect(texture, level, &lockedRect, 0, 0);
            FUN_0031c230(0);
            FUN_0031c570(surfaceDesc, &lockedRect, &lock, 1);
        } else if (volume != 0) {
            thunk_FUN_0038acb0(volume, level, volumeDesc);
            FUN_0031c230(0);
            D3D8::D3DVolumeTexture_LockBox(volume, level, &lockedBox, 0, 0);
            FUN_0031c230(0);
            FUN_0031c600(volumeDesc, &lockedBox, &lock, 1);
        }
        if (compressed == 0 && palettized == 0) {
            buffer = (unsigned char*)FUN_0008d690((lock.bitsPerPixel >> 3) * lock.depth * lock.height * lock.width + 0x10);
            int bytesPerPixel = lock.bitsPerPixel >> 3;
            lock.bits = (unsigned char*)(((hulk_uintptr)buffer + 0xf) & ~(hulk_uintptr)0xf) + (lock.height - 1) * lock.width * bytesPerPixel;
            lock.stride = -(lock.width * bytesPerPixel);
        }
    }
    return &lock;
}
} // namespace fn_00326900



// 0x00326a10 pure3d::d3dTexture::vfunc_14 (189 B): equivalent/0x00326a10.cpp [wrapped: conflict: pure3d::d3dTexture]
// sym: ?vfunc_14@d3dTexture@pure3d@fn_00326a10@@QAEXH@Z @e9a8123f9dcf @w0400036c699c @vcef82bad93f9
namespace fn_00326a10 {
// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 10/10)
// pure3d::d3dTexture::vfunc_14 @ 0x00326a10
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture): slot 14 swizzles the staging copy into the
// locked level and frees it (the XG calls take the pointers as pointers)
namespace XGRAPHC {
void __stdcall XGSwizzleRect(void*, unsigned, unsigned, void*, unsigned, unsigned, unsigned, unsigned);
void __stdcall XGSwizzleBox(void*, unsigned, unsigned, unsigned, void*, unsigned, unsigned, unsigned, unsigned, unsigned);
}
// equiv-conv: FUN_00325f30 eax
extern "C++" __declspec(nothrow) int FUN_00325f30(int format);
void __cdecl FUN_0008d330(void*);

namespace pure3d {
struct d3dTexture : HulkD3dTexture {
    void vfunc_14(int unused);
};

void d3dTexture::vfunc_14(int) {
    if (resource == 0 && !compressed && !palettized) {
        if (texture != 0) {
            int bytesPerPixel = FUN_00325f30(surfaceDesc[0]) >> 3;
            XGRAPHC::XGSwizzleRect((void*)(((hulk_uintptr)buffer + 0xf) & ~(hulk_uintptr)0xf), 0, 0, lockedRect.bits, surfaceDesc[5], surfaceDesc[6], 0, bytesPerPixel);
        } else if (volume != 0) {
            int bytesPerPixel = FUN_00325f30(volumeDesc[0]) >> 3;
            XGRAPHC::XGSwizzleBox((void*)(((hulk_uintptr)buffer + 0xf) & ~(hulk_uintptr)0xf), 0, 0, 0, lockedBox.bits, volumeDesc[4], volumeDesc[5], volumeDesc[6], 0, bytesPerPixel);
        }
        FUN_0008d330(buffer);
        buffer = 0;
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
// sym: ?FUN_00326b00@Texture_326b00@fn_ff6ae8d9@@QAEXK@Z
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture; owners' Obj_326b00 kept the handles in 32-bit
// words): binds the palette, then the texture (the created one, else the volume, else the wrapped resource) to a stage
namespace fn_ff6ae8d9 {
namespace D3D8 {
void __stdcall D3DDevice_SetPalette(DWORD, void*);
void __stdcall D3DDevice_SetTexture(DWORD, void*);
}
struct Texture_326b00 : HulkD3dTexture {
    void FUN_00326b00(DWORD stage);
};
void Texture_326b00::FUN_00326b00(DWORD stage) {
    D3D8::D3DDevice_SetPalette(stage, palette);
    void* tex = texture;
    if (tex == 0)
        tex = volume;
    if (tex != 0)
        D3D8::D3DDevice_SetTexture(stage, tex);
    else if (resource != 0)
        D3D8::D3DDevice_SetTexture(stage, resource);
}
} // namespace fn_ff6ae8d9


// 0x00326b40 FUN_00326b40 (254 B): equivalent/0x00326b40.cpp [wrapped: conflict: pure3d::d3dTexture]
// sym: ?FUN_00326b40@d3dTexture@pure3d@fn_00326b40@@QAEPAU123@PAX@Z @cb3dd2d573f3 @wda35968cb24b @v4ca080519280
namespace fn_00326b40 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00326b40 @ 0x00326b40
// (x64t17) the texture's record (decls/pddi_texture.h HulkD3dTexture), as 0x00326110: d3dDevice's slot 9 constructs
// it (the local stand-in's base constructor had no definition natively)
extern "C" char DAT_004333ac[];   // pure3d::d3dTexture's vftable
namespace pure3d {
struct d3dTexture : HulkD3dTexture {
    d3dTexture* FUN_00326b40(void* ctx);
    HulkD3dTexture* FUN_0031bac0();   // pure3d::pddiObject's constructor
};
d3dTexture* d3dTexture::FUN_00326b40(void* ctx) {
    FUN_0031bac0();
    vftable = (void*)DAT_004333ac;
    lock.width = 0; lock.height = 0; lock.bitsPerPixel = 0; lock.depth = 0; lock.type = 0;
    lock.direct = 0;
    lock.stride = 0; lock.slicePitch = 0; lock.bits = 0;
    lock.left[3] = 0; lock.left[2] = 0; lock.left[1] = 0; lock.left[0] = 0;
    lock.right[3] = 0; lock.right[2] = 0; lock.right[1] = 0; lock.right[0] = 0;
    lock.mask[3] = 0; lock.mask[2] = 0; lock.mask[1] = 0; lock.mask[0] = 0;
    context = ctx;
    texture = 0; volume = 0; resource = 0;
    palette = 0;
    buffer = 0;
    format = 0; type = 0; width = 0; height = 0; bitsPerPixel = 0; alphaBits = 0; mips = 0;
    compressed = 0; palettized = 0; linear = 0;
    bytes = 0;
    usage = 1;
    priority = 0xf;
    fef = 1;
    return this;
}
}
} // namespace fn_00326b40



// 0x00326c40 pure3d::d3dTexture::vfunc_3 (30 B): matches/0x00326c40.cpp
// sym: ?vfunc_3@d3dTexture_326c40@fn_00326c40@@QAEPAU12@E@Z
// scalar deleting destructor: the destructor's body 0x00326290, then (flags & 1) the free.
// (x64t20) an explicit function: gen's `pure3d::d3dTexture::~d3dTexture() {}` stood for it, which natively defines
// no function for the vftable slot (the release of the copyright sprite's texture reached `hulk_x_00326c40`)
namespace fn_00326c40 {
void __cdecl thunk_FUN_00267090(void*);
struct d3dTexture_326c40 {
    void FUN_00326290();   // the destructor's body
    d3dTexture_326c40* vfunc_3(unsigned char flags);
};
d3dTexture_326c40* d3dTexture_326c40::vfunc_3(unsigned char flags) {
    FUN_00326290();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00326c40

