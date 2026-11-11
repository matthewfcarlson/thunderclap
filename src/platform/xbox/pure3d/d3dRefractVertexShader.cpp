// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032ee30..0x0032fc40 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dRefractVertexShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f721c355 {
#define TREE_TU_END }
namespace fn_f721c355 {} using namespace fn_f721c355;
#include "platform/xbox/pure3d.h"
// (x64t3) a local view's pad up to gen d3dContext's field F (byte K of the 32-bit context), less the view's own leading
// bytes B (its vftable pointer, or nothing): the views' fields sit at gen's offsets on 64-bit too (they were 32-bit pads)
#if defined(HULK_PTR64)
#define HULK_D3DCTX_PAD(f, k, b) (__builtin_offsetof(::pure3d::d3dContext, f) - (b))
#else
#define HULK_D3DCTX_PAD(f, k, b) ((k) - (b))
#endif

// ---- declarations shared by the functions below
namespace fn_f721c355 {
struct Color_32ee30 { float red, green, blue, alpha; };
class X_32eee0 {
  public:
    char pad[0x88];
    void Set(int value);
};
class Obj_32eef0 {
  public:
    char pad[0x8c];
    int value;
    void Set(int v);
};
struct Obj_32ef00 {
    char pad[0x90];
    int m;
    void Set(int v);
};
extern "C" char DAT_00433cac[];
class Obj_32ef10 {
  public:
    virtual void A();
    virtual void B();
};
struct d3dRefractVertexShader_nv_32ef10 {
    void Go();
};
class d3dRefractVertexShader_32ef10 {
  public:
    virtual void A();
    char pad[0x7c];
    Obj_32ef10* a;
    Obj_32ef10* b;
    void F();
};
class pddiObject_32ef90 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32ef90 : public pddiObject_32ef90 {};
class pddiBaseShader_32ef90 : public pddiShader_32ef90 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_32ef90 : public pddiBaseShader_32ef90 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
namespace D3D8 {
void __stdcall D3DDevice_SetPalette(int stage, int palette);
}
extern unsigned int DAT_0039db08;
extern TexSlot DAT_0039db10[];
class TexObj_32efa0 {
  public:
    void FUN_00326300(Surface* s);
};
struct StageCache_32efa0 {
    void FUN_00329f70(int a, int b, const void* p);
    char pad0[8];
    TexObj_32efa0* tex[4];
    int texCoordIndex[4];
    int modes[4];
    char pad38[0x48 - 0x38];
    int f48;
    char pad4c[0x9c - 0x4c];
    int f9c;
    char padA0[0xe4 - 0xa0];
    int fe4;
    char padE8[0xf4 - 0xe8];
    int dirty[4];
    char pad104[0x108 - 0x104];
    unsigned int textureFactor;
};
struct Viewport_32efa0 {
    void FUN_0031b1e0();
    char pad0[0x498];
    Surface* surface;
};
class Context {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual unsigned char Slot63();
    char pad4[HULK_D3DCTX_PAD(f_154, 0x154, sizeof(void*))];
    Viewport_32efa0* viewport;
};
class d3dRefractVertexShader_32efa0 {
  public:
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
    void vfunc_14(int unused);
    char pad0[0x10];
    Context* ctx;
    StageCache_32efa0* cache;
    char pad18[4];
    int f1c;
    char pad20[0x28 - 0x20];
    unsigned char b28;
    char pad29[0x44 - 0x29];
    int f44;
    unsigned char b48;
    char pad49[0x4c - 0x49];
    int f4c;
    char f50[0x7c - 0x50];
    unsigned char b7c;
    char pad7d[0x80 - 0x7d];
    TexObj_32efa0* tex80;
    TexObj_32efa0* tex84;
    char pad88[4];
    float alpha;
    unsigned int color;
    int f94;
    unsigned char b98;
    unsigned char b99;
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Holder {
    char pad[0x80];
    Obj* ptr;

  public:
    void Set(Obj* p);
};
class Ref_32f360 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_32f360;
class d3dRefractVertexShader_32f360 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dRefractVertexShader_32f360* vfunc_3(unsigned int);
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
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    void cleanup();
    char pad[0x80 - 4];
    Ref_32f360* a;
    Ref_32f360* b;
};
void __cdecl destroy(d3dRefractVertexShader_32f360*);


// 0x0032ee30 FUN_0032ee30 (105 B): equivalent/0x0032ee30.cpp
// sym: ?FUN_0032ee30@fn_f721c355@@YAXPAUColor_32ee30@1@I@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0032ee30 @ 0x0032ee30
// equiv-conv: FUN_0032ee30 ecx stack
void __cdecl FUN_0032ee30(Color_32ee30* color, unsigned int packed) {
    color->red = (float)(int)((packed >> 16) & 255) * 0.003921568859368563f;
    color->green = (float)(int)((packed >> 8) & 255) * 0.003921568859368563f;
    color->blue = (float)(int)(packed & 255) * 0.003921568859368563f;
    color->alpha = (float)(int)(packed >> 24) * 0.003921568859368563f;
}


// 0x0032eee0 FUN_0032eee0 (13 B): matches/0x0032eee0.cpp
// sym: ?Set@X_32eee0@fn_f721c355@@QAEXH@Z
void X_32eee0::Set(int value) {
    *(int*)((char*)this + 0x88) = value;
}


// 0x0032eef0 FUN_0032eef0 (13 B): matches/0x0032eef0.cpp
// sym: ?Set@Obj_32eef0@fn_f721c355@@QAEXH@Z
void Obj_32eef0::Set(int v) {
    value = v;
}


// 0x0032ef00 FUN_0032ef00 (13 B): matches/0x0032ef00.cpp
// sym: ?Set@Obj_32ef00@fn_f721c355@@QAEXH@Z
void Obj_32ef00::Set(int v) {
    m = v;
}


// 0x0032ef10 FUN_0032ef10 (47 B): matches/0x0032ef10.cpp
// sym: ?F@d3dRefractVertexShader_32ef10@fn_f721c355@@QAEXXZ
void d3dRefractVertexShader_32ef10::F() {
    Obj_32ef10* x = a;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433cac);
    if (x)
        x->B();
    Obj_32ef10* y = b;
    if (y)
        y->B();
    ((d3dRefractVertexShader_nv_32ef10*)(((pure3d::d3dRefractVertexShader*)this)))->Go();
}


