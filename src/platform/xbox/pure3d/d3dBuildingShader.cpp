// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00332260..0x00332ba0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dBuildingShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd7d5ddc {
#define TREE_TU_END }
namespace fn_fd7d5ddc {} using namespace fn_fd7d5ddc;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd7d5ddc {
class Ref_332260 {
  public:
    virtual void f();
    virtual void Release();
};
extern int vtable_332260;
class d3dBuildingShader_332260 {
  public:
    virtual void v();
    char pad[0x7c];
    Ref_332260* a;
    Ref_332260* b;
    Ref_332260* c;
    void init();
    void cleanup();
};
class pddiObject_3322f0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_3322f0 : public pddiObject_3322f0 {};
class pddiBaseShader_3322f0 : public pddiShader_3322f0 {
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
class d3dShader_3322f0 : public pddiBaseShader_3322f0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Dev_332620 {
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
    virtual void SetTransform(int s, const float* m);
    virtual void SetState(int s);
};
struct Dev_3326d0 {
    char p0[0x20];
    int tc;
    char p1[0xc0];
    int s;
    char p2[0x14];
    int t;
};
extern unsigned int g_dirty;
extern int g_a_3326d0;
extern int g_b_3326d0;
void __stdcall SetTC(int a, int b);
class Sub_3326d0 {
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
    virtual void Set(int x);
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
    char _m_pad_4[0x84];
    Ref* ref;
    void Set(Ref* p);
};
class Holder {
    char pad[0x80];
    Obj* ptr;

  public:
    void Set(Obj* p);
};
class Obj_3327e0 {
  public:
    char f4[0x8c];
    void Set(void* p);
};
extern "C" char DAT_00433eec[];
class d3dBuildingShader_332800 {
  public:
    hulk_intptr vtable;
    char pad[0x80 - 4];
    int a, b, c;
    unsigned char d;
    void BaseCtor(int);
    d3dBuildingShader_332800* Target(int);
};
class Ref_332840 {
  public:
    virtual void f0();
    virtual void f1();
};
class d3dBuildingShader_332840 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    d3dBuildingShader_332840(unsigned char);
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
    char pad[0x7c];
    Ref_332840* a;
    Ref_332840* b;
    Ref_332840* c;
    void cleanup();
};
void destroy(d3dBuildingShader_332840*);


// 0x00332260 FUN_00332260 (62 B): matches/0x00332260.cpp
// sym: ?init@d3dBuildingShader_332260@fn_fd7d5ddc@@QAEXXZ
void d3dBuildingShader_332260::init() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_332260;
    if (a)
        a->Release();
    if (b)
        b->Release();
    if (c)
        c->Release();
    cleanup();
}


// 0x003322a0 pure3d::d3dBuildingShader::vfunc_15 (6 B): matches/0x003322a0.cpp
// sym: _FUN_003322a0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003322a0() {
    return &(*(int*)&DAT_004d9328);
}


// 0x003322b0 pure3d::d3dBuildingShader::vfunc_16 (6 B): matches/0x003322b0.cpp
// sym: _FUN_003322b0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003322b0() {
    return &(*(int*)&DAT_004d9238);
}


// 0x003322c0 pure3d::d3dBuildingShader::vfunc_17 (6 B): matches/0x003322c0.cpp
// sym: _FUN_003322c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003322c0() {
    return &(*(int*)&DAT_004d9388);
}


// 0x003322d0 pure3d::d3dBuildingShader::vfunc_18 (6 B): matches/0x003322d0.cpp
// sym: _FUN_003322d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003322d0() {
    return &(*(int*)&DAT_004d91c0);
}


// 0x003322e0 pure3d::d3dBuildingShader::vfunc_4 (6 B): matches/0x003322e0.cpp
// sym: _FUN_003322e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003322e0() {
    return &(*(int*)&DAT_004d91a0);
}

} // namespace fn_fd7d5ddc

// 0x003322f0 pure3d::d3dBuildingShader::vfunc_11 (6 B): matches/0x003322f0.cpp
// sym: ?vfunc_11@d3dBuildingShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dBuildingShader::vfunc_11() {
    return 1;
}

namespace fn_fd7d5ddc {

// 0x00332300 pure3d::d3dBuildingShader::vfunc_23 (6 B): matches/0x00332300.cpp
// sym: _FUN_00332300
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00332300() {
    return &(*(int*)&DAT_003f335c);
}

} // namespace fn_fd7d5ddc

