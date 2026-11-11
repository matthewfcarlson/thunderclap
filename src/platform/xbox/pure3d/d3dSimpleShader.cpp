// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00329430..0x0032b0a0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dSimpleShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f1389006 {
#define TREE_TU_END }
namespace fn_f1389006 {} using namespace fn_f1389006;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f1389006 {
extern "C" void FUN_003290a0();
extern void __stdcall FUN_00011520(void*, unsigned, unsigned, void (*)());
extern "C" unsigned __cdecl FUN_00329060(const char*);
struct Color_329b40 { float r, g, b, a; };
extern int gFlags_329bb0;
extern int gValues_329bb0[128];
extern int gMore[128];
struct TextureState_329c40 { int first; int second; int third; char pad[0x74]; };
extern unsigned int DAT_0039db08;
extern TextureState_329c40 DAT_0039db10[];
extern int gFlags_329cf0;
extern int gCache_329cf0[4096];
extern int gFlags_329d50;
extern int gValues_329d50[];
extern int gFlags_329e00;
extern int gCache_329e00[32];
extern unsigned int gDirty;
struct E_329e50 {
    int x;
    int p[3];
    int y;
    char pad[0x80 - 0x14];
};
extern E_329e50 gTab[];
typedef unsigned int u32_329f20;
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_TextureFactor(u32_329f20);
}
struct Mat_329f70 {
    float diffuse[4];
    float ambient[4];
    float specular[4];
    float emissive[4];
    float power;
};
struct MatSrc_329f70 {
    unsigned int diffuse;
    unsigned int specular;
    unsigned int ambient;
    unsigned int emissive;
    float power;
};
extern void __stdcall D3DDevice_SetRenderState_CullMode(unsigned int mode);
extern void __stdcall D3DDevice_SetMaterial(Mat_329f70* m);
extern void __stdcall D3DDevice_SetBackMaterial(Mat_329f70* m);
struct Color_329f70 {};
extern "C" void __cdecl FUN_00329b40(void *, unsigned int);
class Context {
  public:
    CullState* cull;
    char pad04[0x104 - 4];
    unsigned char lit;
    unsigned char twoSided;
    void FUN_00329f70(unsigned char enable, unsigned char two, MatSrc_329f70* src);
};
extern void __fastcall SetRenderState(unsigned int state, unsigned int value);
extern unsigned int g0_32a0c0, g1, g2, g3;
extern "C" void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
extern int gStateA;
extern int gStateB;
extern int gStateC;
struct Texture {
};
struct DeviceState_32a220 {
    char pad[8];
    Texture* textures[8];
    void SetTexture(int, Texture*);
};
void __stdcall D3DDevice_SetTexture(int, int);
void __stdcall D3DDevice_SetPalette(int, int);
extern "C" char DAT_0043386c[];
class Ref_32a3d0 {
  public:
    virtual void F0();
    virtual void F1();
};
struct d3dSimpleShader_nv_32a3d0 {
    void Next();
};
class pddiObject_32a440 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32a440 : public pddiObject_32a440 {};
class pddiBaseShader_32a440 : public pddiShader_32a440 {
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
class d3dShader_32a440 : public pddiBaseShader_32a440 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
struct Data_32a450 {
    int a, b, c, d, e;
};
class d3dSimpleShader_32a450 {
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
    virtual void vfunc_21(Data_32a450*);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    char pad[0x4c];
    Data_32a450 m;
};
class Owner {
    char pad[0x80];
    Ref* p;

  public:
    void Set(Ref* q);
};
class Obj_32a4f0 {
  public:
    char pad[0x84];
    unsigned char flag;
    void SetFlag(void* p);
};
class Obj_32a510 {
    char pad[0x8c];

