// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00331620..0x00332260 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dSpheremapVertexShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f045d6aa {
#define TREE_TU_END }
namespace fn_f045d6aa {} using namespace fn_f045d6aa;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f045d6aa {
struct Color_331620 { float red, green, blue, alpha; };
extern "C" char DAT_00433e64[];
class Shader {
  public:
    virtual void F0();
    virtual void F1();
};
class d3dSpheremapVertexShader_331690 {
  public:
    hulk_intptr vft;
    char pad[0x7c];
    Shader* a;
    Shader* b;
    void Fn();
    void End();
};
class pddiObject_331720 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_331720 : public pddiObject_331720 {};
class pddiBaseShader_331720 : public pddiShader_331720 {
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
class d3dShader_331720 : public pddiBaseShader_331720 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
struct State_331b60 {
    char pad[0xe4];
    int value;
};
extern int globalFlags;
extern int globalState_331b60;
class Owner {
  public:
    char _m_pad_0[0x80];
    Item* item;
    Ref* p;
    void Set(Item* p);
    void Set(Ref* q);
};
class O_331bf0 {
  public:
    char pad[0x88];
    int m;
    void Set(int v);
};
struct Vec3 {
    int x, y, z;
};
struct Obj {
    char pad[0x8c];
    int a, b, c;
    void Set(Vec3 const* v);
};
class Ref_331c80 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_331c80;
class d3dSpheremapVertexShader_331c80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dSpheremapVertexShader_331c80* vfunc_3(unsigned int);
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
    Ref_331c80* a;
    Ref_331c80* b;
};
void __cdecl destroy(d3dSpheremapVertexShader_331c80*);
} // namespace fn_f045d6aa
namespace pure3d {
struct Vec4_331cd0 {
    float x;
    float y;
    float z;
    union {
        float w;
        unsigned int wBits;
    };
};
}
namespace pure3d {
void FUN_00331620(Vec4_331cd0* self, unsigned int packed);
}
namespace pure3d {
struct ShaderColors {
    unsigned int c0;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    unsigned int extra;
};
}
namespace pure3d {
struct Light_331cd0 {
    int type;
    Vec4_331cd0 diffuse;
    Vec4_331cd0 specular;
    Vec4_331cd0 ambient;
    float position[3];
    Vec4_331cd0 directionRange;
    float falloff;
    float attenuation[3];
    float theta;
    float phi;
};
}
namespace pure3d {
class LightManager_331cd0 {
  public:
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
    virtual unsigned int* v36(unsigned int* out);
    void FUN_00321dc0(int* ids, int key);
};
}
namespace fn_f045d6aa {
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, pure3d::Light_331cd0* out);
}
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const pure3d::Vec4_331cd0* data);
}


// 0x00331620 FUN_00331620 (105 B): equivalent/0x00331620.cpp
// sym: _FUN_00331620
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00331620 @ 0x00331620
// equiv-conv: FUN_00331620 ecx stack
extern "C" void __cdecl FUN_00331620(Color_331620* color, unsigned int packed) {
    color->red = (int)((packed >> 16) & 255) * 0.003921568859368563f;
    color->green = (int)((packed >> 8) & 255) * 0.003921568859368563f;
    color->blue = (int)(packed & 255) * 0.003921568859368563f;
    color->alpha = (int)(packed >> 24) * 0.003921568859368563f;
}


// 0x00331690 FUN_00331690 (47 B): matches/0x00331690.cpp
// sym: ?Fn@d3dSpheremapVertexShader_331690@fn_f045d6aa@@QAEXXZ
void d3dSpheremapVertexShader_331690::Fn() {
    Shader* x = a;
    vft = ((hulk_intptr)DAT_00433e64);
    if (x)
        x->F1();
    x = b;
    if (x)
        x->F1();
    End();
}


// 0x003316c0 pure3d::d3dSpheremapVertexShader::vfunc_15 (6 B): matches/0x003316c0.cpp
// sym: _FUN_003316c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003316c0() {
    return &(*(int*)&DAT_004d9058);
}


