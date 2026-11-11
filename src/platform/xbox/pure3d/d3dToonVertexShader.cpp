// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00330990..0x00331620 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dToonVertexShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f44f442a {
#define TREE_TU_END }
namespace fn_f44f442a {} using namespace fn_f44f442a;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f44f442a {
struct Obj_330990 {
    virtual void f();
    virtual void release();
};
struct d3dToonVertexShader_nv_330990 {
    void destroy();
};
struct Toon {
    void* vptr;
    char pad[0x90];
    Obj_330990* b;
    Obj_330990* a;
};
extern int toonVtable;
class D {
  public:
    void f();
};
struct D3DLOCKED_RECT {
    int Pitch;
    void* pBits;
};
struct D3DTexture {
    char pad[0x10];
    DWORD Data;
};
namespace D3D8 {
void __stdcall D3DTexture_LockRect(DWORD, DWORD, D3DLOCKED_RECT*, void*, DWORD);
}
struct TextureHolder {
    char pad[0x94];
    D3DTexture* texture;
    char pad2[0xe4 - 0x98];
    int height;
    void FillGradient();
};
class Obj_330ca0 {
  public:
    char pad[0xe0];
    int mVal;
    void Set(int v);
};
class Obj_330cb0 {
  public:
    char pad[0x9c];
    int value;
    void Set(int v);
};
class Thing {
  public:
    char pad[0x94];
    void* other;
    char pad2[0x4c];
    int value;
    void update();
    void setValue(int v);
};
class Obj {
    char pad[0x98];
    Ref* ref;

  public:
    void Set(Ref* p);
};
class T_330d30 {
  public:
    char pad[0xe8];
    int m;
    void Set(int x);
};
typedef unsigned int u32_330d40;
class d3dShader_330d40 {
  public:
    void Init(u32_330d40);
};
extern int vtableSymbol;
class d3dToonVertexShader_330d40 : public d3dShader_330d40 {
  public:
    char p[0x94];
    u32_330d40 x94;
    u32_330d40 x98;
    u32_330d40 x9c;
    char q[0xe0 - 0xa0];
    u32_330d40 xe0;
    u32_330d40 xe4;
    u32_330d40 xe8;
    d3dToonVertexShader_330d40* Run(u32_330d40);
};
class Ref_330d90 {
  public:
    virtual void f0();
    virtual void f1();
};
class d3dToonVertexShader_330d90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual d3dToonVertexShader_330d90* vfunc_3(unsigned char);
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
    char pad[0x90];
    Ref_330d90* m94;
    Ref_330d90* m98;
    void helper();
};
extern char toon_vftable;
void thunk_FUN_00267090(d3dToonVertexShader_330d90*);
struct Desc_330de0 {
    int format;
    char pad[24];
};
extern "C" int __stdcall GetBackBuffer2(int);
extern "C" void __stdcall GetDesc(int, Desc_330de0*);
extern "C" void __stdcall Release(int);
extern "C" int __stdcall CreateTexture2(int, int, int, int, int, int, int);
extern "C" hulk_intptr Alloc(hulk_intptr);
struct Obj_330de0 {
    virtual void Fn();
};
struct d3dTexture_nv_330de0 {
    Obj_330de0* Build(int, int);
};
class d3dToonVertexShader_330de0 {
    char pad[0x10];

  public:
    int m;
    char pad2[0x80];
    Obj_330de0* texture;
    void Update();
    void Tail();
};
extern unsigned int DAT_0039db08, DAT_0039db90, DAT_0039db94, DAT_0039db98;
struct Light_330e60 { char pad0[4]; float color[4]; char pad1[44]; float direction[4]; char pad2[24]; };
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int,Light_330e60*);
}
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_CullMode(int);
}
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_ZEnable(int);
}
} // namespace fn_f44f442a
namespace pure3d {
struct LightManager_330e60 { void FUN_00321dc0(int*,int); };
}
namespace pure3d {
struct ShaderContext { char pad[44]; int mode; void FUN_0032a920(int,unsigned int,unsigned int,int,int); void FUN_00329e50(int,int,int,int); void FUN_00329c90(int,int); };
}
namespace pure3d {
struct d3dToonVertexShader_nv_330e60 {
    void FUN_00330de0();
    void FUN_00333770(int);
    void FUN_0032a320(int,int);
    void FUN_0032a2d0();
    void FUN_0032a260();
};
}