  public:
    char m8c;
    void Set(void* p);
};
class A_32a530 {
  public:
    char p[0x90];
    int mRef;
    void Set(int v);
};
class d3dSimpleShader {
  public:
    char pad[0x48];
    unsigned char a;
    char pad2[0x84 - 0x49];
    unsigned char b;
    char pad3[0x8c - 0x85];
    unsigned char c;
    int vfunc_22();
};
static const char s_empty[] = "";
static const char s_multi[] = "simple_multicbv";
static const char s_prox[] = "simple_proximity";
struct Vec4_32a600 {
    float x, y, z, w;
};
struct D3DLIGHT8 {
    int Type;
    Vec4_32a600 Diffuse, Specular, Ambient;
    float Position[3];
    float Direction[3];
    float Range, Falloff, Attenuation0, Attenuation1, Attenuation2, Theta, Phi;
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, D3DLIGHT8* light);
}
struct LightConst_32a600 {
    unsigned char used;
    Vec4_32a600 pos;
    Vec4_32a600 atten;
    Vec4_32a600 color;
};
struct Frame_32a600 {
    LightConst_32a600 lights[4];
    int ids[4];
    D3DLIGHT8 light;
};
class LightSet_32a600 {
  public:
    char pad0[0x10];
    LightMgr* mgr;
    char pad14[0x84 - 0x14];
    unsigned char dirLight;
    char pad85[0x8c - 0x85];
    unsigned char b8c;
    int mode;
    void Upload();
};
struct TextureState_32a920 {
    char pad[8];
    Texture* tex[4];
    void SetTextures(int mode, Texture* t0, Texture* t1, Texture* t2, Texture* t3);
};
class d3dShader_32a9f0 {
  public:
    hulk_intptr v;
    char pad[0x7c];
    int a;
    char b;
    int c;
    char d;
    int e;
};
// pure3d::d3dShader's constructor (0x00333520), on the context the shader belongs to
struct d3dSimpleShader_nv_32a9f0 {
    d3dSimpleShader_nv_32a9f0* FUN_00333520(::pure3d::d3dContext*);
};
class d3dSimpleShader_32a9f0 : public d3dShader_32a9f0 {
  public:
    d3dSimpleShader_32a9f0* Init(::pure3d::d3dContext*);
};
typedef unsigned char u8_32aa30;
struct Ref_32aa30 {
    virtual void f0();
    virtual void f1();
};
struct d3dSimpleShader_nv_32aa30 {
    void run();
};
struct d3dSimpleShader_32aa30 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual d3dSimpleShader_32aa30* vfunc_3(u8_32aa30);
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
    Ref_32aa30* member;
};
class Obj {
    char pad[0x88];
    float value;

  public:
    void Set(float x);
};
} // namespace fn_f1389006
namespace pure3d {
struct Matrix4_32aca0 {
    float m[16];
    void FUN_0022ca90(const Matrix4_32aca0* a, const Matrix4_32aca0* b);
    void FUN_0022cc10(const Matrix4_32aca0* a, const Matrix4_32aca0* b);
    void FUN_0022c0b0();
};
}
namespace pure3d {
class d3dShader_32aca0 {
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
};
}
namespace pure3d {
struct d3dSimpleShader_nv_32aca0 {
    void FUN_0032a5a0();
    void FUN_0032a600();
};
}
namespace fn_f1389006 {
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix4_32aca0* out);
}


// 0x00329430 FUN_00329430 (1080 B): equivalent/0x00329430.cpp
// sym: ?init@Registry_329430@fn_f1389006@@QAEPAU12@PAVd3dContext@pure3d@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2958 inputs, branch coverage 2/2; --wine 600 inputs)
// FUN_00329430 @ 0x00329430
Registry_329430* Registry_329430::init(::pure3d::d3dContext* arg) {
 for(int i=0;i<20;++i) FUN_00011520(entries[i].elements,24,32,&FUN_003290a0);
 owner=arg; count=0;
 entries[0].name=FUN_00329060(((char*)&DAT_003f335c));
 entries[count].data=0; entries[count].count=0;
 const char* names[17]={"skin","skin_onebone","point_sprite","toon2","toon","skin_toon","refract","skin_refract","spheremap","environmap","bumpmap","simple_multicbv","simple_proximity","layered_multicbv","layered_proximity","layered_lightmap_multicbv","layered_lightmap_proximity"};
 char* data[17]={DAT_004d4f40,DAT_004d5388,DAT_004d5640,((char*)&DAT_004d5830),((char*)&DAT_004d56d8),DAT_004d5d70,DAT_004d5a08,DAT_004d6048,DAT_004d64d0,DAT_004d6878,((char*)&DAT_004d6b80),DAT_004d6ce8,((char*)&DAT_004d6f10),DAT_004d70f8,((char*)&DAT_004d7320),DAT_004d7508,((char*)&DAT_004d7730)};
 for(int j=0;j<17;++j) { int index=count+1; count=index; unsigned value=FUN_00329060(names[j]); entries[index].name=value; entries[count].data=data[j]; entries[count].count=0; }
 ++count; return this;
}


// 0x00329b40 FUN_00329b40 (105 B): equivalent/0x00329b40.cpp
// sym: _FUN_00329b40
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0; --wine 600 inputs)
// FUN_00329b40 @ 0x00329b40
// equiv-conv: FUN_00329b40 ecx stack
extern "C" void __cdecl FUN_00329b40(void * color, unsigned int packed)
{
    ((Color_329b40 *)color)->r = (int)((packed >> 16) & 255) * 0.0039215689f;
    ((Color_329b40 *)color)->g = (int)((packed >> 8) & 255) * 0.0039215689f;
    ((Color_329b40 *)color)->b = (int)(packed & 255) * 0.0039215689f;
    ((Color_329b40 *)color)->a = (int)(packed >> 24) * 0.0039215689f;
}

} // namespace fn_f1389006

