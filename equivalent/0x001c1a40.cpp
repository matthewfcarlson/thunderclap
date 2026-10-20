// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 24/24)
// FUN_001c1a40 @ 0x001c1a40
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/Render/Canvas.h"
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);
void* thunk_FUN_0008d690(unsigned int size);

namespace pure3d {
class pddiExtension {
  public:
    virtual void v0();
};
class pddiExtFramebufferEffects : public pddiExtension {
  public:
    virtual void v1();
};
class GameDrawableInfo {
  public:
    virtual void v0();
    int field4;
    GameDrawableInfo() { field4 = 0; }
};
}

class Base_1c1a40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(float x);
    virtual void v8();
    virtual void v9(float x);
};
struct Child_1c1a40 : public Base_1c1a40 {
};
struct Owner_1c1a40 : public Base_1c1a40 {
    Owner_1c1a40* FUN_0029bea0(int a, int b);
    void FUN_0029b690(Base_1c1a40* child);
};
struct Root_1c1a40 : public Base_1c1a40 {
    char pad[0x2c - 4];
    int field2c;
    Root_1c1a40* FUN_00294880();
    void FUN_00294980(Base_1c1a40* other);
};
struct ObjA_1c1a40 : public Base_1c1a40 { char pad[0x1c - 4]; char flag; ObjA_1c1a40* FUN_002a2d50(int n); };
struct ObjB_1c1a40 : public Base_1c1a40 { ObjB_1c1a40* FUN_002a2130(int n); };
struct ObjC_1c1a40 : public Base_1c1a40 { ObjC_1c1a40* FUN_002a16c0(int n, int m); };
struct ObjD : public Base_1c1a40 { ObjD* FUN_0029f600(int a, int b); void FUN_0029f800(Base_1c1a40* o); };
struct ObjE : public Base_1c1a40 { ObjE* FUN_002a1140(int n); };
struct ObjF : public Base_1c1a40 { ObjF* FUN_002a1230(); void FUN_002a07a0(unsigned int color); };
struct ObjG : public Base_1c1a40 { ObjG* FUN_00292d70(); };

void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

class Display_1c1a40 {
  public:
    virtual void v0();
};
class Gfx {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual pure3d::pddiExtension* s89(int id);
};

struct Plane_1c1a40 { float a, b, c, d; };

class SubObj_1c1a40 {
  public:
    char pad0[4];
    Plane_1c1a40 planes[6];
    char pad70[0xac - 0x64];
    void FUN_001c2760();
    void FUN_001c2770(int a, int b);
};

class Hud_1c1a40 {
  public:
    int field0;
    Root_1c1a40* root;
    ObjG* objG;
    SubObj_1c1a40 sub;
    int fieldb8;
    Owner_1c1a40* owner;
    ObjD* objc0;
    ObjD* objc4;
    ObjE* objc8;
    char padcc[3];
    char flagcf;
    int fieldd0;
    int fieldd4;
    char flagd8;
    char flagd9;
    char paddc[2];
    unsigned int colordc;
    char pade0[4];
    float fe4;
    float fe8;
    unsigned int colorec;
    ObjC_1c1a40* objf0;
    int ff4[6];
    Hud_1c1a40* FUN_001c1a40();
};