namespace fn_f44f442a {

// 0x00330990 FUN_00330990 (47 B): matches/0x00330990.cpp
// sym: ?target@fn_f44f442a@@YIXPAUToon@1@@Z
void __fastcall target(Toon* self) {
    self->vptr = &toonVtable;
    if (self->a)
        self->a->release();
    if (self->b)
        self->b->release();
    ((d3dToonVertexShader_nv_330990*)(((pure3d::d3dToonVertexShader*)(((pure3d::d3dToonVertexShader*)self)))))->destroy();
}


// 0x003309c0 pure3d::d3dToonVertexShader::vfunc_16 (6 B): matches/0x003309c0.cpp
// sym: _FUN_003309c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003309c0() {
    return &(*(int*)&DAT_004d8d68);
}


// 0x003309d0 pure3d::d3dToonVertexShader::vfunc_18 (6 B): matches/0x003309d0.cpp
// sym: _FUN_003309d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003309d0() {
    return &(*(int*)&DAT_004d8ea0);
}


// 0x003309e0 pure3d::d3dToonVertexShader::vfunc_15 (6 B): matches/0x003309e0.cpp
// sym: _FUN_003309e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003309e0() {
    return &(*(int*)&DAT_004d8d38);
}


// 0x003309f0 pure3d::d3dToonVertexShader::vfunc_17 (6 B): matches/0x003309f0.cpp
// sym: _FUN_003309f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003309f0() {
    return &(*(int*)&DAT_004d8cc0);
}


// 0x00330a00 pure3d::d3dToonVertexShader::vfunc_4 (6 B): matches/0x00330a00.cpp
// sym: _FUN_00330a00
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00330a00() {
    return &(*(int*)&DAT_004d8ca4);
}

} // namespace fn_f44f442a

// 0x00330a10 pure3d::d3dToonVertexShader::vfunc_11 (16 B): matches/0x00330a10.cpp
// sym: ?vfunc_11@d3dToonVertexShader@pure3d@@UAEHXZ
int pure3d::d3dToonVertexShader::vfunc_11() {
    return (int)((this->f_e0 != 1) + 1);
}

namespace fn_f44f442a {

// 0x00330a20 pure3d::d3dToonVertexShader::vfunc_12 (1 B): matches/0x00330a20.cpp
// sym: ?FUN_00330a20@fn_f44f442a@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00330a20() {}

} // namespace fn_f44f442a

// 0x00330a30 pure3d::d3dToonVertexShader::vfunc_13 (8 B): matches/0x00330a30.cpp
// sym: ?vfunc_13@d3dToonVertexShader@pure3d@@UAEXXZ
// Same code shape as 0x0027ff80 (propagated; names are from that function)
void pure3d::d3dToonVertexShader::vfunc_13() {
    (*(D * *)&this->f_10)->f();
}


// 0x00330b70 pure3d::d3dToonVertexShader::vfunc_22 (3 B): matches/0x00330b70.cpp
// sym: ?vfunc_22@d3dToonVertexShader@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::d3dToonVertexShader::vfunc_22() {
    return true;
}


// 0x00330b80 pure3d::d3dToonVertexShader::vfunc_23 (18 B): matches/0x00330b80.cpp
// sym: ?vfunc_23@d3dToonVertexShader@pure3d@@UAEPAXXZ
// data: skin_toon = DAT_00433818, toon = DAT_00433648
void* pure3d::d3dToonVertexShader::vfunc_23() {
    if ((*(char (*)[122])&this->f_04)[0x79])
        return (void*)(DAT_00433818);
    return (void*)(DAT_00433648);
}

namespace fn_f44f442a {

// 0x00330ba0 FUN_00330ba0 (241 B): equivalent/0x00330ba0.cpp
// sym: ?FillGradient@TextureHolder@fn_f44f442a@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 9/10, incomplete)
// FUN_00330ba0 @ 0x00330ba0
void TextureHolder::FillGradient() {
    D3DLOCKED_RECT lock;
    D3D8::D3DTexture_LockRect(texture->Data, 0, &lock, 0, 0);
    unsigned int* pixels = (unsigned int*)lock.pBits;
    float step = 1.0f / height;
    float stepScaled = step * 245.0f;
    float value = 10.0f;
    float limit = step * 64.0f;
    for (int row = 0; row < height; row++) {
        if (0.0f < limit) {
            int col = 0;
            do {
                signed char c = (signed char)(int)value;
                *pixels++ = 0xff000000 + c * 0x10101;
                col++;
                limit = 64.0f / height;
            } while ((float)col < limit);
        }
        value += stepScaled;
        if (row >= height - 2)
            value = 255.0f;
    }
}


// 0x00330ca0 FUN_00330ca0 (13 B): matches/0x00330ca0.cpp
// sym: ?Set@Obj_330ca0@fn_f44f442a@@QAEXH@Z
void Obj_330ca0::Set(int v) {
    mVal = v;
}


// 0x00330cb0 FUN_00330cb0 (13 B): matches/0x00330cb0.cpp
// sym: ?Set@Obj_330cb0@fn_f44f442a@@QAEXH@Z
void Obj_330cb0::Set(int v) {
    value = v;
}


// 0x00330cc0 FUN_00330cc0 (52 B): matches/0x00330cc0.cpp
// sym: ?setValue@Thing@fn_f44f442a@@QAEXH@Z
void Thing::setValue(int v) {
    if (v != value) {
        value = v;
        if (v < 2)
            v = 2;
        value = v;
        if (other)
            update();
    }
}


// 0x00330d00 FUN_00330d00 (44 B): matches/0x00330d00.cpp
// sym: ?Set@Obj@fn_f44f442a@@QAEXPAVRef@2@@Z
void Obj::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ref)
        ref->Release();
    ref = p;
}


