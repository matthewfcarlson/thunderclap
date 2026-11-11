// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032d8d0..0x0032e830 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dLayeredShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff7bd48b {
#define TREE_TU_END }
namespace fn_ff7bd48b {} using namespace fn_ff7bd48b;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff7bd48b {
class Obj_32d8d0 {
  public:
    char pad[0x8c];
    void* m8c;
    void Set(void* v);
};
extern "C" char DAT_00433b9c[];
class Shader_32d8e0 {
  public:
    virtual void A();
    virtual void B();
};
struct d3dLayeredShader_nv_32d8e0 {
    void Cleanup();
};
class d3dLayeredShader_32d8e0 {
  public:
    virtual void V();
    char pad[0x7c];
    Shader_32d8e0* a;
    Shader_32d8e0* b;
    void Fn();
};
class pddiObject_32d960 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32d960 : public pddiObject_32d960 {};
class pddiBaseShader_32d960 : public pddiShader_32d960 {
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
class d3dShader_32d960 : public pddiBaseShader_32d960 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class d3dLayeredShader {
  public:
    char pad[0x48];
    unsigned char a;
    char pad2[0x90 - 0x49];
    unsigned char b;
    unsigned char c;
    int vfunc_22();
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
    char _m_pad_4[0x80];
    Ref* ptr;
    char _m_pad_88[0x10];
    float value;
    void Set(Ref* p);
    void Set(float x);
};
class Owner {
    char pad[0x80];
    Obj* obj;

  public:
    void Set(Obj* p);
};
class Obj_32da30 {
  public:
    char pad[0x88];
    int value;
    void Set(int v);
};
class X_32dab0 {
  public:
    char pad[0x90];
    char mFlag;
    void SetFlag(int* p);
};
class Obj_32dad0 {
  public:
    char pad[0x91];
    unsigned char flag;
    void Set(void* p);
};
class Obj_32daf0 {
  public:
    char pad[0x94];
    int value;
    void Set(int v);
};
class d3dShader_32dba0 {
  public:
    virtual void V();
    d3dShader_32dba0(int);
};
class d3dLayeredShader_32dba0 : public d3dShader_32dba0 {
  public:
    char pad[0x7c];
    int a;
    int b;
    int special;
    int c;
    unsigned char d;
    unsigned char e;
    char pad2[2];
    int f;
    int g;
    d3dLayeredShader_32dba0(int);
};
class Ref_32dbf0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_32dbf0;
class d3dLayeredShader_32dbf0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dLayeredShader_32dbf0* vfunc_3(unsigned int);
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
    Ref_32dbf0* a;
    Ref_32dbf0* b;
};
void __cdecl destroy(d3dLayeredShader_32dbf0*);
struct Vec3_32e0e0 {
    float x, y, z;
};
struct Light8_32e0e0 {
    int Type;
    Color4 Diffuse;
    Color4 Specular;
    Color4 Ambient;
    Vec3_32e0e0 Position;
    Vec3_32e0e0 Direction;
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
};
struct LightConsts {
    float position[4];
    float attenuation[4];
    float color[4];
    unsigned char used;
};
struct LightList_32e0e0 {
    void FUN_00321dc0(int* indices, int count);
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(DWORD index, Light8_32e0e0* light);
}
struct LightShader {
    char pad0[0x10];
    LightList_32e0e0* lights;
    char pad14[0x90 - 0x14];
    unsigned char directional;
    unsigned char useLights;
    char pad92[2];
    int mode;
    void FUN_0032e0e0();
};
struct Vec4_32e400 {
    float x, y, z, w;
};
struct Matrix_32e400 {
    float m[16];
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int type, Matrix_32e400* out);
}
struct Frame_32e400 {
    Vec4_32e400 consts;
    Matrix_32e400 worldViewT;
    Matrix_32e400 viewT;
    Matrix_32e400 view;
    Matrix_32e400 world;
    Matrix_32e400 worldView;
    Matrix_32e400 proj;
    Matrix_32e400 worldViewProj;
};
} // namespace fn_ff7bd48b
namespace pure3d {
struct d3dLayeredShader_nv_32e400 {
    void FUN_0032db00();
    void FUN_0032e0e0();
};
}
namespace fn_ff7bd48b {
extern "C" char DAT_00433c24[];
struct d3dLayeredLMapShader_nv_32e800 {
    void Init(int);
};


// 0x0032d8d0 FUN_0032d8d0 (13 B): matches/0x0032d8d0.cpp
// sym: ?Set@Obj_32d8d0@fn_ff7bd48b@@QAEXPAX@Z
void Obj_32d8d0::Set(void* v) {
    m8c = v;
}


// 0x0032d8e0 FUN_0032d8e0 (47 B): matches/0x0032d8e0.cpp
// sym: ?Fn@d3dLayeredShader_32d8e0@fn_ff7bd48b@@QAEXXZ
void d3dLayeredShader_32d8e0::Fn() {
    Shader_32d8e0* a = this->a;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_00433b9c);
    if (a)
        a->B();
    Shader_32d8e0* b = this->b;
    if (b)
        b->B();
    ((d3dLayeredShader_nv_32d8e0*)(((pure3d::d3dLayeredShader*)this)))->Cleanup();
}