// 0x00332310 pure3d::d3dBuildingShader::vfunc_14 (752 B): equivalent/0x00332310.cpp [wrapped: conflict: pure3d::d3dBuildingShader]
// sym: ?vfunc_14@d3dBuildingShader@pure3d@fn_00332310@@QAEXI@Z
namespace fn_00332310 {
// STATUS: equivalent (tools/equiv.py level 3: 2952 inputs, branch coverage 45/45)
// pure3d::d3dBuildingShader::vfunc_14 @ 0x00332310
// pure3d::d3dBuildingShader::vfunc_14 @ 0x00332310

namespace D3D8 { void __stdcall D3DDevice_SetTexture(unsigned int, void*); void __stdcall D3DDevice_SetPalette(unsigned int, unsigned int); void __stdcall D3DDevice_SetTextureState_TexCoordIndex(unsigned int, unsigned int); void __fastcall D3DDevice_SetRenderState_Simple(unsigned int, unsigned int); }
extern unsigned int DAT_0039db08; extern unsigned int DAT_0039db4c[]; extern unsigned int DAT_0039db64[]; extern unsigned int DAT_0039de18; 
struct Texture { void FUN_00326b00(unsigned int); };
struct Context { char pad0[8]; Texture* textures[4]; unsigned int coord[4]; char pad28[0x20]; unsigned int renderMode; char pad4c[0x48]; unsigned int filter[4]; char padA4[0x50]; unsigned int coordMode[4]; void FUN_00329cf0(unsigned int,unsigned int,unsigned int); void FUN_00329da0(unsigned int,unsigned int,unsigned int); void FUN_00329d50(unsigned int,unsigned int,unsigned int,unsigned int); void FUN_00329c40(unsigned int,unsigned int); void FUN_00329c90(unsigned int,unsigned int); void FUN_00329f20(unsigned int); void FUN_00329bb0(unsigned int); void FUN_00329f70(unsigned int,unsigned int,void*); };
namespace pure3d { struct d3dBuildingShader { char pad0[0x14]; Context* context; char pad18[4]; unsigned int effect; char pad20[0x18]; unsigned int intensity; char pad3c[8]; unsigned int texCoord; unsigned char disabled; char pad49[3]; unsigned int renderMode; unsigned int color[11]; unsigned char flag; char pad7d[3]; Texture* base; Texture* detail; Texture* extra; unsigned char skipDetail; void FUN_0032a320(unsigned int,unsigned int); void FUN_0032a260(); void vfunc_14(unsigned int); }; }
void pure3d::d3dBuildingShader::vfunc_14(unsigned int) {
 unsigned int stage=0; const unsigned int two=2;
 if(base) {
  Context* c=context; c->FUN_00329cf0(0,4,0);
  if(c->filter[0]!=two) { c->filter[0]=two; DAT_0039db08|=0x800; DAT_0039db4c[0]=two; }
  context->FUN_00329da0(0,two,two);
  c=context; Texture* t=base;
  if(c->textures[0]!=t) { c->textures[0]=t; if(t) t->FUN_00326b00(0); else { D3D8::D3DDevice_SetTexture(0,0); D3D8::D3DDevice_SetPalette(0,0); } }
  FUN_0032a320(0,0); stage=1;
 }
 if(extra && !skipDetail) {
  context->FUN_00329d50(stage,0x14,1,two);
  context->FUN_00329da0(stage,two,1);
  Context* c=context; Texture* t=extra;
  if(c->textures[stage]!=t) { c->textures[stage]=t; if(t) t->FUN_00326b00(stage); else { D3D8::D3DDevice_SetTexture(stage,0); D3D8::D3DDevice_SetPalette(stage,0); } }
  FUN_0032a320(stage,0); ++stage;
 }
 if(detail) {
  Context* c=context; c->FUN_00329cf0(stage,0x14,1);
  if(c->filter[stage]!=two) { c->filter[stage]=two; DAT_0039db08|=0x800; DAT_0039db4c[stage*32]=two; }
  context->FUN_00329da0(stage,two,1);
  c=context; Texture* t=detail;
  if(c->textures[stage]!=t) { c->textures[stage]=t; if(t) t->FUN_00326b00(stage); else { D3D8::D3DDevice_SetTexture(stage,0); D3D8::D3DDevice_SetPalette(stage,0); } }
  c=context; if(c->coord[stage]!=0x30000) { c->coord[stage]=0x30000; D3D8::D3DDevice_SetTextureState_TexCoordIndex(stage,0x30000); }
  c=context; if(c->coordMode[stage]!=two) { c->coordMode[stage]=two; DAT_0039db08|=0x400; DAT_0039db64[stage*32]=two; }
  context->FUN_00329c40(stage,1); context->FUN_00329c90(stage,texCoord); ++stage;
 }
 if(!disabled && intensity && effect>=1 && effect<=7 && effect!=6) {
  unsigned int v=intensity;
  if(effect==1 || effect==7) { context->FUN_00329cf0(stage,two,1); context->FUN_00329f20((0xffffffffu-intensity)<<24); context->FUN_00329da0(stage,two,3); }
  else { unsigned int x=(effect==2 || effect==3)?(255-v):v; unsigned int rgb=(x<<16)|(x<<8)|x; context->FUN_00329f20(rgb); context->FUN_00329d50(stage,4,1,3); context->FUN_00329da0(stage,two,1); }
  Context* c=context; if(c->textures[stage]) { c->textures[stage]=0; D3D8::D3DDevice_SetTexture(stage,0); D3D8::D3DDevice_SetPalette(stage,0); }
  FUN_0032a320(stage,0); ++stage;
 }
 context->FUN_00329bb0(stage);
 Context* c=context; if(c->renderMode!=renderMode) { c->renderMode=renderMode; unsigned int val=((unsigned int*)&DAT_004d4f24)[renderMode]; D3D8::D3DDevice_SetRenderState_Simple(0x4037c,val); DAT_0039de18=val; }
 context->FUN_00329f70(disabled,flag,color); FUN_0032a260();
}
} // namespace fn_00332310