// 0x0032ef40 pure3d::d3dRefractVertexShader::vfunc_15 (6 B): matches/0x0032ef40.cpp
// sym: _FUN_0032ef40
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ef40() {
    return &(*(int*)&DAT_004d88b8);
}


// 0x0032ef50 pure3d::d3dRefractVertexShader::vfunc_16 (6 B): matches/0x0032ef50.cpp
// sym: _FUN_0032ef50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ef50() {
    return &(*(int*)&DAT_004d8978);
}


// 0x0032ef60 pure3d::d3dRefractVertexShader::vfunc_17 (6 B): matches/0x0032ef60.cpp
// sym: _FUN_0032ef60
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ef60() {
    return &(*(int*)&DAT_004d8840);
}


// 0x0032ef70 pure3d::d3dRefractVertexShader::vfunc_18 (6 B): matches/0x0032ef70.cpp
// sym: _FUN_0032ef70
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ef70() {
    return &(*(int*)&DAT_004d88e8);
}


// 0x0032ef80 pure3d::d3dRefractVertexShader::vfunc_4 (6 B): matches/0x0032ef80.cpp
// sym: _FUN_0032ef80
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ef80() {
    return &(*(int*)&DAT_004d8824);
}

} // namespace fn_f721c355

// 0x0032ef90 pure3d::d3dRefractVertexShader::vfunc_11 (6 B): matches/0x0032ef90.cpp
// sym: ?vfunc_11@d3dRefractVertexShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dRefractVertexShader::vfunc_11() {
    return 1;
}