// 0x003316d0 pure3d::d3dSpheremapVertexShader::vfunc_16 (6 B): matches/0x003316d0.cpp
// sym: _FUN_003316d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003316d0() {
    return &(*(int*)&DAT_004d90a0);
}


// 0x003316e0 pure3d::d3dSpheremapVertexShader::vfunc_17 (6 B): matches/0x003316e0.cpp
// sym: _FUN_003316e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003316e0() {
    return &(*(int*)&DAT_004d8f68);
}


// 0x003316f0 pure3d::d3dSpheremapVertexShader::vfunc_18 (6 B): matches/0x003316f0.cpp
// sym: _FUN_003316f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003316f0() {
    return &(*(int*)&DAT_004d8fc8);
}


// 0x00331700 pure3d::d3dSpheremapVertexShader::vfunc_19 (6 B): matches/0x00331700.cpp
// sym: _FUN_00331700
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00331700() {
    return &(*(int*)&DAT_004d8f38);
}


// 0x00331710 pure3d::d3dSpheremapVertexShader::vfunc_4 (6 B): matches/0x00331710.cpp
// sym: _FUN_00331710
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00331710() {
    return &(*(int*)&DAT_004d8f18);
}

} // namespace fn_f045d6aa

// 0x00331720 pure3d::d3dSpheremapVertexShader::vfunc_11 (6 B): matches/0x00331720.cpp
// sym: ?vfunc_11@d3dSpheremapVertexShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dSpheremapVertexShader::vfunc_11() {
    return 1;
}


// 0x00331730 pure3d::d3dSpheremapVertexShader::vfunc_22 (3 B): matches/0x00331730.cpp
// sym: ?vfunc_22@d3dSpheremapVertexShader@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::d3dSpheremapVertexShader::vfunc_22() {
    return true;
}

namespace fn_f045d6aa {

// 0x00331740 pure3d::d3dSpheremapVertexShader::vfunc_23 (6 B): matches/0x00331740.cpp
// sym: _FUN_00331740
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00331740() {
    return &(*(int*)&DAT_00433634);
}

} // namespace fn_f045d6aa

// 0x00331750 pure3d::d3dSpheremapVertexShader::vfunc_24 (445 B): matches/0x00331750.cpp [wrapped: conflict: pure3d::d3dSpheremapVertexShader]
// sym: ?vfunc_24@d3dSpheremapVertexShader@pure3d@fn_00331750@@QAEXXZ
namespace fn_00331750 {
struct Mat_331750 {
    float v[16];
    void FUN_0022b980();
    void FUN_0022bc20(float, float, float);
    void FUN_0022ca90(const Mat_331750*, const Mat_331750*);
    void FUN_0022cc10(const Mat_331750*, const Mat_331750*);
    void FUN_0022c0b0();
    void FUN_0022cdb0();
    void FUN_0022c310(const float*, float*);
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int, Mat_331750*);
void __fastcall D3DDevice_SetVertexShaderConstant4(int, const Mat_331750*);
void __fastcall D3DDevice_SetVertexShaderConstant1(int, const float*);
} // namespace D3D8
namespace pure3d {
struct d3dSpheremapVertexShader {
    char pad[0x8c];
    float x, y, z;
    void vfunc_24();
};
void d3dSpheremapVertexShader::vfunc_24() {
    Mat_331750 projection, view, world, base, combined, temp, light, normal, transposedLight, transposedCombined,
        transposedProjection, transposedBase;
    float in[4], out[4];
    D3D8::D3DDevice_GetTransform(6, &projection);
    D3D8::D3DDevice_GetTransform(0, &view);
    D3D8::D3DDevice_GetTransform(1, &world);
    base.FUN_0022b980();
    base.FUN_0022bc20(x, y, z);
    combined.FUN_0022ca90(&projection, &view);
    temp.FUN_0022cc10(&combined, &world);
    light = temp;
    light.FUN_0022c0b0();
    transposedCombined = combined;
    transposedCombined.FUN_0022c0b0();
    transposedProjection = projection;
    transposedProjection.FUN_0022c0b0();
    normal = combined;
    normal.FUN_0022cdb0();
    transposedBase = base;
    transposedBase.FUN_0022c0b0();
    in[0] = 0;
    in[1] = 0;
    in[2] = 0;
    in[3] = 1.0f;
    normal.FUN_0022c310(in, out);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &light);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x66, &transposedCombined);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x77, &transposedProjection);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x7b, out);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x7c, &transposedBase);
}
} // namespace pure3d
} // namespace fn_00331750