// 0x0032d910 pure3d::d3dLayeredShader::vfunc_15 (6 B): matches/0x0032d910.cpp
// sym: _FUN_0032d910
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d910() {
    return &(*(int*)&DAT_004d8690);
}


// 0x0032d920 pure3d::d3dLayeredShader::vfunc_16 (6 B): matches/0x0032d920.cpp
// sym: _FUN_0032d920
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d920() {
    return &(*(int*)&DAT_004d84c8);
}


// 0x0032d930 pure3d::d3dLayeredShader::vfunc_17 (6 B): matches/0x0032d930.cpp
// sym: _FUN_0032d930
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d930() {
    return &(*(int*)&DAT_004d8618);
}


// 0x0032d940 pure3d::d3dLayeredShader::vfunc_18 (6 B): matches/0x0032d940.cpp
// sym: _FUN_0032d940
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d940() {
    return &(*(int*)&DAT_004d86d8);
}


// 0x0032d950 pure3d::d3dLayeredShader::vfunc_4 (6 B): matches/0x0032d950.cpp
// sym: _FUN_0032d950
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032d950() {
    return &(*(int*)&DAT_00433664);
}

} // namespace fn_ff7bd48b

// 0x0032d960 pure3d::d3dLayeredShader::vfunc_11 (6 B): matches/0x0032d960.cpp
// sym: ?vfunc_11@d3dLayeredShader@pure3d@@UAEHXZ
int pure3d::d3dLayeredShader::vfunc_11() {
    return 1;
}

namespace fn_ff7bd48b {

// 0x0032d970 pure3d::d3dLayeredShader::vfunc_22 (36 B): matches/0x0032d970.cpp
// sym: ?vfunc_22@d3dLayeredShader@fn_ff7bd48b@@QAEHXZ
int d3dLayeredShader::vfunc_22() {
    return !a && (b || c);
}

} // namespace fn_ff7bd48b

// 0x0032d9a0 pure3d::d3dLayeredShader::vfunc_23 (48 B): matches/0x0032d9a0.cpp
// sym: ?vfunc_23@d3dLayeredShader@pure3d@@UAEPAXXZ
void* pure3d::d3dLayeredShader::vfunc_23() {
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_90))
        return (void*)("layered_multicbv");
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_91))
        return (void*)("layered_proximity");
    return (void*)("");
}

namespace fn_ff7bd48b {

// 0x0032d9d0 FUN_0032d9d0 (44 B): matches/0x0032d9d0.cpp
// sym: ?Set@Owner@fn_ff7bd48b@@QAEXPAVObj@2@@Z
void Owner::Set(Obj* p) {
    if (p)
        p->AddRef();
    if (obj)
        obj->Release();
    obj = p;
}


// 0x0032da00 FUN_0032da00 (44 B): matches/0x0032da00.cpp
// sym: ?Set@Obj@fn_ff7bd48b@@QAEXPAVRef@2@@Z
void Obj::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}


// 0x0032da30 FUN_0032da30 (13 B): matches/0x0032da30.cpp
// sym: ?Set@Obj_32da30@fn_ff7bd48b@@QAEXH@Z
void Obj_32da30::Set(int v) {
    value = v;
}


// 0x0032da40 FUN_0032da40 (72 B): equivalent/0x0032da40.cpp
// sym: ?FUN_0032da40@fn_ff7bd48b@@YGII@Z @1abf25ecfd78 @w7020bdf5a1ff
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 9/9)
// FUN_0032da40 @ 0x0032da40
unsigned int __stdcall FUN_0032da40(unsigned int value)
{
    switch (value) {
    case 0: return 2;
    case 1: return 14;
    case 2: return 7;
    case 3: return 10;
    case 5: return 5;
    case 6: return 18;
    default: return 4;
    }
}