// 0x00329bb0 FUN_00329bb0 (93 B): matches/0x00329bb0.cpp
// sym: ?FUN_00329bb0@State_329bb0@owners@@QAEXI@Z
void owners::State_329bb0::FUN_00329bb0(unsigned int index) {
    if (index < 4) {
        if (first[index] != 1) {
            first[index] = 1;
            gFlags_329bb0 = gFlags_329bb0 | 0x800;
            gValues_329bb0[index * 32] = 1;
        }
        if (second[index] != 1) {
            second[index] = 1;
            int value = gFlags_329bb0;
            int current = first[index];
            gFlags_329bb0 = value | 0x800;
            gMore[index * 32] = current;
        }
    }
}


// 0x00329c40 FUN_00329c40 (76 B): equivalent/0x00329c40.cpp
// sym: ?FUN_00329c40@Device_329c40@owners@@QAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00329c40 @ 0x00329c40
void owners::Device_329c40::FUN_00329c40(int stage, int value) {
    if (texture[stage] != value) {
        texture[stage] = value;
        int resolved = DAT_004d4efc[value];
        DAT_0039db10[stage].first = resolved;
        DAT_0039db10[stage].second = resolved;
        DAT_0039db08 |= 1u << (stage & 31);
        DAT_0039db10[stage].third = resolved;
    }
}


// 0x00329cf0 FUN_00329cf0 (91 B): matches/0x00329cf0.cpp
// sym: ?FUN_00329cf0@C_329cf0@owners@@QAEXHHH@Z
void owners::C_329cf0::FUN_00329cf0(int index, int value1, int value2) {
    if (a[index] != value1) {
        a[index] = value1;
        gFlags_329cf0 |= 0x800;
        gCache_329cf0[index * 32] = value1;
    }
    if (b[index] != value2) {
        b[index] = value2;
        gFlags_329cf0 |= 0x800;
        gCache_329cf0[index * 32 + 2] = value2;
    }
}


// 0x00329d50 FUN_00329d50 (78 B): matches/0x00329d50.cpp
// sym: ?FUN_00329d50@Obj_329d50@owners@@QAEXHHHH@Z
void owners::Obj_329d50::FUN_00329d50(int index, int a, int b, int value) {
    helper(index, a, b);
    if (slots[index] != value) {
        slots[index] = value;
        gFlags_329d50 |= 0x800;
        gValues_329d50[index * 32] = value;
    }
}


// 0x00329e00 FUN_00329e00 (78 B): matches/0x00329e00.cpp
// sym: ?FUN_00329e00@Obj_329e00@owners@@QAEXHHHH@Z
void owners::Obj_329e00::FUN_00329e00(int a, int b, int c, int d) {
    Helper(a, b, c);
    if (values[a] != d) {
        values[a] = d;
        gFlags_329e00 |= 0x800;
        gCache_329e00[a * 32] = d;
    }
}


// 0x00329e50 FUN_00329e50 (131 B): matches/0x00329e50.cpp
// sym: ?FUN_00329e50@Obj_329e50@owners@@QAEXHHHH@Z
void owners::Obj_329e50::FUN_00329e50(int i, int x, int y, int v) {
    F1(i, x, y);
    if (a[i] != v) {
        a[i] = v;
        gDirty |= 0x800;
        gTab[i].x = v;
    }
    F2(i, x, y);
    if (b[i] != v) {
        b[i] = v;
        gDirty |= 0x800;
        gTab[i].y = v;
    }
}


// 0x00329f20 FUN_00329f20 (30 B): matches/0x00329f20.cpp
// sym: ?FUN_00329f20@Device_329f20@owners@@QAEXI@Z
void owners::Device_329f20::FUN_00329f20(u32_329f20 value) {
    if (value != textureFactor) {
        textureFactor = value;
        D3D8::D3DDevice_SetRenderState_TextureFactor(value);
    }
}