// 0x00331910 pure3d::d3dSpheremapVertexShader::vfunc_14 (589 B): equivalent/0x00331910.cpp [wrapped: compile error C2668: 'fn_f045d6aa::D3D8::D3DDevice_SetPalette' : ambiguous call to overloaded function]
// sym: ?vfunc_14@d3dSpheremapVertexShader@pure3d_331910@fn_00331910@@QAEXI@Z
namespace fn_00331910 {
// STATUS: equivalent (tools/equiv.py level 3: 2941 inputs, branch coverage 24/24)
// pure3d::d3dSpheremapVertexShader::vfunc_14 @ 0x00331910

typedef unsigned int U_331910;
extern U_331910 DAT_0039db08,DAT_0039db10,DAT_0039db14,DAT_0039db18,DAT_0039db60,DAT_0039db90,DAT_0039db94,DAT_0039db98,DAT_0039dbcc,DAT_0039dc4c,DAT_0039dc5c,DAT_0039de18;
 
namespace D3D8 { void __stdcall D3DDevice_SetRenderState_TextureFactor(U_331910); void __stdcall D3DDevice_SetTexture(U_331910,U_331910); void __stdcall D3DDevice_SetPalette(U_331910,U_331910); void __fastcall D3DDevice_SetRenderState_Simple(U_331910,U_331910); }
struct Texture {  };
struct Device_331910 {
 char p0[8]; hulk_uintptr tex0,tex1; char p10[0x18]; U_331910 mode0,mode1; char p30[0x18]; U_331910 renderMode; char p4c[0x4c]; U_331910 stage0; U_331910 stage1; char pa0[0x2c]; U_331910 stage2; char pd0[0x14]; U_331910 stateE4; char pe8[0x20]; U_331910 factor;
 void FUN_00329f70(U_331910,U_331910,void*);
};
struct pure3d_331910 { struct d3dSpheremapVertexShader {
 char pad0[0x14]; Device_331910 *device; char pad18[0x20]; U_331910 alpha; char pad3c[4]; U_331910 mode; U_331910 setting; unsigned char flag; char pad49[3]; U_331910 renderMode; char pad50[0x2c]; unsigned char flag2; char pad7d[3]; Texture* tex0; Texture* tex1; U_331910 color;
 void FUN_0032a320(U_331910,U_331910); void FUN_0032a260(); void vfunc_14(U_331910);
 };};
void pure3d_331910::d3dSpheremapVertexShader::vfunc_14(U_331910 unused) {
 U_331910 ec=color, a=alpha;
 U_331910 factor=(((0xff-a)*(ec >> 8 & 0xffff0000) ^ ec) & 0xffffff) ^ ((0xff-a)*(ec >> 8 & 0xff0000));
 Device_331910 *d=device;
 if(d->factor!=factor) {d->factor=factor; D3D8::D3DDevice_SetRenderState_TextureFactor(factor);}
 ((owners::Obj_329e50 *)device)->FUN_00329e50(0, 4, 0, 2);
 d=device;
 if(d->mode0!=mode){d->mode0=mode; U_331910 v=((U_331910*)&DAT_004d4efc)[mode]; DAT_0039db10=v; DAT_0039db14=v; DAT_0039db08|=1; DAT_0039db18=v;}
 d=device;
 if(d->stateE4!=5){d->stateE4=5; DAT_0039db08|=0x800; DAT_0039db60=5;}
 d=device;
 if(d->tex0!=(hulk_uintptr)tex0){Texture* t=tex0; d->tex0=(hulk_uintptr)t; if(t) ((owners::Obj_326b00 *)t)->FUN_00326b00(0); else {D3D8::D3DDevice_SetTexture(0,0); D3D8::D3DDevice_SetPalette(0,0);}}
 FUN_0032a320(0,0);
 d=device; ((owners::C_329cf0 *)d)->FUN_00329cf0(1, 4, 3);
 if(d->stage0!=2){d->stage0=2; DAT_0039db08|=0x800; DAT_0039dbcc=2;}
 d=device;
 if(d->mode1!=1){d->mode1=1; U_331910 v=((U_331910*)&DAT_004d4efc)[1]; DAT_0039db90=v; DAT_0039db94=v; DAT_0039db08|=2; DAT_0039db98=v;}
 ((owners::Obj_329c90 *)device)->FUN_00329c90(1, (int)setting);
 d=device;
 if(d->tex1!=(hulk_uintptr)tex1){Texture* t=tex1; d->tex1=(hulk_uintptr)t; if(t) ((owners::Obj_326b00 *)t)->FUN_00326b00(1); else {D3D8::D3DDevice_SetTexture(1,0); D3D8::D3DDevice_SetPalette(1,0);}}
 d=device; ((owners::C_329cf0 *)d)->FUN_00329cf0(2, 0x12, 5);
 if(d->stage1!=1){d->stage1=1; DAT_0039db08|=0x800; DAT_0039dc4c=1;}
 d=device; ((owners::C_329da0 *)d)->FUN_00329da0(2, 4, 1);
 if(d->stage2!=5){d->stage2=5; DAT_0039db08|=0x800; DAT_0039dc5c=5;}
 ((owners::State_329bb0 *)device)->FUN_00329bb0(3);
 d=device;
 if(d->renderMode!=renderMode){d->renderMode=renderMode; U_331910 v=((U_331910*)&DAT_004d4f24)[renderMode]; D3D8::D3DDevice_SetRenderState_Simple(0x4037c,v); DAT_0039de18=v;}
 device->FUN_00329f70(flag,flag2,&pad50);
 FUN_0032a260();
}
} // namespace fn_00331910