namespace fn_f721c355 {

// 0x0032efa0 pure3d::d3dRefractVertexShader::vfunc_14 (619 B): equivalent/0x0032efa0.cpp
// sym: ?vfunc_14@d3dRefractVertexShader_32efa0@fn_f721c355@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19543 inputs, branch coverage 28/28)
// pure3d::d3dRefractVertexShader::vfunc_14 @ 0x0032efa0
void d3dRefractVertexShader_32efa0::vfunc_14(int) {
    ctx->viewport->FUN_0031b1e0();
    Surface* surf = ctx->viewport->surface;
    tex84->FUN_00326300(surf);
    unsigned int factor = ((unsigned int)(__int64)(int)(__int64)(alpha * 255.0f) << 24) | (color & 0xffffff);
    if (factor != cache->textureFactor) {
        cache->textureFactor = factor;
        D3D8::D3DDevice_SetRenderState_TextureFactor(factor);
    }
    ((owners::Obj_329e50 *)cache)->FUN_00329e50(0, 4, 3, 2);
    if (cache->texCoordIndex[0] != 0) {
        cache->texCoordIndex[0] = 0;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(0, 0);
    }
    if (cache->dirty[0] != 0) {
        cache->dirty[0] = 0;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[0].v54 = 0;
    }
    if (cache->modes[0] != 1) {
        cache->modes[0] = 1;
        unsigned int t = ((unsigned int*)&DAT_004d4efc)[1];
        DAT_0039db08 |= 1;
        DAT_0039db10[0].v0 = t;
        DAT_0039db10[0].v4 = t;
        DAT_0039db10[0].v8 = t;
    }
    ((owners::Obj_329c90 *)cache)->FUN_00329c90(0, f44);
    if (cache->fe4 != 5) {
        cache->fe4 = 5;
        DAT_0039db08 |= 0x800;
        DAT_0039db60 = 5;
    }
    TexObj_32efa0* t0 = surf ? tex84 : 0;
    if (t0 != cache->tex[0]) {
        cache->tex[0] = t0;
        if (t0) {
            ((owners::Obj_326b00 *)t0)->FUN_00326b00(0);
        } else {
            D3D8::D3DDevice_SetTexture(0, 0);
            D3D8::D3DDevice_SetPalette(0, 0);
        }
    }
    ((owners::Obj_329e50 *)cache)->FUN_00329e50(1, (b48 != 0) + 3, 0, 2);
    TexObj_32efa0* t1 = tex80;
    if (t1 != cache->tex[1]) {
        cache->tex[1] = t1;
        if (t1) {
            ((owners::Obj_326b00 *)t1)->FUN_00326b00(1);
        } else {
            D3D8::D3DDevice_SetTexture(1, 0);
            D3D8::D3DDevice_SetPalette(1, 0);
        }
    }
    FUN_0032a320(1, 0);
    StageCache_32efa0* c2 = cache;
    ((owners::C_329cf0 *)c2)->FUN_00329cf0(2, 0xf, 5);
    if (c2->f9c != 1) {
        c2->f9c = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039dc4c = 1;
    }
    ((owners::C_329da0 *)cache)->FUN_00329da0(2, 2, 0);
    if (cache->tex[2] != 0) {
        cache->tex[2] = 0;
        D3D8::D3DDevice_SetTexture(2, 0);
        D3D8::D3DDevice_SetPalette(2, 0);
    }
    ((owners::State_329bb0 *)cache)->FUN_00329bb0(3);
    f94 = f1c;
    b98 = b28;
    b99 = ctx->Slot63();
    f1c = 1;
    b28 = 0;
    if (f4c != cache->f48) {
        cache->f48 = f4c;
        unsigned int v = ((unsigned int*)&DAT_004d4f24)[f4c];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    cache->FUN_00329f70(b48, b7c, f50);
    FUN_0032a260();
}


// 0x0032f210 FUN_0032f210 (44 B): matches/0x0032f210.cpp
// sym: ?Set@Holder@fn_f721c355@@QAEXPAVObj@2@@Z
void Holder::Set(Obj* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}

} // namespace fn_f721c355

// 0x0032f240 pure3d::d3dRefractVertexShader::vfunc_22 (3 B): matches/0x0032f240.cpp
// sym: ?vfunc_22@d3dRefractVertexShader@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::d3dRefractVertexShader::vfunc_22() {
    return true;
}


// 0x0032f250 pure3d::d3dRefractVertexShader::vfunc_23 (18 B): matches/0x0032f250.cpp
// sym: ?vfunc_23@d3dRefractVertexShader@pure3d@@UAEPAXXZ
void* pure3d::d3dRefractVertexShader::vfunc_23() {
    if (this->f_7d)
        return (void*)("skin_refract");
    return (void*)("refract");
}

namespace fn_f721c355 {

// 0x0032f270 pure3d::d3dRefractVertexShader::vfunc_12 (1 B): matches/0x0032f270.cpp
// sym: ?FUN_0032f270@fn_f721c355@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0032f270() {}

} // namespace fn_f721c355

