// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032b0a0..0x0032b530 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dErrorShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f3c6e97b {
#define TREE_TU_END }
namespace fn_f3c6e97b {} using namespace fn_f3c6e97b;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f3c6e97b {
class pddiObject_32b0b0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32b0b0 : public pddiObject_32b0b0 {};
class pddiBaseShader_32b0b0 : public pddiShader_32b0b0 {
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
class d3dShader_32b0b0 : public pddiBaseShader_32b0b0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};


// 0x0032b0a0 pure3d::d3dErrorShader::vfunc_4 (6 B): matches/0x0032b0a0.cpp
// sym: _FUN_0032b0a0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032b0a0() {
    return &(*(int*)&DAT_004d7bc8);
}

} // namespace fn_f3c6e97b

// 0x0032b0b0 pure3d::d3dErrorShader::vfunc_11 (6 B): matches/0x0032b0b0.cpp
// sym: ?vfunc_11@d3dErrorShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dErrorShader::vfunc_11() {
    return 1;
}


// 0x0032b0c0 FUN_0032b0c0 (50 B): matches/0x0032b0c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Make@Obj_32b0c0@fn_0032b0c0@@QAEPAV12@PAX@Z
namespace fn_0032b0c0 {
extern "C" char DAT_004338f4[];
class d3dErrorShader_32b0c0 {
  public:
    void Init(void*);
};
class Obj_32b0c0 {
  public:
    virtual void f();
    Obj_32b0c0* Make(void* arg);
    unsigned char pad[0x5c];
};
void Obj_32b0c0::f() {}
Obj_32b0c0* Obj_32b0c0::Make(void* arg) {
    ((d3dErrorShader_32b0c0*)this)->Init(arg);
    *(unsigned int*)((char*)this + 0x58) = 0xff000000;
    *(unsigned int*)((char*)this + 0x50) = 0xff000000;
    *(unsigned int*)((char*)this + 0x54) = 0xff000000;
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004338f4);
    *(unsigned char*)((char*)this + 0x48) = 1;
    *(unsigned int*)((char*)this + 0x5c) = 0xffff80ff;
    return this;
}
} // namespace fn_0032b0c0


// 0x0032b100 pure3d::d3dErrorShader::vfunc_3 (30 B): matches/0x0032b100.cpp
// sym: ??_Gd3dErrorShader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::d3dErrorShader::~d3dErrorShader() {}


// 0x0032b120 pure3d::d3dErrorShader::vfunc_14 (236 B): equivalent/0x0032b120.cpp [wrapped: conflict: pure3d::d3dErrorShader]
// sym: ?vfunc_14@d3dErrorShader@pure3d@fn_0032b120@@UAEXH@Z @cca86ac61996 @we99317246b4c
namespace fn_0032b120 {
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 14/14)
// pure3d::d3dErrorShader::vfunc_14 @ 0x0032b120

struct MatSrc {
    unsigned int diffuse;
    unsigned int specular;
    unsigned int ambient;
    unsigned int emissive;
    float power;
};
struct Texture;
struct Context {
    char pad00[8];
    Texture* tex0;
    Texture* tex1;
    Texture* tex2;
    Texture* tex3;
    char pad18[0x48 - 0x18];
    unsigned int mode;
    char pad4c[0x64 - 0x4c];
    int f64;
    char pad68[0x74 - 0x68];
    int f74;
    void FUN_00329f70(unsigned char enable, unsigned char two, MatSrc* src);
};
extern void __stdcall D3DDevice_SetTexture(int stage, Texture* tex);
extern void __stdcall D3DDevice_SetPalette(int stage, void* palette);
extern void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039db40;
extern unsigned int DAT_0039db50;
extern unsigned int DAT_0039de18;

namespace pure3d {
class d3dErrorShader {
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
    char pad04[0x10];
    Context* ctx;
    char pad18[0x48 - 0x18];
    unsigned char blend;
    char pad49[3];
    unsigned int mode;
    MatSrc material;
    char pad64[0x7c - 0x64];
    unsigned char twoSided;
};
void d3dErrorShader::vfunc_14(int unused) {
    Context* c = ctx;
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
    if (c->tex3) {
        c->tex3 = 0;
        D3DDevice_SetTexture(3, 0);
        D3DDevice_SetPalette(3, 0);
    }
    if (c->f64 != 1) {
        c->f64 = 1;
        DAT_0039db08 = DAT_0039db08 | 0x800;
        DAT_0039db40 = 1;
    }
    if (c->f74 != 1) {
        c->f74 = 1;
        DAT_0039db08 = DAT_0039db08 | 0x800;
        DAT_0039db50 = c->f64;
    }
    if (mode != ctx->mode) {
        ctx->mode = mode;
        unsigned int value = ((unsigned int*)&DAT_004d4f24)[mode];
        D3DDevice_SetRenderState_Simple(0x4037c, value);
        DAT_0039de18 = value;
    }
    ctx->FUN_00329f70(blend, twoSided, &material);
}
}
} // namespace fn_0032b120

