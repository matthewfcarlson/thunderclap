// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032e830..0x0032ee30 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dLayeredLMapShader
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff3206d0 {
#define TREE_TU_END }
namespace fn_ff3206d0 {} using namespace fn_ff3206d0;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff3206d0 {
struct Ref_32e840 {
    virtual void f();
    virtual void Release();
};
struct d3dLayeredShader_32e840 {
    virtual void f();
    void dtorBase();
};
struct d3dLayeredLMapShader_32e840 : d3dLayeredShader_32e840 {
    char pad[0x9c - 4];
    Ref_32e840* m;
    virtual ~d3dLayeredLMapShader_32e840();
};
class pddiObject_32e870 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32e870 : public pddiObject_32e870 {};
class pddiBaseShader_32e870 : public pddiShader_32e870 {
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
class d3dShader_32e870 : public pddiBaseShader_32e870 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
class Owner {
    char pad[0x9c];
    Obj* ptr;

  public:
    void Set(Obj* p);
};
struct Ref_32eb40 {
    virtual void f0();
    virtual void f1();
};
extern void* vtable_32eb40;
struct d3dLayeredLMapShader_32eb40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual d3dLayeredLMapShader_32eb40* vfunc_3(unsigned int);
    char pad[0x98];
    Ref_32eb40* ref;
    void helper();
};
void thunk_FUN_00267090(d3dLayeredLMapShader_32eb40*);


// 0x0032e830 pure3d::d3dLayeredLMapShader::vfunc_15 (6 B): matches/0x0032e830.cpp
// sym: _FUN_0032e830
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032e830() {
    return &(*(int*)&DAT_004d8798);
}


// 0x0032e840 FUN_0032e840 (32 B): matches/0x0032e840.cpp
// sym: ??1d3dLayeredLMapShader_32e840@fn_ff3206d0@@UAE@XZ
d3dLayeredLMapShader_32e840::~d3dLayeredLMapShader_32e840() {
    if (m)
        m->Release();
    d3dLayeredShader_32e840::dtorBase();
}


// 0x0032e860 pure3d::d3dLayeredLMapShader::vfunc_4 (6 B): matches/0x0032e860.cpp
// sym: _FUN_0032e860
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032e860() {
    return &(*(int*)&DAT_004d877c);
}

} // namespace fn_ff3206d0

// 0x0032e870 pure3d::d3dLayeredLMapShader::vfunc_11 (6 B): matches/0x0032e870.cpp
// sym: ?vfunc_11@d3dLayeredLMapShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dLayeredLMapShader::vfunc_11() {
    return 1;
}


// 0x0032e880 pure3d::d3dLayeredLMapShader::vfunc_23 (48 B): matches/0x0032e880.cpp
// sym: ?vfunc_23@d3dLayeredLMapShader@pure3d@@UAEPAXXZ
// data: multiName = DAT_00433794, proximityName = DAT_00433778, zeroName = DAT_003f335c
void* pure3d::d3dLayeredLMapShader::vfunc_23() {
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_90))
        return (void*)(DAT_00433794);
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_91))
        return (void*)(DAT_00433778);
    return (void*)(((const char*)&DAT_003f335c));
}


// 0x0032e8b0 pure3d::d3dLayeredLMapShader::vfunc_14 (567 B): equivalent/0x0032e8b0.cpp [wrapped: conflict: pure3d::d3dLayeredLMapShader]
// sym: ?vfunc_14@d3dLayeredLMapShader@pure3d@fn_0032e8b0@@UAEXH@Z
namespace fn_0032e8b0 {
// STATUS: equivalent (tools/equiv.py level 3: 19759 inputs, branch coverage 35/35)
// pure3d::d3dLayeredLMapShader::vfunc_14 @ 0x0032e8b0

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
struct TextureState_32e8b0 {
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
class d3dLayeredLMapShader {
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
    TextureState_32e8b0* state;
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
    Texture* tex0;
    Texture* tex1;
    int tex1Kind;
    char pad8c[0x9c - 0x8c];
    Texture* tex2;
    void FUN_0032a320(int stage, int coord);
    void FUN_0032b530(int, int, int);
    int FUN_0032da40(int);
    void FUN_0032a260();
};
}
void pure3d::d3dLayeredLMapShader::vfunc_14(int unused) {
    int n = 0;
    if (tex0) {
        state->FUN_00329e50(0, 4, 0, 2);
        if (tex0 != state->tex[0]) {
            state->tex[0] = tex0;
            if (tex0) {
                tex0->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        FUN_0032a320(0, 0);
        n = 1;
    }
    if (tex1) {
        int kind = FUN_0032da40(tex1Kind);
        state->FUN_00329e50(n, kind, 1, 2);
        if (tex1 != state->tex[n]) {
            state->tex[n] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(n);
            } else {
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
        }
        FUN_0032b530(n, 1, 0);
        n++;
    }
    if (tex2) {
        state->FUN_00329e50(n, 4, 1, 2);
        if (tex2 != state->tex[n]) {
            state->tex[n] = tex2;
            if (tex2) {
                tex2->FUN_00326b00(n);
            } else {
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
        }
        FUN_0032b530(n, 2, 0);
        n++;
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
    state->FUN_00329bb0(n);
    if (renderMode != state->renderMode) {
        state->renderMode = renderMode;
        unsigned int v = ((unsigned int*)&DAT_004d4f24)[renderMode];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    state->FUN_00329f70(flag, flag7c, params);
    FUN_0032a260();
}
} // namespace fn_0032e8b0

namespace fn_ff3206d0 {

// 0x0032eb10 FUN_0032eb10 (44 B): matches/0x0032eb10.cpp
// sym: ?Set@Owner@fn_ff3206d0@@QAEXPAVObj@2@@Z
void Owner::Set(Obj* p) {
    if (p)
        p->Add();
    if (ptr)
        ptr->Release();
    ptr = p;
}


// 0x0032eb40 pure3d::d3dLayeredLMapShader::vfunc_3 (53 B): matches/0x0032eb40.cpp
// sym: ?vfunc_3@d3dLayeredLMapShader_32eb40@fn_ff3206d0@@UAEPAU12@I@Z
d3dLayeredLMapShader_32eb40* d3dLayeredLMapShader_32eb40::vfunc_3(unsigned int flags) {
    *(void**)this = &vtable_32eb40;
    if (ref)
        ref->f1();
    helper();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ff3206d0
