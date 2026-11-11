// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032b530..0x0032c270 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dLightMapShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f4b94d0d {
#define TREE_TU_END }
namespace fn_f4b94d0d {} using namespace fn_f4b94d0d;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f4b94d0d {
extern unsigned int DAT_0039db08;
extern TexSlot DAT_0039db10[];
struct StageCache_32b530 {
    char pad0[0x18];
    int texCoordIndex[4];
    int modes[4];
    char pad38[0xf4 - 0x38];
    int dirty[4];
};
class TextureStage {
  public:
    char pad0[0x14];
    StageCache_32b530* cache;
    char pad18[0x40 - 0x18];
    int mode;
    int arg;
    void Set(int stage, int texCoord, int value);
};
extern "C" char DAT_0043397c[];
struct Ref_32b5e0 {
    virtual void f0();
    virtual void f1();
};
struct d3dShader_32b5e0 {
    void cleanup();
};
struct d3dLightMapShader_nv_32b5e0 {
    void cleanup();
};
class pddiObject_32b650 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32b650 : public pddiObject_32b650 {};
class pddiBaseShader_32b650 : public pddiShader_32b650 {
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
class d3dShader_32b650 : public pddiBaseShader_32b650 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class d3dLightMapShader {
  public:
    char pad[0x48];
    unsigned char a;
    char pad2[0x3f];
    unsigned char b;
    unsigned char c;
    int vfunc_22();
};
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(DWORD, DWORD);
}
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_CullMode(DWORD);
}
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_TwoSidedLighting(DWORD);
}
struct Texture_32b6c0 {
};
struct RenderDevice_32b6c0 {
    void FUN_003219c0();
};
struct TextureState_32b6c0 {
    RenderDevice_32b6c0* device;
    char pad4[4];
    Texture_32b6c0* tex[4];
    int texCoordIndex[4];
    char pad28[0x104 - 0x28];
    unsigned char dirty;
    unsigned char twoSided;
};
} // namespace fn_f4b94d0d
namespace pure3d {
struct d3dLightMapShader_nv_32b6c0 {
    void FUN_0032a320(int stage, int coord);
    void FUN_0032b530(int, int, int);
    void FUN_0032a260();
};
}
namespace fn_f4b94d0d {
class Obj {
  public:
    virtual void Add();
    virtual void Release();
    char _m_pad_4[0x8c];
    float value;
    void Set(float x);
};
class Owner {
  public:
    char _m_pad_0[0x80];
    Obj* item;
    Ref* ptr;
    void Set(Obj* p);
    void Set(Ref* p);
};
class A_32b940 {
  public:
    char pad[0x88];
    char b88;
    void Set(void* p);
};
class Obj_32b960 {
  public:
    char pad[0x89];
    char mFlag;
    void Set(void* x);
};
class Obj_32b980 {
  public:
    char pad[0x8c];
    int mVal;
    void Set(int v);
};
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(int, const unsigned int*);
}
extern int vtable_32ba30;
struct d3dLightMapShader_nv_32ba30 {
    void Init(int);
};
class Ref_32ba70 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_32ba70;
class d3dLightMapShader_32ba70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dLightMapShader_32ba70* vfunc_3(unsigned int);
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
    Ref_32ba70* a;
    Ref_32ba70* b;
};
void __cdecl destroy(d3dLightMapShader_32ba70*);
struct Vec4_32bb10 {
    float x, y, z, w;
};
struct D3DLIGHT8 {
    int Type;
    Vec4_32bb10 Diffuse, Specular, Ambient;
    float Position[3];
    float Direction[3];
    float Range, Falloff, Attenuation0, Attenuation1, Attenuation2, Theta, Phi;
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, D3DLIGHT8* light);
}
struct LightConst_32bb10 {
    unsigned char used;
    Vec4_32bb10 pos;
    Vec4_32bb10 atten;
    Vec4_32bb10 color;
};
struct Frame_32bb10 {
    LightConst_32bb10 lights[4];
    int ids[4];
    D3DLIGHT8 light;
};
class LightSet_32bb10 {
  public:
    char pad0[0x10];
    LightMgr* mgr;
    char pad14[0x88 - 0x14];
    unsigned char dirLight;
    unsigned char b89;
    char pad8a[0x8c - 0x8a];
    int mode;
    void Upload();
};
struct Vec4_32be30 {
    float x, y, z, w;
};
struct Matrix_32be30 {
    float m[16];
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned long type, Matrix_32be30* out);
}
} // namespace fn_f4b94d0d
namespace pure3d {
struct d3dLightMapShader_nv_32be30 {
    void FUN_0032b990();
    void FUN_0032bb10();
};
}

