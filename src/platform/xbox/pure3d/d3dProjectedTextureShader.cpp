// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032ca50..0x0032d0f0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dProjectedTextureShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f81ca26d {
#define TREE_TU_END }
namespace fn_f81ca26d {} using namespace fn_f81ca26d;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
extern "C" void _ReadWriteBarrier();
namespace fn_f81ca26d {
extern void* g_vftable_32ca50[];
extern void* g_vftable2[];
} // namespace fn_f81ca26d
void operator delete(void*);
namespace fn_f81ca26d {
class Ref_32ca50 {
  public:
    virtual void F0();
    virtual void Release();
};
class d3dShader_32ca50 {
  public:
    void* vptr;
    void Fin();
};
class d3dProjectedTextureShader_32ca50 : public d3dShader_32ca50 {
  public:
    char pad[0x7c];
    Ref_32ca50* m80;
    Ref_32ca50* m84;
    ~d3dProjectedTextureShader_32ca50();
};
class pddiObject_32cae0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32cae0 : public pddiObject_32cae0 {};
class pddiBaseShader_32cae0 : public pddiShader_32cae0 {
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
class d3dShader_32cae0 : public pddiBaseShader_32cae0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class d3dShader {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};
class Param {
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
    virtual void f14(int, void*);
    virtual void f15(int);
};
class d3dProjectedTextureShader_32caf0 : public d3dShader {
  public:
    char pad[0x10 - sizeof(d3dShader)];
    Param* p;
    char rest[0x88 - 0x14];
    void vfunc_12();
};
class Texture {
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
    virtual void f16(int);
};
class d3dProjectedTextureShader : public d3dShader {
  public:
    char pad[0x10 - sizeof(d3dShader)];
    Texture* texture;
    void vfunc_13();
};
class Obj {
    char pad[0x80];
    Ref* p;

  public:
    void Set(Ref* q);
};
class Owner {
    char pad[0x84];
    Ref* p;

  public:
    void Set(Ref* q);
};
struct Block_32cba0 {
    unsigned int x[16];
};
class Thing_32cba0 {
    char pad[0x88];

  public:
    void Copy(Block_32cba0* src);
};
extern "C" char DAT_00433a8c[];
struct d3dProjectedTextureShader_nv_32cbc0 {
    void InitBase(void*);
    void InitMember();
};
class Ref_32cc00 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_32cc00;
class d3dProjectedTextureShader_32cc00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dProjectedTextureShader_32cc00* vfunc_3(unsigned int);
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
    Ref_32cc00* a;
    Ref_32cc00* b;
};
void __cdecl destroy(d3dProjectedTextureShader_32cc00*);
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(unsigned long stage, unsigned long value);
}
namespace D3D8 {
void __fastcall D3DDevice_SetRenderState_Simple(unsigned long method, unsigned long value);
}
struct StageRegs_32cc50 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    char pad0c[0x54 - 0x0c];
    unsigned int d;
    char pad58[0x80 - 0x58];
};
extern unsigned int DAT_0039db08;
extern StageRegs_32cc50 DAT_0039db10[];
class Texture;
class DeviceState_32cc50 {
public:
    char pad0[0x18];
    int texCoord0;
    int texCoord1;
    char pad20[0x28 - 0x20];
    int blend0;
    int blend1;
    char pad30[0x48 - 0x30];
    int renderMode;
    char pad4c[0xf4 - 0x4c];
    int colorOp0;
    int colorOp1;
    void FUN_0032a920(int mode, Texture* t0, Texture* t1, Texture* t2, Texture* t3);
    void FUN_00329f70(int a, int b, const void* p);
};
class d3dProjectedTextureShader;
class d3dShader_32cc50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(int arg);
};
class d3dProjectedTextureShader_32cc50 : public d3dShader_32cc50 {
public:
    char pad04[0x14 - 4];
    DeviceState_32cc50* dev;
    char pad18[0x44 - 0x18];
    int stageValue;
    unsigned char byte48;
    char pad49[0x4c - 0x49];
    int renderIndex;
    char matrix[0x7c - 0x50];
    unsigned char byte7c;
    char pad7d[0x80 - 0x7d];
    Texture* tex0;
    Texture* tex1;
    void FUN_0032a260();
    virtual void vf14(int arg);
};


