// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032d0f0..0x0032d8d0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dPointSpriteShader
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f3432927 {
#define TREE_TU_END }
namespace fn_f3432927 {} using namespace fn_f3432927;
namespace fn_f3432927 { extern "C" char DAT_00433b14[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f3432927 {
class Ref_32d0f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class d3dShader_32d0f0 {
  public:
    void* vptr;
    void Fin();
};
class d3dPointSpriteShader_32d0f0 : public d3dShader_32d0f0 {
  public:
    char pad[0x80 - 4];
    Ref_32d0f0* m80;
    ~d3dPointSpriteShader_32d0f0() throw();
};
class pddiObject_32d150 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32d150 : public pddiObject_32d150 {};
class pddiBaseShader_32d150 : public pddiShader_32d150 {
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
class d3dShader_32d150 : public pddiBaseShader_32d150 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Owner {
    char pad[0x80];
    Item* item;

  public:
    void Set(Item* p);
};
class Obj_32d290 {
  public:
    char pad[0x84];
    bool mValid;
    void Set(void* p);
};
class Obj_32d2b0 {
  public:
    char pad[0x88];
    int mVal;
    void Set(int v);
};
class X_32d2c0 {
  public:
    char pad[0x8c];
    int m;
    void Set(int v);
};
class C_32d2d0 {
  public:
    char pad[0x90];
    int field;
    void Set(int value);
};
class Obj_32d2e0 {
  public:
    char pad[0x94];
    int value;
    void Set(int x);
};
class Obj_32d2f0 {
  public:
    char pad[0x98];
    int mVal;
    void Set(int v);
};
struct X_32d300 {
    char pad[0x9c];
    int mValue;
    void Set(int v);
};
class Target_32d310 {
  public:
    char pad[0xa0];
    int value;
    void Set(int x);
};
typedef unsigned char u8_32d390;
struct Ref_32d390 {
    virtual void f0();
    virtual void f1();
};
struct d3dPointSpriteShader_nv_32d390 {
    void run();
};
extern "C" char DAT_00433b14[];
struct d3dPointSpriteShader_32d390 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual d3dPointSpriteShader_32d390* vfunc_3(u8_32d390);
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    char pad[0x80 - sizeof(void*)];
    Ref_32d390* member;
};
struct Texture_32d3d0 {
};
struct Context_32d3d0 {
    CullState* cull;
    char pad04[4];
    Texture_32d3d0* tex0;
    Texture_32d3d0* tex1;
    Texture_32d3d0* tex2;
    Texture_32d3d0* tex3;
    char pad18[0x104 - 0x18];
    unsigned char lit;
    unsigned char twoSided;
};
extern void __stdcall D3DDevice_SetTexture(int stage, Texture_32d3d0* tex);
extern void __stdcall D3DDevice_SetPalette(int stage, void* palette);
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039dee0;
extern unsigned int DAT_0039dee4;
extern unsigned int DAT_0039dee8;
extern unsigned int DAT_0039deec;
extern unsigned int DAT_0039def0;
extern unsigned int DAT_0039def4;
extern unsigned int DAT_0039def8;
extern unsigned int DAT_0039defc;
} // namespace fn_f3432927
namespace pure3d {
struct d3dPointSpriteShader_nv_32d3d0 {
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
};
}

namespace fn_f3432927 {

// 0x0032d0f0 FUN_0032d0f0 (32 B): matches/0x0032d0f0.cpp
// sym: ??1d3dPointSpriteShader_32d0f0@fn_f3432927@@QAE@XZ
d3dPointSpriteShader_32d0f0::~d3dPointSpriteShader_32d0f0() throw() {
    Ref_32d0f0* a = m80;
    vptr = (void**)DAT_00433b14;
    if (a)
        a->Release();
    Fin();
}


// 0x0032d110 pure3d::d3dPointSpriteShader::vfunc_15 (6 B): matches/0x0032d110.cpp
// sym: _FUN_0032d110
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d110() {
    return &(*(int*)&DAT_004d83a0);
}


// 0x0032d120 pure3d::d3dPointSpriteShader::vfunc_16 (6 B): matches/0x0032d120.cpp
// sym: _FUN_0032d120
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d120() {
    return &(*(int*)&DAT_004d8328);
}


// 0x0032d130 pure3d::d3dPointSpriteShader::vfunc_17 (6 B): matches/0x0032d130.cpp
// sym: _FUN_0032d130
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d130() {
    return &(*(int*)&DAT_004d83d0);
}


// 0x0032d140 pure3d::d3dPointSpriteShader::vfunc_4 (6 B): matches/0x0032d140.cpp
// sym: _FUN_0032d140
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d140() {
    return &(*(int*)&DAT_004d830c);
}

} // namespace fn_f3432927

// 0x0032d150 pure3d::d3dPointSpriteShader::vfunc_11 (6 B): matches/0x0032d150.cpp
// sym: ?vfunc_11@d3dPointSpriteShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dPointSpriteShader::vfunc_11() {
    return 1;
}


// 0x0032d160 pure3d::d3dPointSpriteShader::vfunc_12 (208 B): matches/0x0032d160.cpp [wrapped: conflict: pure3d::d3dPointSpriteShader; pure3d::d3dShader; pure3d::pddiObject]
// sym: ?vfunc_12@d3dPointSpriteShader@pure3d@fn_0032d160@@UAEXXZ
namespace fn_0032d160 {
namespace pure3d {
struct Matrix4_32d160 {
    float m[16];
    void FUN_0022ca90(const Matrix4_32d160* a, const Matrix4_32d160* b);
    void FUN_0022c0b0();
};
class pddiObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class d3dShader {
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
    char pad[0xa0 - 4];
    float field_a0;
};
class d3dPointSpriteShader : public d3dShader {
  public:
    virtual void vfunc_13();
    void vfunc_12();
};
} // namespace pure3d
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix4_32d160* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
} // namespace D3D8
void pure3d::d3dPointSpriteShader::vfunc_12() {
    Matrix4_32d160 m6, m1, m0, t0, t1, out;
    float consts[4];
    d3dShader::vfunc_12();
    consts[0] = 0.0f;
    consts[1] = 1.0f;
    consts[2] = 255.0f;
    consts[3] = field_a0;
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    t0.FUN_0022ca90(&m6, &m0);
    t1.FUN_0022ca90(&t0, &m1);
    out = t1;
    out.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, consts);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &out);
}
} // namespace fn_0032d160


