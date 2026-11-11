// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00332ba0..0x00333370 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dBumpMapVertexShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fad033e0 {
#define TREE_TU_END }
namespace fn_fad033e0 {} using namespace fn_fad033e0;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fad033e0 {
class Obj_332ba0 {
  public:
    char pad[0x88];
    void Set(int value);
};
extern "C" char DAT_00433f74[];
struct I_332bb0 {
    virtual void f();
    virtual void Release();
};
struct d3dBumpMapVertexShader_nv_332bb0 {
    void common();
};
class pddiObject_332c30 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_332c30 : public pddiObject_332c30 {};
class pddiBaseShader_332c30 : public pddiShader_332c30 {
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
class d3dShader_332c30 : public pddiBaseShader_332c30 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(unsigned, void*);
}
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned, void*);
}
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(unsigned, const void*);
}
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant4(unsigned, const void*);
}
struct Matrix_332c60 { float v[16];     void FUN_0022c310(const float*, float*); };
struct Light_332c60 { char pad[64]; float direction[3]; char rest[196]; };
struct LightSource_332c60 { void FUN_00321dc0(int*,int); };
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Holder {
    char pad[0x84];
    Obj* p;

  public:
    void Set(Obj* q);
};
struct Light8_332ec0 {
    unsigned int type;
    Color4 diffuse;
    Color4 specular;
    Color4 ambient;
    float position[3];
    float direction[3];
    float range;
    float falloff;
    float attenuation0, attenuation1, attenuation2;
    float theta, phi;
};
struct Context_332ec0 {
    char pad[0x110];
    unsigned int pixelShader;
};
struct LightQuery {
    int index;
    int extra[3];
};
struct LightSource_332ec0 {
    void FUN_00321dc0(LightQuery* out, int flags);
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(unsigned int index, Light8_332ec0* out);
}
namespace D3D8 {
void __stdcall D3DDevice_SetPixelShaderConstant(unsigned int reg, const float* data, unsigned int count);
}
namespace D3D8 {
void __stdcall D3DDevice_SetPixelShader(unsigned int handle);
}
struct Device_333110 {
    char pad[0x110];
    int pixelShader;
};
void __stdcall D3DDevice_SetPixelShader(unsigned int);
struct d3dBumpMapVertexShader_nv_333130 {
    void Init(int);
};
struct d3dBumpMapVertexShader_333130 {
    unsigned int* vptr;
    char pad[0x7c];
    unsigned int a, b, c;
    d3dBumpMapVertexShader_333130* Make(int);
};
extern unsigned int vtblBump;
void __stdcall CreatePixelShader(const float* src, unsigned int* out);
typedef unsigned char byte_333170;
struct Ref_333170 {
    virtual void f0();
    virtual void f1();
};
struct d3dBumpMapVertexShader_333170 {
    void* vf;
    char pad[0x7c];
    Ref_333170* m80;
    Ref_333170* m84;
    void FUN_00327930();
    d3dBumpMapVertexShader_333170* vfunc_3(byte_333170);
};
void thunk_FUN_00267090(d3dBumpMapVertexShader_333170*);


// 0x00332ba0 FUN_00332ba0 (13 B): matches/0x00332ba0.cpp
// sym: ?Set@Obj_332ba0@fn_fad033e0@@QAEXH@Z
void Obj_332ba0::Set(int value) {
    *(int*)((char*)this + 0x88) = value;
}

} // namespace fn_fad033e0

// 0x00332bb0 FUN_00332bb0 (47 B): matches/0x00332bb0.cpp
// sym: ?FUN_00332bb0@d3dBumpMapVertexShader@pure3d@@QAEXXZ
void pure3d::d3dBumpMapVertexShader::FUN_00332bb0() {
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_00433f74);
    if ((*(I_332bb0 * *)&this->f_84))
        (*(I_332bb0 * *)&this->f_84)->Release();
    if ((*(I_332bb0 * *)&this->f_80))
        (*(I_332bb0 * *)&this->f_80)->Release();
    ((d3dBumpMapVertexShader_nv_332bb0*)this)->common();
}

namespace fn_fad033e0 {

// 0x00332be0 pure3d::d3dBumpMapVertexShader::vfunc_15 (6 B): matches/0x00332be0.cpp
// sym: _FUN_00332be0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332be0() {
    return &(*(int*)&DAT_004d9658);
}


// 0x00332bf0 pure3d::d3dBumpMapVertexShader::vfunc_16 (6 B): matches/0x00332bf0.cpp
// sym: _FUN_00332bf0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332bf0() {
    return &(*(int*)&DAT_004d9568);
}