// 0x0032ca50 FUN_0032ca50 (47 B): matches/0x0032ca50.cpp
// sym: ??1d3dProjectedTextureShader_32ca50@fn_f81ca26d@@QAE@XZ
d3dProjectedTextureShader_32ca50::~d3dProjectedTextureShader_32ca50() {
    Ref_32ca50* a = m80;
    vptr = ((void**)DAT_00433a8c);
    if (a)
        a->Release();
    if (m84)
        m84->Release();
    Fin();
}


// 0x0032ca80 pure3d::d3dProjectedTextureShader::vfunc_15 (6 B): matches/0x0032ca80.cpp
// sym: _FUN_0032ca80
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ca80() {
    return &(*(int*)&DAT_004d8148);
}


// 0x0032ca90 pure3d::d3dProjectedTextureShader::vfunc_16 (6 B): matches/0x0032ca90.cpp
// sym: _FUN_0032ca90
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032ca90() {
    return &(*(int*)&DAT_004d8208);
}


// 0x0032caa0 pure3d::d3dProjectedTextureShader::vfunc_17 (6 B): matches/0x0032caa0.cpp
// sym: _FUN_0032caa0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032caa0() {
    return &(*(int*)&DAT_004d80e8);
}


// 0x0032cab0 pure3d::d3dProjectedTextureShader::vfunc_18 (6 B): matches/0x0032cab0.cpp
// sym: _FUN_0032cab0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032cab0() {
    return &(*(int*)&DAT_004d8190);
}


// 0x0032cac0 pure3d::d3dProjectedTextureShader::vfunc_20 (6 B): matches/0x0032cac0.cpp
// sym: _FUN_0032cac0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032cac0() {
    return &(*(int*)&DAT_004d80b8);
}


// 0x0032cad0 pure3d::d3dProjectedTextureShader::vfunc_4 (6 B): matches/0x0032cad0.cpp
// sym: _FUN_0032cad0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032cad0() {
    return &(*(int*)&DAT_004d80a0);
}

} // namespace fn_f81ca26d

// 0x0032cae0 pure3d::d3dProjectedTextureShader::vfunc_11 (6 B): matches/0x0032cae0.cpp
// sym: ?vfunc_11@d3dProjectedTextureShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dProjectedTextureShader::vfunc_11() {
    return 1;
}

namespace fn_f81ca26d {

// 0x0032caf0 pure3d::d3dProjectedTextureShader::vfunc_12 (37 B): matches/0x0032caf0.cpp
// sym: ?vfunc_12@d3dProjectedTextureShader_32caf0@fn_f81ca26d@@UAEXXZ
void d3dProjectedTextureShader_32caf0::vfunc_12() {
    d3dShader::vfunc_12();
    p->f15(2);
    p->f14(2, (char*)this + 0x88);
}


// 0x0032cb20 pure3d::d3dProjectedTextureShader::vfunc_13 (21 B): matches/0x0032cb20.cpp
// sym: ?vfunc_13@d3dProjectedTextureShader@fn_f81ca26d@@UAEXXZ
void d3dProjectedTextureShader::vfunc_13() {
    texture->f16(2);
    d3dShader::vfunc_13();
}


// 0x0032cb40 FUN_0032cb40 (44 B): matches/0x0032cb40.cpp
// sym: ?Set@Obj@fn_f81ca26d@@QAEXPAVRef@2@@Z
void Obj::Set(Ref* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}


// 0x0032cb70 FUN_0032cb70 (44 B): matches/0x0032cb70.cpp
// sym: ?Set@Owner@fn_f81ca26d@@QAEXPAVRef@2@@Z
void Owner::Set(Ref* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}


// 0x0032cba0 FUN_0032cba0 (24 B): matches/0x0032cba0.cpp
// sym: ?Copy@Thing_32cba0@fn_f81ca26d@@QAEXPAUBlock_32cba0@2@@Z
void Thing_32cba0::Copy(Block_32cba0* src) {
    *(Block_32cba0*)((char*)this + 0x88) = *src;
}

} // namespace fn_f81ca26d