namespace fn_f4b94d0d {

// 0x0032b530 FUN_0032b530 (173 B): equivalent/0x0032b530.cpp
// sym: ?Set@TextureStage@fn_f4b94d0d@@QAEXHHH@Z @a31d6acc44ef @w46c551faea69
// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 6/6)
// FUN_0032b530 @ 0x0032b530
void TextureStage::Set(int stage, int texCoord, int value) {
    if (cache->texCoordIndex[stage] != texCoord) {
        cache->texCoordIndex[stage] = texCoord;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(stage, texCoord);
    }
    if (cache->dirty[stage] != value) {
        cache->dirty[stage] = value;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[stage].v54 = value;
    }
    if (cache->modes[stage] != mode) {
        cache->modes[stage] = mode;
        unsigned int t = ((unsigned int*)&DAT_004d4efc)[mode];
        DAT_0039db08 |= 1u << stage;
        DAT_0039db10[stage].v0 = t;
        DAT_0039db10[stage].v4 = t;
        DAT_0039db10[stage].v8 = t;
    }
    ((owners::Obj_329c90 *)cache)->FUN_00329c90(stage, arg);
}

} // namespace fn_f4b94d0d

// 0x0032b5e0 FUN_0032b5e0 (47 B): matches/0x0032b5e0.cpp
// sym: ?FUN_0032b5e0@d3dLightMapShader@pure3d@@QAEXXZ
void pure3d::d3dLightMapShader::FUN_0032b5e0() {
    *(void**)this = (void*)((hulk_intptr)DAT_0043397c);
    if ((*(Ref_32b5e0 * *)&this->f_80))
        (*(Ref_32b5e0 * *)&this->f_80)->f1();
    if ((*(Ref_32b5e0 * *)&this->f_84))
        (*(Ref_32b5e0 * *)&this->f_84)->f1();
    ((d3dLightMapShader_nv_32b5e0*)this)->cleanup();
}

namespace fn_f4b94d0d {

// 0x0032b610 pure3d::d3dLightMapShader::vfunc_15 (6 B): matches/0x0032b610.cpp
// sym: _FUN_0032b610
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032b610() {
    return &(*(int*)&DAT_004d7d60);
}


// 0x0032b620 pure3d::d3dLightMapShader::vfunc_16 (6 B): matches/0x0032b620.cpp
// sym: _FUN_0032b620
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032b620() {
    return &(*(int*)&DAT_004d7c40);
}


// 0x0032b630 pure3d::d3dLightMapShader::vfunc_17 (6 B): matches/0x0032b630.cpp
// sym: _FUN_0032b630
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032b630() {
    return &(*(int*)&DAT_004d7da8);
}


// 0x0032b640 pure3d::d3dLightMapShader::vfunc_4 (6 B): matches/0x0032b640.cpp
// sym: _FUN_0032b640
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032b640() {
    return &(*(int*)&DAT_00433680);
}

} // namespace fn_f4b94d0d

// 0x0032b650 pure3d::d3dLightMapShader::vfunc_11 (6 B): matches/0x0032b650.cpp
// sym: ?vfunc_11@d3dLightMapShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dLightMapShader::vfunc_11() {
    return 1;
}

namespace fn_f4b94d0d {

// 0x0032b660 pure3d::d3dLightMapShader::vfunc_22 (36 B): matches/0x0032b660.cpp
// sym: ?vfunc_22@d3dLightMapShader@fn_f4b94d0d@@QAEHXZ
int d3dLightMapShader::vfunc_22() {
    return !a && (b || c);
}

} // namespace fn_f4b94d0d

// 0x0032b690 pure3d::d3dLightMapShader::vfunc_23 (48 B): matches/0x0032b690.cpp
// sym: ?vfunc_23@d3dLightMapShader@pure3d@@UAEPAXXZ
 // namespace pure3d
void* pure3d::d3dLightMapShader::vfunc_23() {
    if (!(*(u8 *)&this->f_48) && (*(u8 *)&this->f_88))
        return (void*)("layered_multicbv");
    if (!(*(u8 *)&this->f_48) && (*(u8 *)&this->f_89))
        return (void*)("layered_proximity");
    return (void*)("");
}