// 0x00332c00 pure3d::d3dBumpMapVertexShader::vfunc_17 (6 B): matches/0x00332c00.cpp
// sym: _FUN_00332c00
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332c00() {
    return &(*(int*)&DAT_004d96a0);
}


// 0x00332c10 pure3d::d3dBumpMapVertexShader::vfunc_18 (6 B): matches/0x00332c10.cpp
// sym: _FUN_00332c10
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332c10() {
    return &(*(int*)&DAT_004d94f0);
}


// 0x00332c20 pure3d::d3dBumpMapVertexShader::vfunc_4 (6 B): matches/0x00332c20.cpp
// sym: _FUN_00332c20
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332c20() {
    return &(*(int*)&DAT_004d972c);
}

} // namespace fn_fad033e0

// 0x00332c30 pure3d::d3dBumpMapVertexShader::vfunc_11 (6 B): matches/0x00332c30.cpp
// sym: ?vfunc_11@d3dBumpMapVertexShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dBumpMapVertexShader::vfunc_11() {
    return 1;
}


// 0x00332c40 pure3d::d3dBumpMapVertexShader::vfunc_22 (3 B): matches/0x00332c40.cpp
// sym: ?vfunc_22@d3dBumpMapVertexShader@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::d3dBumpMapVertexShader::vfunc_22() {
    return true;
}

namespace fn_fad033e0 {

// 0x00332c50 pure3d::d3dBumpMapVertexShader::vfunc_23 (6 B): matches/0x00332c50.cpp
// sym: _FUN_00332c50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332c50() {
    return &(*(int*)&DAT_0043362c);
}

} // namespace fn_fad033e0

// 0x00332c60 pure3d::d3dBumpMapVertexShader::vfunc_24 (509 B): equivalent/0x00332c60.cpp
// sym: ?vfunc_24@d3dBumpMapVertexShader@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// pure3d::d3dBumpMapVertexShader::vfunc_24 @ 0x00332c60
void pure3d::d3dBumpMapVertexShader::vfunc_24() {
 struct Constants { float zero[4]; float direction[4]; float origin[4]; int index; char padding[12]; float out2[4]; float out1[4]; } constants;
 constants.zero[0]=constants.zero[1]=constants.zero[2]=constants.zero[3]=0;
 (*(LightSource_332c60 * *)&this->f_10)->FUN_00321dc0(&constants.index,0);
 Light_332c60 light;
 D3D8::D3DDevice_GetLight(constants.index == -1 ? 0 : constants.index,&light);
 Matrix_332c60 projection, world, view;
 D3D8::D3DDevice_GetTransform(6,&projection);
 D3D8::D3DDevice_GetTransform(0,&world);
 D3D8::D3DDevice_GetTransform(1,&view);
 Matrix_332c60 combined, result;
 ((owners::Matrix_22ca90 *)&combined)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix_332c60 *)(&projection), (const owners::Matrix_22ca90 *)(const Matrix_332c60 *)(&world));
 ((owners::Matrix_22cc10 *)&result)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix_332c60 *)(&combined), (const owners::Matrix_22cc10 *)(const Matrix_332c60 *)(&view));
 Matrix_332c60 inverse=result;
 ((owners::M_22c0b0 *)&inverse)->FUN_0022c0b0();
 Matrix_332c60 proj2=projection;
 ((owners::M_22c0b0 *)&proj2)->FUN_0022c0b0();
 Matrix_332c60 normal=combined;
 ((owners::Matrix_22cdb0 *)&normal)->FUN_0022cdb0();
 Matrix_332c60 proj3=projection;
 ((owners::Matrix_22cdb0 *)&proj3)->FUN_0022cdb0();
 constants.direction[0]=-light.direction[0]; constants.direction[1]=-light.direction[1]; constants.direction[2]=-light.direction[2]; constants.direction[3]=0;
 constants.origin[0]=0; constants.origin[1]=0; constants.origin[2]=0; constants.origin[3]=1;
 normal.FUN_0022c310(constants.origin,constants.out1);
 normal.FUN_0022c310(constants.direction,constants.out2);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x75,constants.index == -1 ? constants.zero : constants.out2);
 D3D8::D3DDevice_SetVertexShaderConstant4(0x62,&inverse);
 D3D8::D3DDevice_SetVertexShaderConstant4(0x6d,&proj2);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x78,constants.out1);
}