// 0x0032f280 pure3d::d3dRefractVertexShader::vfunc_13 (82 B): matches/0x0032f280.cpp [wrapped: conflict: DAT_0039db08; DAT_0039db60; pure3d::Texture; pure3d::d3dRefractVertexShader]
// sym: ?vfunc_13@d3dRefractVertexShader@pure3d@fn_0032f280@@QAEXXZ
namespace fn_0032f280 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::d3dRefractVertexShader::vfunc_13 @ 0x0032f280
namespace pure3d {
struct ShaderState_32f280 {
    char pad[0xe4];
    int mode;
};
struct Texture {
    void FUN_00326300(int);
};
struct d3dRefractVertexShader {
    char pad0[0x14];
    ShaderState_32f280* state;
    char pad18[4];
    int value1c;
    char pad20[8];
    unsigned char value28;
    char pad29[0x84 - 0x29];
    Texture* texture;
    char pad88[0x94 - 0x88];
    int stored94;
    unsigned char stored98;
    void FUN_0032a260();
    void vfunc_13();
};
} // namespace pure3d
extern int DAT_0039db08;
extern int DAT_0039db60;
void pure3d::d3dRefractVertexShader::vfunc_13() {
    texture->FUN_00326300(0);
    if (1 != state->mode) {
        state->mode = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039db60 = 1;
    }
    value1c = stored94;
    value28 = stored98;
    FUN_0032a260();
}
} // namespace fn_0032f280


// 0x0032f2e0 FUN_0032f2e0 (125 B): equivalent/0x0032f2e0.cpp [wrapped: conflict: pure3d::d3dRefractVertexShader]
// sym: ??0d3dRefractVertexShader@pure3d@fn_0032f2e0@@QAE@PAX@Z
namespace fn_0032f2e0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// FUN_0032f2e0 @ 0x0032f2e0
struct d3dTexture_32f2e0 { d3dTexture_32f2e0* FUN_00326110(void* owner, int flag); };
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
struct FUN_00333520 {
    virtual void dummy();
    char pad04[12];
    void* owner;
    char pad14[108];
    FUN_00333520(void* arg);
};
namespace pure3d {
struct d3dRefractVertexShader : FUN_00333520 {
    unsigned int field80;
    d3dTexture_32f2e0* resource;
    float field88;
    float field8c;
    int field90;
    virtual void dummy();
    d3dRefractVertexShader(void* arg);
};
d3dRefractVertexShader::d3dRefractVertexShader(void* arg) : FUN_00333520(arg) {
    field80 = 0;
    resource = 0;
    field88 = 10.0f;
    field8c = 1.0f;
    field90 = -1;
    d3dTexture_32f2e0* allocation = (d3dTexture_32f2e0*)FUN_0008d690(248);
    if (allocation) resource = allocation->FUN_00326110(owner, 0);
    else resource = 0;
}
}
} // namespace fn_0032f2e0

namespace fn_f721c355 {

// 0x0032f360 pure3d::d3dRefractVertexShader::vfunc_3 (68 B): matches/0x0032f360.cpp
// sym: ?vfunc_3@d3dRefractVertexShader_32f360@fn_f721c355@@UAEPAV12@I@Z
// Same code shape as 0x0032ba70 (propagated; names are from that function)
d3dRefractVertexShader_32f360* d3dRefractVertexShader_32f360::vfunc_3(unsigned int x) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32f360;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}

} // namespace fn_f721c355