// 0x00330d30 FUN_00330d30 (13 B): matches/0x00330d30.cpp
// sym: ?Set@T_330d30@fn_f44f442a@@QAEXH@Z
void T_330d30::Set(int x) {
    m = x;
}


// 0x00330d40 FUN_00330d40 (71 B): matches/0x00330d40.cpp
// sym: ?Run@d3dToonVertexShader_330d40@fn_f44f442a@@QAEPAV12@I@Z
d3dToonVertexShader_330d40* d3dToonVertexShader_330d40::Run(u32_330d40 arg) {
    Init(arg);
    x94 = 0;
    x98 = 0;
    xe0 = 0;
    x9c = 0;
    *(int**)this = &vtableSymbol;
    xe4 = 4;
    xe8 = 0x3c03126f;
    return this;
}


// 0x00330d90 pure3d::d3dToonVertexShader::vfunc_3 (68 B): matches/0x00330d90.cpp
// sym: ?vfunc_3@d3dToonVertexShader_330d90@fn_f44f442a@@UAEPAV12@E@Z
d3dToonVertexShader_330d90* d3dToonVertexShader_330d90::vfunc_3(unsigned char p) {
    Ref_330d90* r = m98;
    *(void**)this = &toon_vftable;
    if (r)
        r->f1();
    r = m94;
    if (r)
        r->f1();
    helper();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00330de0 FUN_00330de0 (125 B): matches/0x00330de0.cpp
// sym: ?Update@d3dToonVertexShader_330de0@fn_f44f442a@@QAEXXZ
void d3dToonVertexShader_330de0::Update() {
    if (texture == 0) {
        int s = GetBackBuffer2(0);
        Desc_330de0 d;
        GetDesc(s, &d);
        Release(s);
        int t = CreateTexture2(0x40, 1, 1, 1, 0, d.format, 3);
        Obj_330de0* o = (Obj_330de0*)Alloc(0xf8);
        if (o)
            o = ((d3dTexture_nv_330de0*)(((pure3d::d3dTexture*)(((pure3d::d3dTexture*)o)))))->Build(m, t);
        else
            o = (Obj_330de0*)0;
        texture = o;
        o->Fn();
        Tail();
    }
}

} // namespace fn_f44f442a