// 0x0032d230 pure3d::d3dPointSpriteShader::vfunc_13 (36 B): matches/0x0032d230.cpp [wrapped: conflict: pure3d::d3dPointSpriteShader; pure3d::d3dShader; pure3d::gA; pure3d::gB (+1)]
// sym: ?vfunc_13@d3dPointSpriteShader@pure3d@fn_0032d230@@UAEXXZ
namespace fn_0032d230 {
typedef unsigned int u32_32d230;
namespace pure3d {
class d3dShader {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void vfunc_13();
};
extern u32_32d230 gFlags;
extern u32_32d230 gA;
extern u32_32d230 gB;
class d3dPointSpriteShader : public d3dShader {
  public:
    virtual void b14();
    void vfunc_13();
};
} // namespace pure3d
u32_32d230 pure3d::gFlags;
u32_32d230 pure3d::gA;
u32_32d230 pure3d::gB;
void pure3d::d3dPointSpriteShader::vfunc_13() {
    d3dShader::vfunc_13();
    gA = 0;
    gFlags |= 0x900;
    gB = 0;
}
} // namespace fn_0032d230

namespace fn_f3432927 {

// 0x0032d260 FUN_0032d260 (44 B): matches/0x0032d260.cpp
// sym: ?Set@Owner@fn_f3432927@@QAEXPAVItem@2@@Z
void Owner::Set(Item* p) {
    if (p)
        p->AddRef();
    if (item)
        item->Release();
    item = p;
}


// 0x0032d290 FUN_0032d290 (18 B): matches/0x0032d290.cpp
// sym: ?Set@Obj_32d290@fn_f3432927@@QAEXPAX@Z
void Obj_32d290::Set(void* p) {
    mValid = (p != 0);
}


// 0x0032d2b0 FUN_0032d2b0 (13 B): matches/0x0032d2b0.cpp
// sym: ?Set@Obj_32d2b0@fn_f3432927@@QAEXH@Z
void Obj_32d2b0::Set(int v) {
    mVal = v;
}


// 0x0032d2c0 FUN_0032d2c0 (13 B): matches/0x0032d2c0.cpp
// sym: ?Set@X_32d2c0@fn_f3432927@@QAEXH@Z
void X_32d2c0::Set(int v) {
    m = v;
}


// 0x0032d2d0 FUN_0032d2d0 (13 B): matches/0x0032d2d0.cpp
// sym: ?Set@C_32d2d0@fn_f3432927@@QAEXH@Z
void C_32d2d0::Set(int value) {
    field = value;
}


// 0x0032d2e0 FUN_0032d2e0 (13 B): matches/0x0032d2e0.cpp
// sym: ?Set@Obj_32d2e0@fn_f3432927@@QAEXH@Z
void Obj_32d2e0::Set(int x) {
    value = x;
}


// 0x0032d2f0 FUN_0032d2f0 (13 B): matches/0x0032d2f0.cpp
// sym: ?Set@Obj_32d2f0@fn_f3432927@@QAEXH@Z
void Obj_32d2f0::Set(int v) {
    mVal = v;
}


// 0x0032d300 FUN_0032d300 (13 B): matches/0x0032d300.cpp
// sym: ?Set@X_32d300@fn_f3432927@@QAEXH@Z
void X_32d300::Set(int v) {
    mValue = v;
}


// 0x0032d310 FUN_0032d310 (13 B): matches/0x0032d310.cpp
// sym: ?Set@Target_32d310@fn_f3432927@@QAEXH@Z
void Target_32d310::Set(int x) {
    value = x;
}

} // namespace fn_f3432927