namespace fn_f1389006 {

// 0x00329f70 FUN_00329f70 (321 B): equivalent/0x00329f70.cpp
// sym: ?FUN_00329f70@Context@fn_f1389006@@QAEXEEPAUMatSrc_329f70@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 16/16)
// FUN_00329f70 @ 0x00329f70
// FUN_00329f70 @ 0x00329f70
// equiv-conv: FUN_00329b40 ecx stack
void Context::FUN_00329f70(unsigned char enable, unsigned char two, MatSrc_329f70* src) {
    if (twoSided != two || lit != enable) {
        twoSided = two;
        if (two) {
            D3DDevice_SetRenderState_CullMode(0);
            D3DDevice_SetRenderState_TwoSidedLighting(enable);
        } else {
            D3DDevice_SetRenderState_TwoSidedLighting(0);
            cull->FUN_003219c0();
        }
    }
    if (lit) {
        if (!enable) {
            lit = enable;
            DAT_0039db08 = DAT_0039db08 | 0x3200;
            DAT_0039dea8 = 0;
            DAT_0039deac = 0;
            return;
        }
    } else if (!enable) {
        return;
    }
    Mat_329f70 mat;
    lit = enable;
    DAT_0039db08 = DAT_0039db08 | 0x1200;
    DAT_0039dea8 = 1;
    unsigned int spec = 0;
    if (src->power > 0.0f)
        spec = 1;
    DAT_0039deac = spec;
    DAT_0039db08 = DAT_0039db08 | 0x3000;
    FUN_00329b40((Color_329f70 *)((Color_329f70*)mat.diffuse), src->diffuse);
    FUN_00329b40((Color_329f70 *)((Color_329f70*)mat.ambient), src->ambient);
    FUN_00329b40((Color_329f70 *)((Color_329f70*)mat.specular), src->specular);
    FUN_00329b40((Color_329f70 *)((Color_329f70*)mat.emissive), src->emissive);
    mat.power = src->power;
    D3DDevice_SetMaterial(&mat);
    if (twoSided)
        D3DDevice_SetBackMaterial(&mat);
}

} // namespace fn_f1389006

// 0x0032a0c0 FUN_0032a0c0 (153 B): matches/0x0032a0c0.cpp
// sym: ?FUN_0032a0c0@State_32a0c0@owners@@QAEXEHHH@Z
void owners::State_32a0c0::FUN_0032a0c0(unsigned char flag, int a, int b, int c) {
    if (flag != this->flag) {
        this->flag = flag;
        SetRenderState(0x40304, flag);
        g0_32a0c0 = flag;
    }
    if (this->flag) {
        if (a != this->a) {
            this->a = a;
            SetRenderState(0x40350, a);
            g3 = a;
        }
        if (b != this->b) {
            this->b = b;
            unsigned int v = ((unsigned int*)&DAT_004d4ed0)[b];
            SetRenderState(0x40344, v);
            g1 = v;
        }
        if (c != this->c) {
            this->c = c;
            unsigned int v = ((unsigned int*)&DAT_004d4ed0)[c];
            SetRenderState(0x40348, v);
            g2 = v;
        }
    }
}


// 0x0032a190 FUN_0032a190 (129 B): matches/0x0032a190.cpp
// sym: ?FUN_0032a190@Obj_32a190@owners@@QAEXEHH@Z
// data: gValues_32a190 = DAT_004d4f04
void owners::Obj_32a190::FUN_0032a190(unsigned char enabled, int mode, int value) {
    if (mEnabled != enabled) {
        mEnabled = enabled;
        D3DDevice_SetRenderState_Simple(0x40300, (unsigned char)enabled);
        gStateA = (unsigned char)enabled;
    }
    if (mEnabled != 0) {
        if (mMode != mode) {
            mMode = mode;
            int v = ((int*)&DAT_004d4f04)[mode];
            D3DDevice_SetRenderState_Simple(0x4033c, v);
            gStateB = v;
        }
        if (mEnabled != 0 && mValue != value) {
            mValue = value;
            D3DDevice_SetRenderState_Simple(0x40340, value);
            gStateC = value;
        }
    }
}

namespace fn_f1389006 {

// 0x0032a220 FUN_0032a220 (55 B): matches/0x0032a220.cpp
// sym: ?SetTexture@DeviceState_32a220@fn_f1389006@@QAEXHPAUTexture@2@@Z
void DeviceState_32a220::SetTexture(int stage, Texture* value) {
    if (value != textures[stage]) {
        textures[stage] = value;
        if (value) {
            ((owners::Obj_326b00 *)value)->FUN_00326b00((unsigned long)stage);
            return;
        }
        D3DDevice_SetTexture(stage, 0);
        D3DDevice_SetPalette(stage, 0);
    }
}

} // namespace fn_f1389006

// 0x0032a260 FUN_0032a260 (103 B): equivalent/0x0032a260.cpp [wrapped: compile error C2668: 'fn_f1389006::D3D8::D3DDevice_SetRenderState_Simple' : ambiguous call to overloaded function]
// sym: ?FUN_0032a260@Object@fn_0032a260@@QAEXXZ
namespace fn_0032a260 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0032a260 @ 0x0032a260