// 0x00332620 pure3d::d3dBuildingShader::vfunc_12 (164 B): matches/0x00332620.cpp
// sym: ?vfunc_12@d3dBuildingShader@pure3d@@UAEXXZ
void pure3d::d3dBuildingShader::vfunc_12() {
    (*(Dev_332620 * *)&this->f_10)->SetState(3);
    float m[16];
    m[0] = 0.5f;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0.5f;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1.0f;
    m[11] = 0;
    m[12] = 0.5f;
    m[13] = 0.5f;
    m[14] = 0;
    m[15] = 1.0f;
    (*(Dev_332620 * *)&this->f_10)->SetTransform(3, m);
}


// 0x003326d0 pure3d::d3dBuildingShader::vfunc_13 (117 B): matches/0x003326d0.cpp
// sym: ?vfunc_13@d3dBuildingShader@pure3d@@UAEXXZ
void pure3d::d3dBuildingShader::vfunc_13() {
    if ((*(Dev_3326d0 * *)&this->f_14)->s != 1) {
        (*(Dev_3326d0 * *)&this->f_14)->s = 1;
        g_dirty |= 0x800;
        g_a_3326d0 = 1;
    }
    if ((*(Dev_3326d0 * *)&this->f_14)->tc != 2) {
        (*(Dev_3326d0 * *)&this->f_14)->tc = 2;
        SetTC(2, 2);
    }
    if ((*(Dev_3326d0 * *)&this->f_14)->t != 0) {
        (*(Dev_3326d0 * *)&this->f_14)->t = 0;
        g_dirty |= 0x400;
        g_b_3326d0 = 0;
    }
    (*(Sub_3326d0 * *)&this->f_10)->Set(3);
}

namespace fn_fd7d5ddc {

// 0x00332750 FUN_00332750 (44 B): matches/0x00332750.cpp
// sym: ?Set@Holder@fn_fd7d5ddc@@QAEXPAVObj@2@@Z
void Holder::Set(Obj* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}

} // namespace fn_fd7d5ddc

// 0x00332780 FUN_00332780 (44 B): matches/0x00332780.cpp [wrapped: same definition as 0x00332750 in this TU]
// sym: ?Set@Holder@fn_00332780@@QAEXPAVObj@2@@Z
namespace fn_00332780 {
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
void Holder::Set(Obj* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}
} // namespace fn_00332780

namespace fn_fd7d5ddc {

// 0x003327b0 FUN_003327b0 (44 B): matches/0x003327b0.cpp
// sym: ?Set@Obj@fn_fd7d5ddc@@QAEXPAVRef@2@@Z
void Obj::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ref)
        ref->Release();
    ref = p;
}


// 0x003327e0 FUN_003327e0 (18 B): matches/0x003327e0.cpp
// sym: ?Set@Obj_3327e0@fn_fd7d5ddc@@QAEXPAX@Z
void Obj_3327e0::Set(void* p) {
    f4[0x8c] = (p != 0) ? 1 : 0;
}


// 0x00332800 FUN_00332800 (51 B): matches/0x00332800.cpp
// sym: ?Target@d3dBuildingShader_332800@fn_fd7d5ddc@@QAEPAV12@H@Z
d3dBuildingShader_332800* d3dBuildingShader_332800::Target(int arg) {
    BaseCtor(arg);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433eec);
    return this;
}


// 0x00332840 pure3d::d3dBuildingShader::vfunc_3 (83 B): matches/0x00332840.cpp
// sym: ??0d3dBuildingShader_332840@fn_fd7d5ddc@@QAE@E@Z
d3dBuildingShader_332840::d3dBuildingShader_332840(unsigned char flag) {
    if (a)
        a->f1();
    if (b)
        b->f1();
    if (c)
        c->f1();
    cleanup();
    if (flag & 1)
        destroy(this);
}

} // namespace fn_fd7d5ddc