namespace fn_fad033e0 {

// 0x00332e60 FUN_00332e60 (44 B): matches/0x00332e60.cpp
// sym: ?Set@Holder@fn_fad033e0@@QAEXPAVObj@2@@Z
void Holder::Set(Obj* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}

} // namespace fn_fad033e0

// 0x00332e90 FUN_00332e90 (44 B): matches/0x00332e90.cpp [wrapped: same definition as 0x00332e60 in this TU]
// sym: ?Set@Holder@fn_00332e90@@QAEXPAVObj@2@@Z
namespace fn_00332e90 {
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Holder {
    char pad[0x80];
    Obj* obj;

  public:
    void Set(Obj* p);
};
void Holder::Set(Obj* p) {
    if (p)
        p->AddRef();
    if (obj)
        obj->Release();
    obj = p;
}
} // namespace fn_00332e90


// 0x00332ec0 pure3d::d3dBumpMapVertexShader::vfunc_12 (580 B): equivalent/0x00332ec0.cpp
// sym: ?vfunc_12@d3dBumpMapVertexShader@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// pure3d::d3dBumpMapVertexShader::vfunc_12 @ 0x00332ec0
void pure3d::d3dBumpMapVertexShader::vfunc_12() {
    Context_332ec0* c = (*(Context_332ec0 * *)&this->f_14);
    unsigned int shader = (*(unsigned int *)&this->f_8c);
    if (c->pixelShader != shader) {
        c->pixelShader = shader;
        D3D8::D3DDevice_SetPixelShader(shader);
    }
    LightQuery query;
    (*(LightSource_332ec0 * *)&this->f_10)->FUN_00321dc0(&query, 0);
    int lightIndex = query.index;
    if (lightIndex == -1)
        lightIndex = 0;
    Light8_332ec0 light;
    D3D8::D3DDevice_GetLight(lightIndex, &light);
    float v[4];
    v[0] = (float)(*(unsigned char *)&this->f_52) * light.diffuse.r * 0.003921569f;
    v[1] = (float)(*(unsigned char *)&this->f_51) * light.diffuse.g * 0.003921569f;
    v[2] = (float)(*(unsigned char *)&this->f_50) * light.diffuse.b * 0.003921569f;
    v[3] = 1.0f;
    D3D8::D3DDevice_SetPixelShaderConstant(1, v, 1);
    v[0] = (float)(*(unsigned char *)&this->f_56) * light.specular.r * 0.003921569f;
    v[1] = (float)(*(unsigned char *)&this->f_55) * light.specular.g * 0.003921569f;
    v[2] = (float)(*(unsigned char *)&this->f_54) * light.specular.b * 0.003921569f;
    v[3] = 1.0f;
    D3D8::D3DDevice_SetPixelShaderConstant(0, v, 1);
    v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, v);
    v[0] = 1.0f; v[1] = 1.0f; v[2] = 1.0f; v[3] = 1.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x61, v);
    v[0] = 0.5f; v[1] = 0.5f; v[2] = 0.5f; v[3] = 0.5f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, v);
    v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 1.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x77, v);
    if (this->f_88) {
        v[0] = 1.0f; v[1] = 1.0f; v[2] = 1.0f; v[3] = 1.0f;
    } else {
        v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0;
    }
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, v);
}


// 0x00333110 pure3d::d3dBumpMapVertexShader::vfunc_13 (31 B): matches/0x00333110.cpp
// sym: ?vfunc_13@d3dBumpMapVertexShader@pure3d@@UAEXXZ
void pure3d::d3dBumpMapVertexShader::vfunc_13() {
    Device_333110* d = (*(Device_333110 * *)&this->f_14);
    if (d->pixelShader) {
        d->pixelShader = 0;
        D3DDevice_SetPixelShader(0);
    }
}