// 0x0032dab0 FUN_0032dab0 (18 B): matches/0x0032dab0.cpp
// sym: ?SetFlag@X_32dab0@fn_ff7bd48b@@QAEXPAH@Z
void X_32dab0::SetFlag(int* p) {
    mFlag = (char)(p != 0);
}


// 0x0032dad0 FUN_0032dad0 (18 B): matches/0x0032dad0.cpp
// sym: ?Set@Obj_32dad0@fn_ff7bd48b@@QAEXPAX@Z
void Obj_32dad0::Set(void* p) {
    flag = (p != 0);
}


// 0x0032daf0 FUN_0032daf0 (13 B): matches/0x0032daf0.cpp
// sym: ?Set@Obj_32daf0@fn_ff7bd48b@@QAEXH@Z
void Obj_32daf0::Set(int v) {
    value = v;
}

} // namespace fn_ff7bd48b

// 0x0032db00 FUN_0032db00 (93 B): equivalent/0x0032db00.cpp
// sym: ?FUN_0032db00@ShaderState_32db00@owners@@QAEXXZ @1e3c8828095e @w88f46da6df01
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 4/4)
// FUN_0032db00 @ 0x0032db00
void owners::ShaderState_32db00::FUN_0032db00() {
 float constants[4];
 float v = (mode == 1 || enabled == 0) ? 0.0f : value;
 constants[0] = v;
 constants[1] = v;
 constants[2] = v;
 constants[3] = v;
 D3D8::D3DDevice_SetVertexShaderConstant1(0x63, constants);
}

namespace fn_ff7bd48b {

// 0x0032dba0 FUN_0032dba0 (79 B): matches/0x0032dba0.cpp
// sym: ??0d3dLayeredShader_32dba0@fn_ff7bd48b@@QAE@H@Z
d3dLayeredShader_32dba0::d3dLayeredShader_32dba0(int x) : d3dShader_32dba0(x), special(4) {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
}


// 0x0032dbf0 pure3d::d3dLayeredShader::vfunc_3 (68 B): matches/0x0032dbf0.cpp
// sym: ?vfunc_3@d3dLayeredShader_32dbf0@fn_ff7bd48b@@UAEPAV12@I@Z
// Same code shape as 0x0032ba70 (propagated; names are from that function)
d3dLayeredShader_32dbf0* d3dLayeredShader_32dbf0::vfunc_3(unsigned int x) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32dbf0;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}

} // namespace fn_ff7bd48b

// 0x0032dc40 pure3d::d3dLayeredShader::vfunc_14 (1065 B): equivalent/0x0032dc40.cpp [wrapped: conflict: pure3d::d3dLayeredShader]
// sym: ?vfunc_14@d3dLayeredShader@pure3d@fn_0032dc40@@UAEXH@Z @676164b57808 @w1a60ad631905
namespace fn_0032dc40 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 55/55)
// pure3d::d3dLayeredShader::vfunc_14 @ 0x0032dc40

namespace D3D8 {
void __stdcall D3DDevice_SetTexture(int stage, void* texture);
void __stdcall D3DDevice_SetPalette(int stage, int palette);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(int stage, int value);
void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
}
extern int DAT_0039de18;

struct Texture {
    void FUN_00326b00(int stage);
};

struct DeviceState_32dc40 {
    char pad0[8];
    Texture* tex[5];
    int coordIndex;
    char pad20[0x48 - 0x20];
    int blend;
    void FUN_00329e50(int a, int b, int c, int d);
    void FUN_00329da0(int a, int b, int c);
    void FUN_00329d50(int a, int b, int c, int d);
    void FUN_00329e00(int a, int b, int c, int d);
    void FUN_00329cf0(int a, int b, int c);
    void FUN_00329f20(int color);
    void FUN_00329bb0(int stageCount);
    void FUN_00329f70(int a, int b, void* data);
    void FUN_0032a920(int a, Texture* t0, Texture* t1, int b, int c);
    void FUN_0032a220(int a, Texture* t);
    void FUN_0032a0c0(int a, int b, int c, int d);
};

namespace pure3d {
class d3dLayeredShader {
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
    char pad4[0x14 - 4];
    DeviceState_32dc40* state;
    char pad18[4];
    int kind;
    char pad20[0x38 - 0x20];
    int alpha;
    char pad3c[0x48 - 0x3c];
    unsigned char flag;
    char pad49[3];
    int blend;
    char data[0x2c];
    unsigned char val7c;
    char pad7d[3];
    Texture* tex0;
    Texture* tex1;
    int mode;
    int path;
    int FUN_0032da40(int mode);
    void FUN_0032b530(int a, int b, int c);
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
};
}