struct Entry_32a260 { unsigned char first; char pad[3]; unsigned int second, third, fourth; };   extern int DAT_0039de04; struct Device_32a260 { void FUN_0032a0c0(unsigned int, unsigned int, unsigned int, unsigned int); void FUN_0032a190(unsigned int, unsigned int, unsigned int); }; extern "C" int __cdecl FUN_0034483c(); namespace D3D8 { void __fastcall D3DDevice_SetRenderState_Simple(unsigned int, unsigned int); } struct Object { char pad0[0x14]; Device_32a260 *device; char pad1[4]; unsigned int index; char pad2[8]; unsigned char color; char pad3[3]; unsigned int value; char pad4[4]; float brightness; void FUN_0032a260(); }; void Object::FUN_0032a260() { Entry_32a260 &entry = ((Entry_32a260*)&DAT_004d4e50)[index]; device->FUN_0032a0c0(entry.first, entry.second, entry.third, entry.fourth); device->FUN_0032a190(color, value, 0); int result = (int)(__int64)(brightness * (*(float*)&DAT_00409000)); D3D8::D3DDevice_SetRenderState_Simple(0x40340, result); DAT_0039de04 = result; }
} // namespace fn_0032a260


// 0x0032a2d0 FUN_0032a2d0 (70 B): matches/0x0032a2d0.cpp [wrapped: conflict: D3DDevice_SetRenderState_Simple]
// sym: ?FUN_0032a2d0@fn_0032a2d0@@YIXPAVObj_32a2d0@1@@Z
namespace fn_0032a2d0 {

class Dev_32a2d0 {
    char pad[0x48];

  public:
    hulk_intptr state;
    void Do(unsigned char, unsigned char, char*);
};
class Obj_32a2d0 {
    char pad0[0x14];

  public:
    Dev_32a2d0* dev;
    char pad18[0x30];
    unsigned char first;
    char pad49[3];
    int value;
    char pad50[0x2c];
    unsigned char second;
};
extern void __fastcall D3DDevice_SetRenderState_Simple(const char*, int);
extern int DAT_0039de18;
void __fastcall FUN_0032a2d0(Obj_32a2d0* self) {
    hulk_intptr x = self->value;
    if (x != self->dev->state) {
        self->dev->state = x;
        int v = (*(int*)(((hulk_intptr)((char*)&DAT_004d4f24)) + x * 4));
        D3DDevice_SetRenderState_Simple((const char*)0x4037c, v);
        DAT_0039de18 = v;
    }
    self->dev->Do(self->first, self->second, (char*)self + 0x50);
}
} // namespace fn_0032a2d0


// 0x0032a320 FUN_0032a320 (169 B): equivalent/0x0032a320.cpp [wrapped: conflict: DAT_0039db10]
// sym: ?Set@Stage_32a320@fn_0032a320@@QAEXHH@Z
namespace fn_0032a320 {
// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 6/6)
// FUN_0032a320 @ 0x0032a320

typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(DWORD, DWORD);
}
struct StageState2 {
    char pad0[0x18];
    volatile int texCoordIndex[4];
    volatile int addrMode[4];
    char pad1[0xf4 - 0x38];
    volatile int field_f4[4];
};
struct StageRegs_32a320 {
    int a, b, c;
    char pad[0x80 - 12];
};
struct CoordReg {
    int v;
    char pad[0x7c];
};
extern CoordReg DAT_0039db64[];
extern unsigned int DAT_0039db08;
extern StageRegs_32a320 DAT_0039db10[];
struct Stage_32a320 {
    char pad[0x14];
    StageState2* st;
    char pad2[0x40 - 0x18];
    int mode;
    int value;
    void Set(int stage, int coord);
};
void Stage_32a320::Set(int stage, int coord) {
    if (st->texCoordIndex[stage] != stage) {
        st->texCoordIndex[stage] = stage;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(stage, stage);
    }
    if (st->field_f4[stage] != coord) {
        st->field_f4[stage] = coord;
        DAT_0039db64[stage].v = coord;
        DAT_0039db08 |= 0x400;
    }
    if (st->addrMode[stage] != mode) {
        st->addrMode[stage] = mode;
        unsigned int v = ((unsigned int*)&DAT_004d4efc)[mode];
        DAT_0039db10[stage].a = v;
        DAT_0039db10[stage].b = v;
        DAT_0039db10[stage].c = v;
        DAT_0039db08 |= 1 << stage;
    }
    ((owners::Obj_329c90 *)st)->FUN_00329c90(stage, value);
}
} // namespace fn_0032a320