// 0x0032d320 FUN_0032d320 (102 B): matches/0x0032d320.cpp [wrapped: conflict: pure3d::d3dPointSpriteShader]
// sym: ??0d3dPointSpriteShader@pure3d@fn_0032d320@@QAE@PAX@Z
namespace fn_0032d320 {
namespace pure3d {
class Base_32d320 {
  public:
    Base_32d320(void* a);
    virtual void f();
    char pad[0x3c];
    int m40;
    char p[0x3c];
};
class d3dPointSpriteShader : public Base_32d320 {
  public:
    d3dPointSpriteShader(void* a);
    virtual void f();
    int m80;
    unsigned char m84;
    int m88, m8c, m90, m94, m98, m9c, ma0;
};
d3dPointSpriteShader::d3dPointSpriteShader(void* a) : Base_32d320(a) {
    m80 = 0;
    m84 = 1;
    m88 = 0x3f800000;
    m8c = 0;
    m90 = 0x42c80000;
    m94 = 0x3f800000;
    m98 = 0;
    m9c = 0;
    ma0 = 0x41a00000;
    m40 = 1;
}
} // namespace pure3d
} // namespace fn_0032d320

namespace fn_f3432927 {

// 0x0032d390 pure3d::d3dPointSpriteShader::vfunc_3 (53 B): matches/0x0032d390.cpp
// sym: ?vfunc_3@d3dPointSpriteShader_32d390@fn_f3432927@@UAEPAU12@E@Z
// Same code shape as 0x0032aa30 (propagated; names are from that function)
d3dPointSpriteShader_32d390* d3dPointSpriteShader_32d390::vfunc_3(u8_32d390 destroy) {
    *(int**)this = (int*)DAT_00433b14;
    if (member)
        member->f1();
    ((d3dPointSpriteShader_nv_32d390*)(((pure3d::d3dPointSpriteShader*)(((pure3d::d3dPointSpriteShader*)this)))))->run();
    if (destroy & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f3432927

// 0x0032d3d0 pure3d::d3dPointSpriteShader::vfunc_14 (471 B): equivalent/0x0032d3d0.cpp
// sym: ?vfunc_14@d3dPointSpriteShader@pure3d@@UAEXH@Z @7aa416c23251 @we63e21dbec94
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// pure3d::d3dPointSpriteShader::vfunc_14 @ 0x0032d3d0
void pure3d::d3dPointSpriteShader::vfunc_14(int unused) {
    DAT_0039db08 = DAT_0039db08 | 0x900;
    DAT_0039dee8 = 1;
    DAT_0039deec = (*(unsigned char *)&this->f_84);
    DAT_0039dee0 = (*(unsigned int *)&this->f_88);
    DAT_0039dee4 = (*(unsigned int *)&this->f_8c);
    DAT_0039defc = (*(unsigned int *)&this->f_90);
    DAT_0039def0 = (*(unsigned int *)&this->f_94);
    DAT_0039def4 = (*(unsigned int *)&this->f_98);
    DAT_0039def8 = (*(unsigned int *)&this->f_9c);
    Context_32d3d0* c = (*(Context_32d3d0 * *)&this->f_14);
    Texture_32d3d0* tex = (*(Texture_32d3d0 * *)&this->f_80);
    if (c->tex0) {
        c->tex0 = 0;
        D3DDevice_SetTexture(0, 0);
        D3DDevice_SetPalette(0, 0);
    }
    if (c->tex1) {
        c->tex1 = 0;
        D3DDevice_SetTexture(1, 0);
        D3DDevice_SetPalette(1, 0);
    }
    if (c->tex2) {
        c->tex2 = 0;
        D3DDevice_SetTexture(2, 0);
        D3DDevice_SetPalette(2, 0);
    }
    if (tex != c->tex3) {
        c->tex3 = tex;
        if (tex) {
            ((owners::Obj_326b00 *)tex)->FUN_00326b00(3);
        } else {
            D3DDevice_SetTexture(3, 0);
            D3DDevice_SetPalette(3, 0);
        }
    }
    ((d3dPointSpriteShader_nv_32d3d0*)this)->FUN_0032a320(3, 0);
    ((owners::Obj_329e50 *)((*(Context_32d3d0 * *)&this->f_14)))->FUN_00329e50(3, 4, 0, 2);
    ((owners::Obj_329e50 *)((*(Context_32d3d0 * *)&this->f_14)))->FUN_00329e50(0, 4, 0, 2);
    ((owners::Obj_329e50 *)((*(Context_32d3d0 * *)&this->f_14)))->FUN_00329e50(1, 4, 0, 2);
    ((owners::Obj_329e50 *)((*(Context_32d3d0 * *)&this->f_14)))->FUN_00329e50(2, 4, 0, 2);
    c = (*(Context_32d3d0 * *)&this->f_14);
    if (c->twoSided || c->lit) {
        c->twoSided = 0;
        D3DDevice_SetRenderState_TwoSidedLighting(0);
        c->cull->FUN_003219c0();
        if (c->lit) {
            c->lit = 0;
            DAT_0039db08 = DAT_0039db08 | 0x3200;
            DAT_0039dea8 = 0;
            DAT_0039deac = 0;
        }
    }
    ((d3dPointSpriteShader_nv_32d3d0*)this)->FUN_0032a260();
}