// 0x00331b60 pure3d::d3dSpheremapVertexShader::vfunc_13 (41 B): matches/0x00331b60.cpp
// sym: ?vfunc_13@d3dSpheremapVertexShader@pure3d@@UAEXXZ
void pure3d::d3dSpheremapVertexShader::vfunc_13() {
    if ((*(struct State_331b60 * *)&this->f_14)->value != 1) {
        (*(struct State_331b60 * *)&this->f_14)->value = 1;
        globalFlags |= 0x800;
        globalState_331b60 = 1;
    }
}

namespace fn_f045d6aa {

// 0x00331b90 FUN_00331b90 (44 B): matches/0x00331b90.cpp
// sym: ?Set@Owner@fn_f045d6aa@@QAEXPAVItem@2@@Z
void Owner::Set(Item* p) {
    if (p)
        p->AddRef();
    if (item)
        item->Release();
    item = p;
}


// 0x00331bc0 FUN_00331bc0 (44 B): matches/0x00331bc0.cpp
// sym: ?Set@Owner@fn_f045d6aa@@QAEXPAVRef@2@@Z
void Owner::Set(Ref* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}


// 0x00331bf0 FUN_00331bf0 (13 B): matches/0x00331bf0.cpp
// sym: ?Set@O_331bf0@fn_f045d6aa@@QAEXH@Z
void O_331bf0::Set(int v) {
    m = v;
}


// 0x00331c00 FUN_00331c00 (33 B): matches/0x00331c00.cpp
// sym: ?Set@Obj@fn_f045d6aa@@QAEXPBUVec3@2@@Z
void Obj::Set(Vec3 const* v) {
    a = v->x;
    b = v->y;
    c = v->z;
}

} // namespace fn_f045d6aa