void pure3d::d3dLayeredShader::vfunc_14(int unused) {
    int stage = 0;
    int last = -1;
    int x;
    int p = path;

    if (p == 0) {
        state->FUN_00329e50(0, 3, 1, 2);
        if (state->tex[0] != tex0) {
            state->tex[0] = tex0;
            if (tex0) {
                tex0->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        FUN_0032b530(0, 0, 0);
        int m = mode;
        if (m == 1) {
            x = FUN_0032da40(m);
            state->FUN_00329e50(1, x, 2, m);
            state->FUN_00329da0(1, 2, 1);
        } else {
            x = FUN_0032da40(m);
            state->FUN_00329e50(1, x, 1, 2);
        }
        if (state->tex[1] != tex1) {
            state->tex[1] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(1);
            } else {
                D3D8::D3DDevice_SetTexture(1, 0);
                D3D8::D3DDevice_SetPalette(1, 0);
            }
        }
        FUN_0032b530(1, 1, 0);
        last = 1;
        state->FUN_00329e50(2, 4, 0, 1);
    } else if (p == 1) {
        state->FUN_0032a920(0, tex0, tex1, 0, 0);
        if (tex0) {
            state->FUN_00329e50(0, 4, 0, 2);
            state->FUN_0032a220(0, tex0);
            FUN_0032b530(0, 0, 0);
            stage = 1;
        }
        int m = mode;
        if (m == 1) {
            x = FUN_0032da40(m);
            state->FUN_00329e50(stage, x, 2, m);
            state->FUN_00329da0(stage, 2, 1);
        } else {
            x = FUN_0032da40(m);
            state->FUN_00329e50(stage, x, 1, 2);
        }
        if (state->tex[stage] != tex1) {
            state->tex[stage] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(stage);
            } else {
                D3D8::D3DDevice_SetTexture(stage, 0);
                D3D8::D3DDevice_SetPalette(stage, 0);
            }
        }
        FUN_0032b530(stage, 1, 0);
        last = stage;
        stage++;
    } else {
        state->FUN_00329e50(0, 3, 1, 2);
        if (state->tex[0] != tex1) {
            state->tex[0] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        FUN_0032b530(0, 1, 0);
        state->FUN_00329e50(1, 12, 1, 2);
        if (state->tex[1] != tex0) {
            state->tex[1] = tex0;
            if (tex0) {
                tex0->FUN_00326b00(1);
            } else {
                D3D8::D3DDevice_SetTexture(1, 0);
                D3D8::D3DDevice_SetPalette(1, 0);
            }
        }
        FUN_0032b530(1, 0, 0);
        if (state->coordIndex != 0) {
            state->coordIndex = 0;
            D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 0);
        }
        state->FUN_00329d50(2, 4, 0, 1);
        state->FUN_00329da0(2, 2, 1);
    }

    if (p != 1) {
        if (state->tex[2] != 0) {
            state->tex[2] = 0;
            D3D8::D3DDevice_SetTexture(2, 0);
            D3D8::D3DDevice_SetPalette(2, 0);
        }
        FUN_0032a320(2, 0);
        stage = 3;
    }

    if (flag == 0 && alpha != 0) {
        bool apply = true;
        switch (kind) {
        case 1:
        case 7:
            state->FUN_00329cf0(stage, 2, 1);
            state->FUN_00329f20((-1 - alpha) << 24);
            state->FUN_00329e00(stage, 4, 1, 3);
            break;
        case 2:
        case 3: {
            int a = 0xff - alpha;
            state->FUN_00329f20((((a << 8) | a) << 8) | a);
            state->FUN_00329d50(stage, 4, 1, 3);
            state->FUN_00329da0(stage, 2, 1);
            break;
        }
        case 4:
        case 5:
            state->FUN_00329f20((((alpha << 8) | alpha) << 8) | alpha);
            state->FUN_00329d50(stage, 4, 1, 3);
            state->FUN_00329da0(stage, 2, 1);
            break;
        default:
            apply = false;
            break;
        }
        if (apply) {
            if (state->tex[stage] != 0) {
                state->tex[stage] = 0;
                D3D8::D3DDevice_SetTexture(stage, 0);
                D3D8::D3DDevice_SetPalette(stage, 0);
            }
            FUN_0032a320(stage, 0);
            stage++;
        }
    }

    state->FUN_00329bb0(stage);
    if (blend != state->blend) {
        state->blend = blend;
        int value = DAT_004d4f24[blend];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, value);
        DAT_0039de18 = value;
    }
    state->FUN_00329f70(flag, val7c, data);
    if (mode == 7 && last != -1) {
        state->FUN_00329d50(last, 10, 1, 2);
        state->FUN_00329e00(last, 3, 1, 2);
        state->FUN_0032a0c0(1, 0x8006, 6, 0);
        return;
    }
    FUN_0032a260();
}
} // namespace fn_0032dc40