Hud_1c1a40* Hud_1c1a40::FUN_001c1a40() {
    field0 = 0;
    sub.FUN_001c2760();
    fieldb8 = 0;
    flagcf = 1;
    fieldd0 = 0;
    fieldd4 = 0;
    flagd8 = 1;
    flagd9 = 1;
    colordc = 0xff808080;
    fe4 = 50.0f;
    fe8 = 650.0f;
    colorec = 0xffcfcfcf;
    sub.FUN_001c2770(6, 0);
    sub.planes[0].a = 0; sub.planes[0].b = 0; sub.planes[0].c = -1.0f; sub.planes[0].d = 0;
    sub.planes[1].a = 0; sub.planes[1].b = 0; sub.planes[1].c = 1.0f; sub.planes[1].d = -1.0f;
    sub.planes[2].a = 0; sub.planes[2].b = -1.0f; sub.planes[2].c = 0; sub.planes[2].d = 0;
    sub.planes[3].a = 0; sub.planes[3].b = 1.0f; sub.planes[3].c = 0; sub.planes[3].d = -1.0f;
    sub.planes[4].a = -1.0f; sub.planes[4].b = 0; sub.planes[4].c = 0; sub.planes[4].d = 0;
    sub.planes[5].a = 1.0f; sub.planes[5].b = 0; sub.planes[5].c = 0; sub.planes[5].d = -1.0f;
    for (int i = 0; i < 6; i++)
        ff4[i] = 0;

    void* mem = thunk_FUN_0008d690(0x38);
    Owner_1c1a40* o = 0;
    if (mem)
        o = ((Owner_1c1a40*)mem)->FUN_0029bea0(3, 0x400);
    owner = o;
    o->v0();

    mem = FUN_0008d690(0x38);
    ObjA_1c1a40* a = 0;
    if (mem)
        a = ((ObjA_1c1a40*)mem)->FUN_002a2d50(0x400);
    owner->FUN_0029b690(a);
    a->flag = 1;

    mem = FUN_0008d690(0x34);
    ObjB_1c1a40* b = 0;
    if (mem)
        b = ((ObjB_1c1a40*)mem)->FUN_002a2130(0x400);
    owner->FUN_0029b690(b);

    mem = FUN_0008d690(0x48);
    ObjC_1c1a40* c = 0;
    if (mem)
        c = ((ObjC_1c1a40*)mem)->FUN_002a16c0(0x100, (*(int*)&DAT_0042d5fc));
    objf0 = c;
    owner->FUN_0029b690(c);

    mem = thunk_FUN_0008d690(0x58);
    ObjD* d = 0;
    if (mem)
        d = ((ObjD*)mem)->FUN_0029f600((*(int*)&DAT_0042d5f8), (*(int*)&DAT_0042d5fc));
    objc0 = d;
    d->v0();

    mem = thunk_FUN_0008d690(0x58);
    d = 0;
    if (mem)
        d = ((ObjD*)mem)->FUN_0029f600((*(int*)&DAT_0042d5f8), (*(int*)&DAT_0042d5fc));
    objc4 = d;
    d->v0();

    mem = thunk_FUN_0008d690(0x28);
    ObjE* e = 0;
    if (mem)
        e = ((ObjE*)mem)->FUN_002a1140(2);
    objc8 = e;
    e->v0();

    mem = thunk_FUN_0008d690(0x58);
    ObjF* f = 0;
    if (mem)
        f = ((ObjF*)mem)->FUN_002a1230();
    f->v0();
    f->FUN_002a07a0(0xff4b4b4b);
    objc4->FUN_0029f800(f);
    f->v1();

    mem = thunk_FUN_0008d690(0x58);
    f = 0;
    if (mem)
        f = ((ObjF*)mem)->FUN_002a1230();
    f->v0();
    f->FUN_002a07a0(0xff4b4b4b);
    objc0->FUN_0029f800(f);
    f->v1();

    mem = FUN_0008d690(0x140);
    Root_1c1a40* r = 0;
    if (mem)
        r = ((Root_1c1a40*)mem)->FUN_00294880();
    root = r;
    r->v0();

    mem = thunk_FUN_0008d690(0xd0);
    ObjG* g = 0;
    if (mem)
        g = ((ObjG*)mem)->FUN_00292d70();
    objG = g;
    g->v0();
    root->FUN_00294980(objG);
    objG->v7(0.25f);
    objG->v9(200.0f);
    root->field2c = 0;
    (*(pure3d::pddiExtFramebufferEffects**)&DAT_004e2318) = dynamic_cast<pure3d::pddiExtFramebufferEffects*>(DAT_0052c2a8->s89(0x103));

    mem = FUN_0008d690(8);
    pure3d::GameDrawableInfo* info = 0;
    if (mem)
        info = new (mem) pure3d::GameDrawableInfo();
    (*(pure3d::GameDrawableInfo**)&DAT_004e2314) = info;
    info->v0();
    return this;
}