// 0x00330e60 pure3d::d3dToonVertexShader::vfunc_14 (1290 B): equivalent/0x00330e60.cpp
// sym: ?vfunc_14@d3dToonVertexShader@pure3d@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 40/40)
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
void pure3d::d3dToonVertexShader::vfunc_14(int edge) {
 if (!(*(unsigned int *)&this->f_94)) ((d3dToonVertexShader_nv_330e60*)this)->FUN_00330de0();
 float scale=(*(float*)&DAT_0040bbec);
 if (edge) {
  float c[4]; c[0]=(float)(((*(unsigned int *)&this->f_9c)>>16)&255)*scale; c[1]=(float)(((*(unsigned int *)&this->f_9c)>>8)&255)*scale; c[2]=(float)((*(unsigned int *)&this->f_9c)&255)*scale; c[3]=1.0f;
  if(this->f_38) c[3]=(float)(unsigned int)(255-this->f_38)*scale;
  union { unsigned int bits; float value; } edgeBits; edgeBits.bits=(*(unsigned int *)&this->f_e8);
  float settings[4]={64.0f,0.0f,0.0f,0.0f}; settings[2]=edgeBits.value;
  if((*(unsigned char *)&this->f_7d)){D3D8::D3DDevice_SetVertexShaderConstant1(0xbc,c);D3D8::D3DDevice_SetVertexShaderConstant1(0xbd,settings);}
  else {D3D8::D3DDevice_SetVertexShaderConstant1(0x6a,c);D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,settings);}
  ((d3dToonVertexShader_nv_330e60*)this)->FUN_00333770(this->f_38!=0);
  D3D8::D3DDevice_SetRenderState_CullMode(0x900);
  return;
 }
 float colorConstant[4];
 colorConstant[0]=(float)(((*(unsigned int *)&this->f_50)>>16)&255)*scale;
 colorConstant[1]=(float)(((*(unsigned int *)&this->f_50)>>8)&255)*scale;
 colorConstant[2]=(float)((*(unsigned int *)&this->f_50)&255)*scale;
 colorConstant[3]=(float)(((*(unsigned int *)&this->f_50)>>24)&255)*scale;
 if(this->f_38) colorConstant[3]=(float)(unsigned int)(255-this->f_38)*colorConstant[3]*scale;
 float options[4]={0.0f,64.0f,0.0f,0.0f};
 if(this->f_e0==2){((d3dToonVertexShader_nv_330e60*)this)->FUN_00333770(1);colorConstant[3]=0.0f;}
 int indices[4]; float zeroDir[4]={0,0,0,0}; float zeroColor[4]={0,0,0,0};
 Light_330e60 lights[3];
 (*(LightManager_330e60 * *)&this->f_10)->FUN_00321dc0(indices,0);
 D3D8::D3DDevice_GetLight(indices[0]==-1?0:indices[0],&lights[0]);
 D3D8::D3DDevice_GetLight(indices[1]==-1?0:indices[1],&lights[1]);
 D3D8::D3DDevice_GetLight(indices[2]==-1?0:indices[2],&lights[2]);
 const float *a=indices[0]==-1?zeroColor:lights[0].color;
 const float *b=indices[2]==-1?zeroColor:lights[1].color;
 const float *c=indices[2]==-1?zeroColor:lights[2].color;
 float luminance[4];
 luminance[0]=a[2]*(*(float*)&DAT_00433e3c)+a[1]*(*(float*)&DAT_00433e38)+a[0]*(*(float*)&DAT_00433e34);
 luminance[1]=b[2]*(*(float*)&DAT_00433e3c)+b[1]*(*(float*)&DAT_00433e38)+b[0]*(*(float*)&DAT_00433e34);
 luminance[2]=c[2]*(*(float*)&DAT_00433e3c)+c[1]*(*(float*)&DAT_00433e38)+c[0]*(*(float*)&DAT_00433e34);
 luminance[3]=0;
 if((*(unsigned char *)&this->f_7d)) {
  D3D8::D3DDevice_SetVertexShaderConstant1(0xbc,colorConstant);
  D3D8::D3DDevice_SetVertexShaderConstant1(0xbd,options);
  D3D8::D3DDevice_SetVertexShaderConstant1(0xbe,luminance);
 } else {
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6c,indices[0]==-1?zeroDir:lights[0].direction);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6d,indices[1]==-1?zeroDir:lights[1].direction);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6e,indices[2]==-1?zeroDir:lights[2].direction);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6f,luminance);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6a,colorConstant);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,options);
 }
 (*(ShaderContext * *)&this->f_14)->FUN_0032a920(2,(*(unsigned int *)&this->f_98),(*(unsigned int *)&this->f_94),0,0);
 (*(ShaderContext * *)&this->f_14)->FUN_00329e50(0,4,1,2);
 (*(ShaderContext * *)&this->f_14)->FUN_00329e50(1,4,1,2);
 ((d3dToonVertexShader_nv_330e60*)this)->FUN_0032a320(0,0);
 if((*(ShaderContext * *)&this->f_14)->mode!=1){(*(ShaderContext * *)&this->f_14)->mode=1;DAT_0039db90=(*(unsigned int*)((char*)&DAT_004d4efc + 4));DAT_0039db94=(*(unsigned int*)((char*)&DAT_004d4efc + 4));DAT_0039db08|=2;DAT_0039db98=(*(unsigned int*)((char*)&DAT_004d4efc + 4));}
 (*(ShaderContext * *)&this->f_14)->FUN_00329c90(1,2);
 D3D8::D3DDevice_SetRenderState_CullMode(0x901);
 D3D8::D3DDevice_SetRenderState_ZEnable(1);
 ((d3dToonVertexShader_nv_330e60*)this)->FUN_0032a2d0();((d3dToonVertexShader_nv_330e60*)this)->FUN_0032a260();
}