// 0x00331c30 FUN_00331c30 (67 B): equivalent/0x00331c30.cpp [wrapped: conflict: pure3d::d3dSpheremapVertexShader]
// sym: ??0d3dSpheremapVertexShader@pure3d@fn_00331c30@@QAE@I@Z
namespace fn_00331c30 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00331c30 @ 0x00331c30
namespace pure3d {
struct Base_331c30 {
    virtual void dummy();
    char padding[0x7c];
    Base_331c30(unsigned int);
};
struct d3dSpheremapVertexShader : Base_331c30 {
    unsigned int field80, field84, color, field8c, field90, field94;
    virtual void dummy();
    d3dSpheremapVertexShader(unsigned int);
};
}
// Base constructor address: FUN_00333520
namespace pure3d {
d3dSpheremapVertexShader::d3dSpheremapVertexShader(unsigned int arg) : Base_331c30(arg) {
    field80 = 0;
    field84 = 0;
    color = 0x80808080;
    field8c = 0;
    field90 = 0;
    field94 = 0;
}
}
} // namespace fn_00331c30

namespace fn_f045d6aa {

// 0x00331c80 pure3d::d3dSpheremapVertexShader::vfunc_3 (68 B): matches/0x00331c80.cpp
// sym: ?vfunc_3@d3dSpheremapVertexShader_331c80@fn_f045d6aa@@UAEPAV12@I@Z
// Same code shape as 0x0032ba70 (propagated; names are from that function)
d3dSpheremapVertexShader_331c80* d3dSpheremapVertexShader_331c80::vfunc_3(unsigned int x) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_331c80;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}

} // namespace fn_f045d6aa

// 0x00331cd0 pure3d::d3dSpheremapVertexShader::vfunc_12 (659 B): equivalent/0x00331cd0.cpp
// sym: ?vfunc_12@d3dSpheremapVertexShader@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 14/14)
// pure3d::d3dSpheremapVertexShader::vfunc_12 @ 0x00331cd0
// pure3d::d3dSpheremapVertexShader::vfunc_12 @ 0x00331cd0
// equiv-conv: FUN_00331620 ecx stack
void pure3d::d3dSpheremapVertexShader::vfunc_12() {
    int ids[4];
    Vec4_331cd0 constA, constB, zero, out1, out2, out3, out4, out5;
    ShaderColors colors;
    unsigned int scratch;
    Light_331cd0 light0, light1, light2;

    constA.x = 0.0f;
    constA.y = 1.0f;
    constA.z = 0.5f;
    constA.w = 2.0f;
    constB.x = 0.0f;
    constB.y = 0.0f;
    constB.z = 1.0f;
    constB.w = 0.0f;
    (*(LightManager_331cd0 * *)&this->f_10)->FUN_00321dc0(ids, 0);
    D3D8::D3DDevice_GetLight(ids[0] == -1 ? 0 : ids[0], &light0);
    D3D8::D3DDevice_GetLight(ids[1] == -1 ? 0 : ids[1], &light1);
    D3D8::D3DDevice_GetLight(ids[2] == -1 ? 0 : ids[2], &light2);
    vfunc_21(&colors);
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    FUN_00331620(&out1, colors.c1);
    FUN_00331620(&out2, colors.c0);
    FUN_00331620(&out3, colors.c3);
    FUN_00331620(&out4, colors.c2);
    FUN_00331620(&out5, *(*(LightManager_331cd0 * *)&this->f_10)->v36(&scratch));
    if (out3.w == 0.0f) {
        out3.wBits = out2.wBits;
        out2.wBits = 0;
    }
    out1.wBits = colors.extra;
    out3.x = out5.x * out4.x + out3.x;
    out3.y = out5.y * out4.y + out3.y;
    out3.z = out5.z * out4.z + out3.z;
    out3.w = out5.w * out4.w + out3.w;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &constA);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x61, &constB);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6e, &out2);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6f, &out1);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, &out3);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, &light0.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, ids[0] != -1 ? &light0.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x73, &light1.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x74, ids[1] != -1 ? &light1.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x75, &light2.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x76, ids[2] != -1 ? &light2.diffuse : &zero);
}