// 0x0032f3b0 pure3d::d3dRefractVertexShader::vfunc_24 (1360 B): equivalent/0x0032f3b0.cpp [wrapped: conflict: pure3d::d3dRefractVertexShader]
// sym: ?vfunc_24@d3dRefractVertexShader@pure3d@fn_0032f3b0@@UAEXXZ
namespace fn_0032f3b0 {
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 26/26)
// pure3d::d3dRefractVertexShader::vfunc_24 @ 0x0032f3b0
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(int,const void*); void __fastcall D3DDevice_SetVertexShaderConstant4(int,const void*); void __stdcall D3DDevice_GetTransform(int,void*); void __stdcall D3DDevice_GetLight(int,void*); }
struct Matrix { float m[16]; void FUN_0022ca90(const Matrix*,const Matrix*); void FUN_0022cc10(const Matrix*,const Matrix*); void FUN_0022c0b0(); };
struct V { float x,y,z,w; };
// equiv-conv: FUN_0032ee30 ecx stack
void FUN_0032ee30(V*,unsigned int);
struct Material_32f3b0 { unsigned int diffuse,specular,ambient,emissive; float power; };
struct Light { unsigned int type; V diffuse,specular,ambient; float position[3]; V direction; float rest[6]; };
struct Surface_32f3b0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int v6(); virtual int v7(); char pad[0x48c]; unsigned height,width; };
struct Context { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual unsigned* v36(unsigned*); char pad[HULK_D3DCTX_PAD(f_154, 0x154, sizeof(void*))]; Surface_32f3b0* surface; void FUN_00321dc0(int*,int); };
namespace pure3d { struct d3dRefractVertexShader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(Material_32f3b0*); virtual void v22(); virtual void v23(); virtual void vfunc_24(); char pad0[12]; Context* context; char pad1[0x24]; unsigned alpha; char pad2[0x41]; unsigned char flag; char pad3[10]; float scale,intensity; }; }
void pure3d::d3dRefractVertexShader::vfunc_24() {
 struct Scratch { unsigned packed; int surfaceHeight; float height; V result; } scratch;
 float viewport[4]={640.f,480.f,1.f,1.f};
 viewport[0]=(float)context->surface->width; viewport[1]=(float)context->surface->height;
 float width=(float)context->surface->width; int sw=context->surface->v7();
 float uv[4]; uv[0]=width/sw*scale;
 scratch.height=(float)context->surface->height; scratch.surfaceHeight=context->surface->v6(); uv[1]=scratch.height/scratch.surfaceHeight*scale; uv[2]=uv[3]=0;
 float half[4]={0.5f,0.5f,0.5f,0.5f}; float one[4]={1,1,1,1};
 scratch.packed=255-alpha; intensity=(float)scratch.packed*intensity*0.003921568859368563f; one[3]=intensity-0.3f;
 if(flag) { D3D8::D3DDevice_SetVertexShaderConstant1(188,uv); D3D8::D3DDevice_SetVertexShaderConstant1(189,half); D3D8::D3DDevice_SetVertexShaderConstant1(190,viewport); D3D8::D3DDevice_SetVertexShaderConstant1(191,one); return; }
 Matrix projection,world,view,pw,pwv,inverse,invproj;
 D3D8::D3DDevice_GetTransform(6,&projection); D3D8::D3DDevice_GetTransform(0,&world); D3D8::D3DDevice_GetTransform(1,&view);
 pw.FUN_0022ca90(&projection,&world); pwv.FUN_0022cc10(&pw,&view); inverse=pwv; inverse.FUN_0022c0b0(); invproj=projection; invproj.FUN_0022c0b0();
 D3D8::D3DDevice_SetVertexShaderConstant4(0x62,&inverse); D3D8::D3DDevice_SetVertexShaderConstant4(0x66,&invproj);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,viewport); D3D8::D3DDevice_SetVertexShaderConstant1(0x6c,uv); D3D8::D3DDevice_SetVertexShaderConstant1(0x6d,half);
 int ids[4]; float coeff[4]={0,1,256,0.5f}; context->FUN_00321dc0(ids,0);
 Light lights[3]; D3D8::D3DDevice_GetLight(ids[0]==-1?0:ids[0],&lights[0]); D3D8::D3DDevice_GetLight(ids[1]==-1?0:ids[1],&lights[1]); D3D8::D3DDevice_GetLight(ids[2]==-1?0:ids[2],&lights[2]);
 Material_32f3b0 material; v21(&material); float zero[4]={0,0,0,0}; V specular,diffuse,ambient,global; V& result=scratch.result;
 FUN_0032ee30(&specular,material.specular); FUN_0032ee30(&diffuse,material.diffuse); FUN_0032ee30(&result,material.emissive); FUN_0032ee30(&ambient,material.ambient);
 unsigned* p=context->v36(&scratch.packed); FUN_0032ee30(&global,*p);
 if(result.w==0.0f) { result.w=diffuse.w; diffuse.w=0; }
 specular.w=material.power;
 result.x=global.x*ambient.x+result.x; result.y=global.y*ambient.y+result.y; result.z=global.z*ambient.z+result.z; result.w=global.w*ambient.w+result.w;
 D3D8::D3DDevice_SetVertexShaderConstant1(0x60,coeff); D3D8::D3DDevice_SetVertexShaderConstant1(0x6e,&diffuse); D3D8::D3DDevice_SetVertexShaderConstant1(0x6f,&specular); D3D8::D3DDevice_SetVertexShaderConstant1(0x70,&result);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x71,&lights[0].direction); D3D8::D3DDevice_SetVertexShaderConstant1(0x72,ids[0]==-1?(void*)zero:(void*)&lights[0].diffuse);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x73,&lights[1].direction); D3D8::D3DDevice_SetVertexShaderConstant1(0x74,ids[1]==-1?(void*)zero:(void*)&lights[1].diffuse);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x75,&lights[2].direction); D3D8::D3DDevice_SetVertexShaderConstant1(0x76,ids[2]==-1?(void*)zero:(void*)&lights[2].diffuse); D3D8::D3DDevice_SetVertexShaderConstant1(0x79,one);
}
} // namespace fn_0032f3b0