// 0x0032a3d0 FUN_0032a3d0 (32 B): matches/0x0032a3d0.cpp
// sym: ?FUN_0032a3d0@d3dSimpleShader@pure3d@@QAEXXZ
void pure3d::d3dSimpleShader::FUN_0032a3d0() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0043386c);
    if ((*(Ref_32a3d0 * *)&this->f_80))
        (*(Ref_32a3d0 * *)&this->f_80)->F1();
    ((d3dSimpleShader_nv_32a3d0*)this)->Next();
}

namespace fn_f1389006 {

// 0x0032a3f0 pure3d::d3dSimpleShader::vfunc_15 (6 B): matches/0x0032a3f0.cpp
// sym: _FUN_0032a3f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032a3f0() {
    return &(*(int*)&DAT_004d7988);
}


// 0x0032a400 pure3d::d3dSimpleShader::vfunc_16 (6 B): matches/0x0032a400.cpp
// sym: _FUN_0032a400
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032a400() {
    return &(*(int*)&DAT_004d7aa8);
}


// 0x0032a410 pure3d::d3dSimpleShader::vfunc_17 (6 B): matches/0x0032a410.cpp
// sym: _FUN_0032a410
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032a410() {
    return &(*(int*)&DAT_004d79b8);
}


// 0x0032a420 pure3d::d3dSimpleShader::vfunc_18 (6 B): matches/0x0032a420.cpp
// sym: _FUN_0032a420
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032a420() {
    return &(*(int*)&DAT_004d7a30);
}


// 0x0032a430 pure3d::d3dSimpleShader::vfunc_4 (6 B): matches/0x0032a430.cpp
// sym: _FUN_0032a430
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032a430() {
    return &(*(int*)&DAT_0040a084);
}

} // namespace fn_f1389006

// 0x0032a440 pure3d::d3dSimpleShader::vfunc_11 (6 B): matches/0x0032a440.cpp
// sym: ?vfunc_11@d3dSimpleShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dSimpleShader::vfunc_11() {
    return 1;
}

namespace fn_f1389006 {

// 0x0032a450 pure3d::d3dSimpleShader::vfunc_21 (38 B): matches/0x0032a450.cpp
// sym: ?vfunc_21@d3dSimpleShader_32a450@fn_f1389006@@UAEXPAUData_32a450@2@@Z
// Same code shape as 0x00333370 (propagated; names are from that function)
void d3dSimpleShader_32a450::vfunc_21(Data_32a450* out) {
    *out = m;
}


// 0x0032a4c0 FUN_0032a4c0 (44 B): matches/0x0032a4c0.cpp
// sym: ?Set@Owner@fn_f1389006@@QAEXPAVRef@2@@Z
void Owner::Set(Ref* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}


// 0x0032a4f0 FUN_0032a4f0 (18 B): matches/0x0032a4f0.cpp
// sym: ?SetFlag@Obj_32a4f0@fn_f1389006@@QAEXPAX@Z
void Obj_32a4f0::SetFlag(void* p) {
    flag = (p != 0);
}


// 0x0032a510 FUN_0032a510 (18 B): matches/0x0032a510.cpp
// sym: ?Set@Obj_32a510@fn_f1389006@@QAEXPAX@Z
void Obj_32a510::Set(void* p) {
    m8c = (p != 0);
}


// 0x0032a530 FUN_0032a530 (13 B): matches/0x0032a530.cpp
// sym: ?Set@A_32a530@fn_f1389006@@QAEXH@Z
void A_32a530::Set(int v) {
    mRef = v;
}


// 0x0032a540 pure3d::d3dSimpleShader::vfunc_22 (36 B): matches/0x0032a540.cpp
// sym: ?vfunc_22@d3dSimpleShader@fn_f1389006@@QAEHXZ
int d3dSimpleShader::vfunc_22() {
    if (!a && (b || c))
        return 1;
    return 0;
}

} // namespace fn_f1389006

// 0x0032a570 pure3d::d3dSimpleShader::vfunc_23 (48 B): matches/0x0032a570.cpp
// sym: ?vfunc_23@d3dSimpleShader@pure3d@@UAEPAXXZ
void* pure3d::d3dSimpleShader::vfunc_23() {
    if (!(*(bool *)&this->f_48) && (*(bool *)&this->f_84))
        return (void*)(s_multi);
    if (!(*(bool *)&this->f_48) && (*(bool *)&this->f_8c))
        return (void*)(s_prox);
    return (void*)(s_empty);
}


// 0x0032a5a0 FUN_0032a5a0 (93 B): equivalent/0x0032a5a0.cpp
// sym: ?FUN_0032a5a0@ShaderState_32a5a0@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_0032a5a0 @ 0x0032a5a0
void owners::ShaderState_32a5a0::FUN_0032a5a0() {
 float v = (mode == 1 || enabled == 0) ? 0.0f : value;
 float data[4] = {v,v,v,v};
 D3D8::D3DDevice_SetVertexShaderConstant1(0x63,data);
}