namespace fn_fad033e0 {

// 0x00333130 FUN_00333130 (62 B): matches/0x00333130.cpp
// sym: ?Make@d3dBumpMapVertexShader_333130@fn_fad033e0@@QAEPAU12@H@Z
// data: zeroF = DAT_004d93ec
d3dBumpMapVertexShader_333130* d3dBumpMapVertexShader_333130::Make(int n) {
    ((d3dBumpMapVertexShader_nv_333130*)(((pure3d::d3dBumpMapVertexShader*)this)))->Init(n);
    vptr = (unsigned int*)&vtblBump;
    a = 0;
    b = 0;
    c = 0;
    CreatePixelShader(((const float*)&DAT_004d93ec), (unsigned int*)((char*)this + 0x8c));
    return this;
}


// 0x00333170 pure3d::d3dBumpMapVertexShader::vfunc_3 (68 B): matches/0x00333170.cpp
// sym: ?vfunc_3@d3dBumpMapVertexShader_333170@fn_fad033e0@@QAEPAU12@E@Z
d3dBumpMapVertexShader_333170* d3dBumpMapVertexShader_333170::vfunc_3(byte_333170 param) {
    vf = (void*)((hulk_intptr)DAT_00433f74);
    if (m84)
        m84->f1();
    if (m80)
        m80->f1();
    FUN_00327930();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fad033e0

// 0x003331c0 pure3d::d3dBumpMapVertexShader::vfunc_14 (414 B): equivalent/0x003331c0.cpp [wrapped: conflict: pure3d::d3dBumpMapVertexShader]
// sym: ?vfunc_14@d3dBumpMapVertexShader@pure3d@fn_003331c0@@UAEXH@Z
namespace fn_003331c0 {
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 12/12)
// pure3d::d3dBumpMapVertexShader::vfunc_14 @ 0x003331c0

typedef unsigned int uint;
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(uint stage, uint value);
}
extern uint DAT_0039db08;
extern uint DAT_0039db10, DAT_0039db14, DAT_0039db18;
extern uint DAT_0039db90, DAT_0039db94, DAT_0039db98;
extern uint DAT_0039dc10, DAT_0039dc14, DAT_0039dc18;
extern uint DAT_0039dc90, DAT_0039dc94, DAT_0039dc98;
extern uint DAT_0039de9c, DAT_0039dea0, DAT_0039dea4;

struct TextureState_3331c0 {
    char pad0[0x18];
    uint coord0;
    uint coord1;
    char pad20[0x28 - 0x20];
    uint blend0;
    uint blend1;
    uint blend2;
    uint blend3;
    void FUN_0032a920(uint a, uint tex1, uint tex0, uint b, uint c);
    void FUN_00329c90(uint stage, uint value);
};

namespace pure3d {
class d3dBumpMapVertexShader {
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
    virtual void vfunc_13();
    virtual void vfunc_14(int unused);
    char pad04[0x14 - 4 - 0];
    TextureState_3331c0* state;
    char pad18[0x40 - 0x18];
    uint mode;
    uint value;
    char pad48[0x80 - 0x48];
    uint tex0;
    uint tex1;
};
}

void pure3d::d3dBumpMapVertexShader::vfunc_14(int unused) {
    state->FUN_0032a920(4, tex1, tex0, 0, 0);
    if (state->coord0 != 0) {
        state->coord0 = 0;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(0, 0);
    }
    if (state->coord1 != 1) {
        state->coord1 = 1;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 1);
    }
    if (state->blend0 != mode) {
        state->blend0 = mode;
        uint v = ((uint*)&DAT_004d4efc)[mode];
        DAT_0039db10 = v;
        DAT_0039db14 = v;
        DAT_0039db08 |= 1;
        DAT_0039db18 = v;
    }
    state->FUN_00329c90(0, value);
    if (state->blend1 != 0) {
        state->blend1 = 0;
        uint v = ((uint*)&DAT_004d4efc)[0];
        DAT_0039db90 = v;
        DAT_0039db94 = v;
        DAT_0039db08 |= 2;
        DAT_0039db98 = v;
    }
    state->FUN_00329c90(1, value);
    if (state->blend2 != 1) {
        state->blend2 = 1;
        uint v = ((uint*)&DAT_004d4efc)[1];
        DAT_0039dc10 = v;
        DAT_0039dc14 = v;
        DAT_0039db08 |= 4;
        DAT_0039dc18 = v;
    }
    state->FUN_00329c90(3, value);
    if (state->blend3 != 1) {
        state->blend3 = 1;
        uint v = ((uint*)&DAT_004d4efc)[1];
        DAT_0039dc90 = v;
        DAT_0039dc94 = v;
        DAT_0039db08 |= 8;
        DAT_0039dc98 = v;
    }
    state->FUN_00329c90(3, value);
    DAT_0039dc10 = 3;
    DAT_0039dc14 = 3;
    DAT_0039dc18 = 3;
    DAT_0039dc90 = 3;
    DAT_0039dc94 = 3;
    DAT_0039dc98 = 3;
    DAT_0039de9c = 0;
    DAT_0039dea0 = 0;
    DAT_0039dea4 = 0;
    DAT_0039db90 = 1;
    DAT_0039db94 = 1;
    DAT_0039db98 = 1;
    DAT_0039db08 |= 0xf;
}
} // namespace fn_003331c0