namespace fn_ff7bd48b {

// 0x0032e090 FUN_0032e090 (78 B): matches/0x0032e090.cpp
// sym: ?Set@Obj@fn_ff7bd48b@@QAEXM@Z
void Obj::Set(float x) {
    if (x >= 0.0f && x <= 1.0f)
        value = x;
    else if (x > 1.0f)
        value = 1.0f;
    else
        value = 0.0f;
}


// 0x0032e0e0 FUN_0032e0e0 (792 B): equivalent/0x0032e0e0.cpp
// sym: ?FUN_0032e0e0@LightShader@fn_ff7bd48b@@QAEXXZ @1ef1680c975c @wa685e2d0a119
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0032e0e0 @ 0x0032e0e0
void LightShader::FUN_0032e0e0() {
    LightConsts c[4];
    for (int i = 0; i < 4; i++) {
        c[i].used = 0;
        for (int k = 0; k < 4; k++) {
            c[i].position[k] = 1.0f;
            c[i].attenuation[k] = 1e10f;
            c[i].color[k] = 0.0f;
        }
    }
    if (mode == 1 || useLights) {
        int idx[4];
        lights->FUN_00321dc0(idx, 3);
        for (int i = 0; i < 4; i++) {
            if (idx[i] == -1)
                continue;
            Light8_32e0e0 light;
            D3D8::D3DDevice_GetLight(idx[i], &light);
            c[i].position[0] = light.Position.x;
            c[i].position[1] = light.Position.y;
            c[i].position[2] = light.Position.z;
            c[i].attenuation[2] = light.Attenuation2;
            if (mode == 1 && directional) {
                c[i].color[3] = 1.0f;
            } else {
                c[i].color[0] = light.Diffuse.r;
                c[i].color[1] = light.Diffuse.g;
                c[i].color[2] = light.Diffuse.b;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7e + i * 3, c[i].position);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7f + i * 3, c[i].attenuation);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x80 + i * 3, c[i].color);
    }
}

} // namespace fn_ff7bd48b

// 0x0032e400 pure3d::d3dLayeredShader::vfunc_24 (264 B): matches/0x0032e400.cpp
// sym: ?vfunc_24@d3dLayeredShader@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::d3dLayeredShader::vfunc_24() {
    Frame_32e400 F;
    F.consts.x = 0.0f;
    F.consts.y = 0.5f;
    F.consts.z = 1.0f;
    F.consts.w = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &F.consts);
    D3D8::D3DDevice_GetTransform(6, &F.view);
    D3D8::D3DDevice_GetTransform(0, &F.world);
    D3D8::D3DDevice_GetTransform(1, &F.proj);
    ((owners::Matrix_22ca90 *)&(F.worldView))->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix_32e400 *)(&F.view), (const owners::Matrix_22ca90 *)(const Matrix_32e400 *)(&F.world));
    ((owners::Matrix_22cc10 *)&(F.worldViewProj))->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix_32e400 *)(&F.worldView), (const owners::Matrix_22cc10 *)(const Matrix_32e400 *)(&F.proj));
    F.worldViewT = F.worldViewProj;
    ((owners::M_22c0b0 *)&(F.worldViewT))->FUN_0022c0b0();
    F.viewT = F.view;
    ((owners::M_22c0b0 *)&(F.viewT))->FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &F.viewT);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &F.worldViewT);
    ((d3dLayeredShader_nv_32e400*)this)->FUN_0032db00();
    ((d3dLayeredShader_nv_32e400*)this)->FUN_0032e0e0();
}


// 0x0032e800 FUN_0032e800 (35 B): matches/0x0032e800.cpp
// sym: ?FUN_0032e800@d3dLayeredLMapShader@pure3d@@QAEPAV12@H@Z
pure3d::d3dLayeredLMapShader* pure3d::d3dLayeredLMapShader::FUN_0032e800(int arg) {
    ((d3dLayeredLMapShader_nv_32e800*)this)->Init(arg);
    *(void**)this = (void*)((hulk_intptr)DAT_00433c24);
    *(int*)((char*)this + 0x9c) = 0;
    return (d3dLayeredLMapShader*)(this);
}