// 0x0032cbc0 FUN_0032cbc0 (50 B): matches/0x0032cbc0.cpp
// sym: ?FUN_0032cbc0@d3dProjectedTextureShader@pure3d@@QAEPAV12@PAX@Z
pure3d::d3dProjectedTextureShader* pure3d::d3dProjectedTextureShader::FUN_0032cbc0(void* arg) {
    ((d3dProjectedTextureShader_nv_32cbc0*)this)->InitBase(arg);
    *(void**)this = (void*)((hulk_intptr)DAT_00433a8c);
    (*(int *)&this->f_80) = 0;
    (*(int *)&this->f_84) = 0;
    ((d3dProjectedTextureShader_nv_32cbc0*)(void*)this->f_88)->InitMember();   // (x64t8) the matrix (gen's f_88; was `this + 0x88`)
    return (d3dProjectedTextureShader*)(this);
}

namespace fn_f81ca26d {

// 0x0032cc00 pure3d::d3dProjectedTextureShader::vfunc_3 (68 B): matches/0x0032cc00.cpp
// sym: ?vfunc_3@d3dProjectedTextureShader_32cc00@fn_f81ca26d@@UAEPAV12@I@Z
// Same code shape as 0x0032ba70 (propagated; names are from that function)
d3dProjectedTextureShader_32cc00* d3dProjectedTextureShader_32cc00::vfunc_3(unsigned int x) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32cc00;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}


// 0x0032cc50 pure3d::d3dProjectedTextureShader::vfunc_14 (379 B): equivalent/0x0032cc50.cpp
// sym: ?vf14@d3dProjectedTextureShader_32cc50@fn_f81ca26d@@UAEXH@Z @5bcc82886e49 @w4aa7949ff387
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 14/14)
// pure3d::d3dProjectedTextureShader::vfunc_14 @ 0x0032cc50
void d3dProjectedTextureShader_32cc50::vf14(int arg) {
    dev->FUN_0032a920(2, tex0, tex1, 0, 0);
    ((owners::Obj_329e50 *)dev)->FUN_00329e50(0, 4, 1, 2);
    if (dev->texCoord0 != 0) {
        dev->texCoord0 = 0;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(0, 0);
    }
    if (dev->colorOp0 != 0) {
        dev->colorOp0 = 0;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[0].d = 0;
    }
    if (dev->blend0 != 0) {
        dev->blend0 = 0;
        DAT_0039db10[0].a = (*(unsigned int*)&DAT_004d4efc);
        DAT_0039db10[0].b = (*(unsigned int*)&DAT_004d4efc);
        DAT_0039db08 |= 1;
        DAT_0039db10[0].c = (*(unsigned int*)&DAT_004d4efc);
    }
    ((owners::Obj_329c90 *)dev)->FUN_00329c90(0, stageValue);
    ((owners::Obj_329e50 *)dev)->FUN_00329e50(1, 4, 1, 2);
    if (dev->texCoord1 != 0x20000) {
        dev->texCoord1 = 0x20000;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 0x20000);
    }
    if (dev->colorOp1 != 0x103) {
        dev->colorOp1 = 0x103;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[1].d = 0x103;
    }
    if (dev->blend1 != 1) {
        dev->blend1 = 1;
        DAT_0039db10[1].a = (*(unsigned int*)((char*)&DAT_004d4efc + 4));
        DAT_0039db10[1].b = (*(unsigned int*)((char*)&DAT_004d4efc + 4));
        DAT_0039db08 |= 2;
        DAT_0039db10[1].c = (*(unsigned int*)((char*)&DAT_004d4efc + 4));
    }
    ((owners::Obj_329c90 *)dev)->FUN_00329c90(1, stageValue);
    if (renderIndex != dev->renderMode) {
        dev->renderMode = renderIndex;
        unsigned int value = ((unsigned int*)&DAT_004d4f24)[renderIndex];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, value);
        DAT_0039de18 = value;
    }
    dev->FUN_00329f70(byte48, byte7c, matrix);
    FUN_0032a260();
}

} // namespace fn_f81ca26d