namespace fn_f1389006 {

// 0x0032a600 FUN_0032a600 (792 B): equivalent/0x0032a600.cpp
// sym: ?Upload@LightSet_32a600@fn_f1389006@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 12/12)
// FUN_0032a600 @ 0x0032a600
void LightSet_32a600::Upload() {
    Frame_32a600 F;
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
    if (mode == 1 || b8c) {
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


// 0x0032a920 FUN_0032a920 (203 B): matches/0x0032a920.cpp
// sym: ?SetTextures@TextureState_32a920@fn_f1389006@@QAEXHPAUTexture@2@000@Z
void TextureState_32a920::SetTextures(int mode, Texture* t0, Texture* t1, Texture* t2, Texture* t3) {
    if (t0 != tex[0]) {
        tex[0] = t0;
        if (t0) {
            ((owners::Obj_326b00 *)t0)->FUN_00326b00(0);
        } else {
            D3D8::D3DDevice_SetTexture(0, 0);
            D3D8::D3DDevice_SetPalette(0, 0);
        }
    }
    if (t1 != tex[1]) {
        tex[1] = t1;
        if (t1) {
            ((owners::Obj_326b00 *)t1)->FUN_00326b00(1);
        } else {
            D3D8::D3DDevice_SetTexture(1, 0);
            D3D8::D3DDevice_SetPalette(1, 0);
        }
    }
    if (t2 != tex[2]) {
        tex[2] = t2;
        if (t2) {
            ((owners::Obj_326b00 *)t2)->FUN_00326b00(2);
        } else {
            D3D8::D3DDevice_SetTexture(2, 0);
            D3D8::D3DDevice_SetPalette(2, 0);
        }
    }
    if (t3 != tex[3]) {
        tex[3] = t3;
        if (t3) {
            ((owners::Obj_326b00 *)t3)->FUN_00326b00(3);
        } else {
            D3D8::D3DDevice_SetTexture(3, 0);
            D3D8::D3DDevice_SetPalette(3, 0);
        }
    }
    ((owners::State_329bb0 *)this)->FUN_00329bb0((unsigned int)mode);
}


// 0x0032a9f0 FUN_0032a9f0 (57 B): matches/0x0032a9f0.cpp
// sym: ?Init@d3dSimpleShader_32a9f0@fn_f1389006@@QAEPAV12@PAVd3dContext@pure3d@@@Z
d3dSimpleShader_32a9f0* d3dSimpleShader_32a9f0::Init(::pure3d::d3dContext* x) {
    ((d3dSimpleShader_nv_32a9f0*)(((pure3d::d3dSimpleShader*)(this))))->FUN_00333520(x);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    v = ((hulk_intptr)DAT_0043386c);
    return this;
}


// 0x0032aa30 pure3d::d3dSimpleShader::vfunc_3 (53 B): matches/0x0032aa30.cpp
// sym: ?vfunc_3@d3dSimpleShader_32aa30@fn_f1389006@@UAEPAU12@E@Z
d3dSimpleShader_32aa30* d3dSimpleShader_32aa30::vfunc_3(u8_32aa30 destroy) {
    *(int**)this = (int*)DAT_0043386c;
    if (member)
        member->f1();
    ((d3dSimpleShader_nv_32aa30*)(((pure3d::d3dSimpleShader*)(((pure3d::d3dSimpleShader*)this)))))->run();
    if (destroy & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f1389006

// 0x0032aa70 pure3d::d3dSimpleShader::vfunc_14 (445 B): equivalent/0x0032aa70.cpp [wrapped: conflict: DAT_0039de18; pure3d::d3dSimpleShader]
// sym: ?vfunc_14@d3dSimpleShader@pure3d@fn_0032aa70@@UAEXH@Z
namespace fn_0032aa70 {
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 29/29)
// pure3d::d3dSimpleShader::vfunc_14 @ 0x0032aa70

typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __fastcall D3DDevice_SetRenderState_Simple(DWORD method, DWORD value);
}
extern unsigned int DAT_0039de18;
struct Texture {
    void FUN_00326b00(int stage);
};
struct TextureState_32aa70 {
    char pad0[8];
    Texture* tex[4];
    char pad18[0x48 - 0x18];
    int renderMode;
    void FUN_00329bb0(int);
    void FUN_00329e50(int, int, int, int);
    void FUN_00329cf0(int, int, int);
    void FUN_00329f20(unsigned int);
    void FUN_00329e00(int, int, int, int);
    void FUN_00329d50(int, int, int, int);
    void FUN_00329da0(int, int, int);
    void FUN_00329f70(int, int, void*);
};
namespace pure3d {
class d3dSimpleShader {
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
    virtual void vfunc_14(int unused);
    char pad4[0x14 - 4];
    TextureState_32aa70* state;
    char pad18[4];
    int mode;
    char pad20[0x38 - 0x20];
    unsigned int value;
    char pad3c[0x48 - 0x3c];
    unsigned char flag;
    char pad49[3];
    int renderMode;
    char params[0x7c - 0x50];
    unsigned char flag7c;
    char pad7d[3];
    Texture* tex;
    void FUN_0032a320(int stage, int coord);
    void FUN_0032a260();
};
}
void pure3d::d3dSimpleShader::vfunc_14(int unused) {
    int n = 0;
    if (tex) {
        state->FUN_00329e50(0, 4, 0, 2);
        FUN_0032a320(0, 0);
        n = 1;
    }
    if (!flag && value) {
        unsigned int color = 0;
        bool apply = true;
        switch (mode) {
        case 1:
        case 7:
            state->FUN_00329cf0(n, 2, 1);
            state->FUN_00329f20((0xffffffffu - value) << 24);
            state->FUN_00329e00(n, 4, 1, 3);
            break;
        case 2:
        case 3:
            color = 0xff - value;
            color = (((color << 8) | color) << 8) | color;
            state->FUN_00329f20(color);
            state->FUN_00329d50(n, 4, 1, 3);
            state->FUN_00329da0(n, 2, 1);
            break;
        case 4:
        case 5:
            color = (((value << 8) | value) << 8) | value;
            state->FUN_00329f20(color);
            state->FUN_00329d50(n, 4, 1, 3);
            state->FUN_00329da0(n, 2, 1);
            break;
        default:
            apply = false;
            break;
        }
        if (apply) {
            if (state->tex[n] != 0) {
                state->tex[n] = 0;
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
            FUN_0032a320(n, 0);
            n++;
        }
    }
    TextureState_32aa70* s = state;
    Texture* t0 = tex;
    if (s->tex[0] != t0) {
        s->tex[0] = t0;
        if (t0) {
            t0->FUN_00326b00(0);
        } else {
            D3D8::D3DDevice_SetTexture(0, 0);
            D3D8::D3DDevice_SetPalette(0, 0);
        }
    }
    if (s->tex[1]) {
        s->tex[1] = 0;
        D3D8::D3DDevice_SetTexture(1, 0);
        D3D8::D3DDevice_SetPalette(1, 0);
    }
    if (s->tex[2]) {
        s->tex[2] = 0;
        D3D8::D3DDevice_SetTexture(2, 0);
        D3D8::D3DDevice_SetPalette(2, 0);
    }
    if (s->tex[3]) {
        s->tex[3] = 0;
        D3D8::D3DDevice_SetTexture(3, 0);
        D3D8::D3DDevice_SetPalette(3, 0);
    }
    s->FUN_00329bb0(n);
    if (renderMode != state->renderMode) {
        state->renderMode = renderMode;
        unsigned int v = ((unsigned int*)&DAT_004d4f24)[renderMode];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    state->FUN_00329f70(flag, flag7c, params);
    FUN_0032a260();
}
} // namespace fn_0032aa70

namespace fn_f1389006 {

// 0x0032ac50 FUN_0032ac50 (78 B): matches/0x0032ac50.cpp
// sym: ?Set@Obj@fn_f1389006@@QAEXM@Z
void Obj::Set(float x) {
    if (x >= 0.0f && x <= 1.0f)
        value = x;
    else if (x > 1.0f)
        value = 1.0f;
    else
        value = 0.0f;
}

} // namespace fn_f1389006

// 0x0032aca0 pure3d::d3dSimpleShader::vfunc_24 (264 B): matches/0x0032aca0.cpp
// sym: ?vfunc_24@d3dSimpleShader@pure3d@@UAEXXZ
 // namespace D3D8
void pure3d::d3dSimpleShader::vfunc_24() {
    Matrix4_32aca0 m6, m0, m1, t, u, f, g;
    float consts[4];
    consts[0] = 0.0f;
    consts[1] = 0.5f;
    consts[2] = 1.0f;
    consts[3] = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, consts);
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    t.FUN_0022ca90(&m6, &m0);
    u.FUN_0022cc10(&t, &m1);
    f = u;
    f.FUN_0022c0b0();
    g = m6;
    g.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &g);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &f);
    ((d3dSimpleShader_nv_32aca0*)this)->FUN_0032a5a0();
    ((d3dSimpleShader_nv_32aca0*)this)->FUN_0032a600();
}