// 0x0032b6c0 pure3d::d3dLightMapShader::vfunc_14 (514 B): equivalent/0x0032b6c0.cpp
// sym: ?vfunc_14@d3dLightMapShader@pure3d@@UAEXH@Z @5a4cc0c16581 @wed2853bcc864
// STATUS: equivalent (tools/equiv.py level 3: 19754 inputs, branch coverage 37/37)
// pure3d::d3dLightMapShader::vfunc_14 @ 0x0032b6c0
void pure3d::d3dLightMapShader::vfunc_14(int unused) {
    int n = 0;
    if ((*(Texture_32b6c0 * *)&this->f_80)) {
        ((owners::Obj_329e50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329e50(0, 4, 1, 2);
        if ((*(Texture_32b6c0 * *)&this->f_80) != (*(TextureState_32b6c0 * *)&this->f_14)->tex[0]) {
            (*(TextureState_32b6c0 * *)&this->f_14)->tex[0] = (*(Texture_32b6c0 * *)&this->f_80);
            if ((*(Texture_32b6c0 * *)&this->f_80)) {
                ((owners::Obj_326b00 *)((*(Texture_32b6c0 * *)&this->f_80)))->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032b530(0, 0, 0);
        n = 1;
    }
    if ((*(Texture_32b6c0 * *)&this->f_84)) {
        ((owners::Obj_329e50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329e50(n, 4, 1, 2);
        if ((*(Texture_32b6c0 * *)&this->f_84) != (*(TextureState_32b6c0 * *)&this->f_14)->tex[n]) {
            (*(TextureState_32b6c0 * *)&this->f_14)->tex[n] = (*(Texture_32b6c0 * *)&this->f_84);
            if ((*(Texture_32b6c0 * *)&this->f_84)) {
                ((owners::Obj_326b00 *)((*(Texture_32b6c0 * *)&this->f_84)))->FUN_00326b00((unsigned long)n);
            } else {
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
        }
        ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032a320(n, 0);
        if ((*(TextureState_32b6c0 * *)&this->f_14)->texCoordIndex[n] != 1) {
            (*(TextureState_32b6c0 * *)&this->f_14)->texCoordIndex[n] = 1;
            D3D8::D3DDevice_SetTextureState_TexCoordIndex(n, 1);
        }
        n++;
    }
    if (!this->f_48 && (*(unsigned int *)&this->f_38)) {
        unsigned int color = 0;
        bool apply = true;
        switch (this->f_1c) {
        case 1:
        case 7:
            ((owners::C_329cf0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329cf0(n, 2, 1);
            ((owners::Device_329f20 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329f20((0xffffffffu - (*(unsigned int *)&this->f_38)) << 24);
            ((owners::Obj_329e00 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329e00(n, 4, 1, 3);
            break;
        case 2:
        case 3:
            color = 0xff - (*(unsigned int *)&this->f_38);
            color = (((color << 8) | color) << 8) | color;
            ((owners::Device_329f20 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329f20(color);
            ((owners::Obj_329d50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329d50(n, 4, 1, 3);
            ((owners::C_329da0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329da0(n, 2, 1);
            break;
        case 4:
        case 5:
            color = ((((*(unsigned int *)&this->f_38) << 8) | (*(unsigned int *)&this->f_38)) << 8) | (*(unsigned int *)&this->f_38);
            ((owners::Device_329f20 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329f20(color);
            ((owners::Obj_329d50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329d50(n, 4, 1, 3);
            ((owners::C_329da0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329da0(n, 2, 1);
            break;
        default:
            apply = false;
            break;
        }
        if (apply) {
            if ((*(TextureState_32b6c0 * *)&this->f_14)->tex[n] != 0) {
                (*(TextureState_32b6c0 * *)&this->f_14)->tex[n] = 0;
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
            ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032a320(n, 0);
            n++;
        }
    }
    ((owners::State_329bb0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329bb0((unsigned int)n);
    TextureState_32b6c0* s = (*(TextureState_32b6c0 * *)&this->f_14);
    unsigned char cull = (*(unsigned char *)&this->f_7c);
    if (s->twoSided != cull || s->dirty) {
        s->twoSided = cull;
        if (cull) {
            D3D8::D3DDevice_SetRenderState_CullMode(0);
            D3D8::D3DDevice_SetRenderState_TwoSidedLighting(0);
        } else {
            D3D8::D3DDevice_SetRenderState_TwoSidedLighting(0);
            s->device->FUN_003219c0();
        }
    }
    if (s->dirty) {
        s->dirty = 0;
        DAT_0039db08 |= 0x3200;
        DAT_0039dea8 = 0;
        DAT_0039deac = 0;
    }
    ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032a260();
}

namespace fn_f4b94d0d {

// 0x0032b8e0 FUN_0032b8e0 (44 B): matches/0x0032b8e0.cpp
// sym: ?Set@Owner@fn_f4b94d0d@@QAEXPAVObj@2@@Z
void Owner::Set(Obj* p) {
    if (p)
        p->Add();
    if (item)
        item->Release();
    item = p;
}


// 0x0032b910 FUN_0032b910 (44 B): matches/0x0032b910.cpp
// sym: ?Set@Owner@fn_f4b94d0d@@QAEXPAVRef@2@@Z
void Owner::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}


// 0x0032b940 FUN_0032b940 (18 B): matches/0x0032b940.cpp
// sym: ?Set@A_32b940@fn_f4b94d0d@@QAEXPAX@Z
void A_32b940::Set(void* p) {
    b88 = (p != 0);
}


// 0x0032b960 FUN_0032b960 (18 B): matches/0x0032b960.cpp
// sym: ?Set@Obj_32b960@fn_f4b94d0d@@QAEXPAX@Z
void Obj_32b960::Set(void* x) {
    mFlag = (x != 0);
}


// 0x0032b980 FUN_0032b980 (13 B): matches/0x0032b980.cpp
// sym: ?Set@Obj_32b980@fn_f4b94d0d@@QAEXH@Z
void Obj_32b980::Set(int v) {
    mVal = v;
}

} // namespace fn_f4b94d0d

// 0x0032b990 FUN_0032b990 (93 B): equivalent/0x0032b990.cpp
// sym: ?FUN_0032b990@ShaderState_32b990@owners@@QAEXXZ @3ce0d75c4f62 @w67333074cec6
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0032b990 @ 0x0032b990
void owners::ShaderState_32b990::FUN_0032b990() {
    unsigned int v = value;
    if (mode == 1 || flag == 0) v = 0;
    unsigned int constants[4] = {v, v, v, v};
    D3D8::D3DDevice_SetVertexShaderConstant1(0x63, constants);
}


// 0x0032ba30 FUN_0032ba30 (63 B): matches/0x0032ba30.cpp
// sym: ?FUN_0032ba30@d3dLightMapShader@pure3d@@QAEPAV12@H@Z
pure3d::d3dLightMapShader* pure3d::d3dLightMapShader::FUN_0032ba30(int arg) {
    ((d3dLightMapShader_nv_32ba30*)this)->Init(arg);
    (*(int *)&this->f_80) = 0;
    (*(int *)&this->f_84) = 0;
    (*(char *)&this->f_88) = 0;
    (*(char *)&this->f_89) = 0;
    this->f_8c = 0;
    this->f_90 = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32ba30;
    return (d3dLightMapShader*)(this);
}

namespace fn_f4b94d0d {

// 0x0032ba70 pure3d::d3dLightMapShader::vfunc_3 (68 B): matches/0x0032ba70.cpp
// sym: ?vfunc_3@d3dLightMapShader_32ba70@fn_f4b94d0d@@UAEPAV12@I@Z
d3dLightMapShader_32ba70* d3dLightMapShader_32ba70::vfunc_3(unsigned int x) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32ba70;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}


// 0x0032bac0 FUN_0032bac0 (78 B): matches/0x0032bac0.cpp
// sym: ?Set@Obj@fn_f4b94d0d@@QAEXM@Z
void Obj::Set(float x) {
    if (x >= 0.0f && x <= 1.0f)
        value = x;
    else if (x > 1.0f)
        value = 1.0f;
    else
        value = 0.0f;
}


// 0x0032bb10 FUN_0032bb10 (792 B): equivalent/0x0032bb10.cpp
// sym: ?Upload@LightSet_32bb10@fn_f4b94d0d@@QAEXXZ @7292b7b438bd @wf072ce9561ba
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0032bb10 @ 0x0032bb10
void LightSet_32bb10::Upload() {
    Frame_32bb10 F;
    F.lights[0].used = 0;
    F.lights[0].pos.x = 1.0f;
    F.lights[0].pos.y = 1.0f;
    F.lights[0].pos.z = 1.0f;
    F.lights[0].pos.w = 1.0f;
    F.lights[0].atten.x = 1.0e10f;
    F.lights[0].atten.y = 1.0e10f;
    F.lights[0].atten.z = 1.0e10f;
    F.lights[0].atten.w = 1.0e10f;
    F.lights[0].color.x = 0.0f;
    F.lights[0].color.y = 0.0f;
    F.lights[0].color.z = 0.0f;
    F.lights[0].color.w = 0.0f;
    F.lights[1].used = 0;
    F.lights[1].pos.x = 1.0f;
    F.lights[1].pos.y = 1.0f;
    F.lights[1].pos.z = 1.0f;
    F.lights[1].pos.w = 1.0f;
    F.lights[1].atten.x = 1.0e10f;
    F.lights[1].atten.y = 1.0e10f;
    F.lights[1].atten.z = 1.0e10f;
    F.lights[1].atten.w = 1.0e10f;
    F.lights[1].color.x = 0.0f;
    F.lights[1].color.y = 0.0f;
    F.lights[1].color.z = 0.0f;
    F.lights[1].color.w = 0.0f;
    F.lights[2].used = 0;
    F.lights[2].pos.x = 1.0f;
    F.lights[2].pos.y = 1.0f;
    F.lights[2].pos.z = 1.0f;
    F.lights[2].pos.w = 1.0f;
    F.lights[2].atten.x = 1.0e10f;
    F.lights[2].atten.y = 1.0e10f;
    F.lights[2].atten.z = 1.0e10f;
    F.lights[2].atten.w = 1.0e10f;
    F.lights[2].color.x = 0.0f;
    F.lights[2].color.y = 0.0f;
    F.lights[2].color.z = 0.0f;
    F.lights[2].color.w = 0.0f;
    F.lights[3].used = 0;
    F.lights[3].pos.x = 1.0f;
    F.lights[3].pos.y = 1.0f;
    F.lights[3].pos.z = 1.0f;
    F.lights[3].pos.w = 1.0f;
    F.lights[3].atten.x = 1.0e10f;
    F.lights[3].atten.y = 1.0e10f;
    F.lights[3].atten.z = 1.0e10f;
    F.lights[3].atten.w = 1.0e10f;
    F.lights[3].color.x = 0.0f;
    F.lights[3].color.y = 0.0f;
    F.lights[3].color.z = 0.0f;
    F.lights[3].color.w = 0.0f;
    if (mode == 1 || b89) {
        mgr->FUN_00321dc0(F.ids, 3);
        for (int i = 0; i < 4; i++) {
            int id = F.ids[i];
            if (id == -1)
                continue;
            D3D8::D3DDevice_GetLight(id, &F.light);
            F.lights[i].pos.x = F.light.Position[0];
            F.lights[i].pos.y = F.light.Position[1];
            F.lights[i].pos.z = F.light.Position[2];
            F.lights[i].atten.z = F.light.Attenuation2;
            if (mode == 1 && dirLight) {
                F.lights[i].color.w = 1.0f;
            } else {
                F.lights[i].color.x = F.light.Diffuse.x;
                F.lights[i].color.y = F.light.Diffuse.y;
                F.lights[i].color.z = F.light.Diffuse.z;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7e + i * 3, &F.lights[i].pos);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7f + i * 3, &F.lights[i].atten);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x80 + i * 3, &F.lights[i].color);
    }
}

} // namespace fn_f4b94d0d

// 0x0032be30 pure3d::d3dLightMapShader::vfunc_24 (264 B): matches/0x0032be30.cpp
// sym: ?vfunc_24@d3dLightMapShader@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::d3dLightMapShader::vfunc_24() {
    Vec4_32be30 consts;
    Matrix_32be30 m6, m0, m1, prod, full, a, b;
    consts.x = 0.0f;
    consts.y = 0.5f;
    consts.z = 1.0f;
    consts.w = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &consts);
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    ((owners::Matrix_22ca90 *)&prod)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix_32be30 *)(&m6), (const owners::Matrix_22ca90 *)(Matrix_32be30 *)(&m0));
    ((owners::Matrix_22cc10 *)&full)->FUN_0022cc10((const owners::Matrix_22cc10 *)(Matrix_32be30 *)(&prod), (const owners::Matrix_22cc10 *)(Matrix_32be30 *)(&m1));
    a = full;
    ((owners::M_22c0b0 *)&a)->FUN_0022c0b0();
    b = m6;
    ((owners::M_22c0b0 *)&b)->FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &b);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &a);
    ((d3dLightMapShader_nv_32be30*)this)->FUN_0032b990();
    ((d3dLightMapShader_nv_32be30*)this)->FUN_0032bb10();
}

