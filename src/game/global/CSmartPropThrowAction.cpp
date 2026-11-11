// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000160b0..0x00016440 (kind game, layer game, confidence medium), dominant class CSmartPropThrowAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdd2ae74 {
#define TREE_TU_END }
namespace fn_fdd2ae74 {} using namespace fn_fdd2ae74;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdd2ae74 {
class Obj_160b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual int h(int, int);
};
class A_160b0 {
  public:
};
class B_160b0 {
  public:
    Obj_160b0* next_00059a30();
};
class C_160b0 {
  public:
};
struct Data_160b0 {
    char pad[16];
    int value;
};
class CAction_160f0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual bool vfunc_6(int);
    virtual void a7();
    virtual void a8();
};
struct Obj_160f0 {
    Obj_160f0* f59a30_00059a30();
    unsigned int f40140_00040140(int, int, int, int, int);
};

} // namespace fn_fdd2ae74

// 0x000160b0 CSmartPropSetStateAction::vfunc_7 (53 B): matches/0x000160b0.cpp
// sym: ?vfunc_7@CSmartPropSetStateAction@@UAE_NH@Z
bool CSmartPropSetStateAction::vfunc_7(int arg) {
    Obj_160b0* a = ((Obj_160b0 *)((owners::Object_592a0 *)((*(A_160b0 * *)&this->f_1c)))->FUN_000592a0());
    B_160b0* b = (B_160b0*)a;
    a = b->next_00059a30();
    C_160b0* c = (C_160b0*)a;
    Obj_160b0* p = ((Obj_160b0 *)((owners::C_35ef0 *)c)->FUN_00035ef0((hulk_intptr)0));
    if (p)
        p->h((*(Data_160b0 * *)&this->f_20)->value, 1);
    return false;
}


// 0x000160f0 CSmartPropDetachAction::vfunc_6 (37 B): matches/0x000160f0.cpp
// sym: ?vfunc_6@CSmartPropDetachAction@@UAE_NH@Z
bool CSmartPropDetachAction::vfunc_6(int unused) {
    Obj_160f0* o = *(Obj_160f0**)((char*)this + 0x1c);
    o = ((Obj_160f0 *)((owners::Object_592a0 *)o)->FUN_000592a0());
    o = o->f59a30_00059a30();
    o->f40140_00040140(0, -1, 0, 0, 0);
    return false;
}


// 0x00016120 CSmartPropThrowAction::vfunc_6 (788 B): equivalent/0x00016120.cpp [wrapped: conflict: CSmartPropThrowAction]
// sym: ?vfunc_6@CSmartPropThrowAction@fn_00016120@@UAE_NH@Z
namespace fn_00016120 {
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 24/24)
// CSmartPropThrowAction::vfunc_6 @ 0x00016120

struct V3_16120 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Aimed_16120 {
    void FUN_0022c3b0(V3_16120* from, V3_16120* to);
};

struct TrackerSub_16120 {
    Aimed_16120* FUN_00221c40();
};

struct Tracker_16120 {
    char pad0[0x10];
    TrackerSub_16120 sub;
};

struct Anchor_16120;

struct Body_16120 {
    char pad00[0x40];
    V3_16120 pos;
};

struct Part_16120 {
    int FUN_001d4e80();
};

struct Object {
    char pad00[0xec];
    Part_16120* partEc;
    char padf0[0x1ec - 0xf0];
    unsigned char flag1ec;
    char pad1ed[3];
    Body_16120* FUN_001d72e0();
    void FUN_001d8c70(void* body);
    int FUN_001d64a0();
    void FUN_001d8d90(int flag);
    void FUN_001d81b0(V3_16120* v, int w);
    void FUN_001d63b0(int v);
};

struct Fighter_16120 {
    char pad00[0x140];
    int f140;
    char pad144[0x328 - 0x144];
    Body_16120* body328;
    Object* FUN_00035ef0(int index);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
    void FUN_00036c20(Body_16120* b);
    bool FUN_00038de0(V3_16120* a, V3_16120* b, int c, int d, V3_16120* e, V3_16120* f, int* g, int h);
};

struct Anchor_16120 {
    Fighter_16120* FUN_00059a30();
    Tracker_16120* FUN_00059a40();
    void FUN_00059a50(V3_16120* out);
};

struct Owner_16120 {
    Anchor_16120* FUN_000592a0();
};

struct Params {
    char pad00[0x10];
    V3_16120 vec10;
    char pad1c[0x34 - 0x1c];
    int f34;
    char pad38[4];
    unsigned char b3c;
    char pad3d[3];
    int f40;
};

struct Globals_16120 {
    char pad00[0x10];
    V3_16120 vec10;
};


extern "C" void __cdecl FUN_00097540(Fighter_16120* f, V3_16120* a, V3_16120* b, int c, float d, Body_16120* e, V3_16120* g, V3_16120* h, int i);

struct Frame_16120 {
    union {
        Body_16120* x;
        unsigned char flag;
        int word;
    } u0;
    union {
        Tracker_16120* tracker;
        int f34;
    } u4;
    union {
        Anchor_16120* anchor;
        unsigned char eq5;
        int zero;
        int word;
    } u8;
    V3_16120 w;
    V3_16120 l;
    V3_16120 out1;
    V3_16120 g;
    V3_16120 pc;
    V3_16120 out2;
    V3_16120 out3;
    V3_16120 out4;
};

class CSmartPropThrowAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    char pad04[0x1c - 4];
    Owner_16120* owner;
    Params* params;
};

bool CSmartPropThrowAction::vfunc_6(int arg)
{
    Frame_16120 f;
    f.u8.anchor = owner->FUN_000592a0();
    Fighter_16120* fighter = f.u8.anchor->FUN_00059a30();
    Tracker_16120* tracker = f.u8.anchor->FUN_00059a40();
    f.u4.tracker = tracker;
    Object* o = fighter->FUN_00035ef0(params->f40);
    if (o == 0)
        return false;
    f.u0.x = o->FUN_001d72e0();
    if (f.u0.x == 0)
        return false;
    if (tracker == 0)
        return false;
    Body_16120* b = fighter->body328;
    if (o->flag1ec) {
        if (b == 0)
            return false;
        f.g = b->pos;
        f.l.x = f.u0.x->pos.x - f.g.x;
        f.l.y = f.u0.x->pos.y - f.g.y;
        f.l.z = f.u0.x->pos.z - f.g.z;
        f.l.FUN_0022d110();
    } else {
        f.g = params->vec10;
        f.u4.tracker->sub.FUN_00221c40()->FUN_0022c3b0(&f.g, &f.l);
    }
    f.l.FUN_0022d110();
    f.u4.f34 = params->f34;
    f.pc = f.u0.x->pos;
    f.g = (*(Globals_16120**)&DAT_00554c10)->vec10;
    o->FUN_001d8c70(b);
    fighter->FUN_0003acf0(params->f40, 0, -1, 0, 0, 0);
    fighter->FUN_00036c20(f.u0.x);
    FUN_00097540(fighter, &f.pc, &f.l, f.u4.f34, f.g.y * -0.01f, b, &f.out1, &f.out2, params->b3c);
    f.u0.flag = 1;
    int state = o->partEc->FUN_001d4e80();
    bool isTwo = state == 2;
    if (b == 0 && !isTwo) {
        f.u8.anchor->FUN_00059a50(&f.g);
        f.g.y = (fighter->f140 == 3 ? 0.0f : 3.0f) + f.g.y;
        f.w = f.l;
        f.w.x = f.w.x * 3.0f;
        f.w.y = f.w.y * 3.0f;
        f.w.z = f.w.z * 3.0f;
        f.w.x = f.g.x + f.w.x;
        f.w.y = f.w.y + f.g.y;
        f.w.z = f.g.z + f.w.z;
        f.u8.zero = 0;
        if (fighter->FUN_00038de0(&f.g, &f.w, 0, 1, &f.out4, &f.out3, &f.u8.zero, 0)) {
            f.out1.FUN_0022d110();
            f.u0.flag = 0;
            f.out1.x = f.out1.x * 4.0f;
            f.out1.y = f.out1.y * 4.0f + 2.0f;
            f.out1.z = f.out1.z * 4.0f;
        }
    }
    f.u8.eq5 = o->FUN_001d64a0() == 5;
    o->FUN_001d8d90(f.u0.word);
    o->FUN_001d81b0(&f.out1, f.u8.word);
    if (o->FUN_001d64a0() == 5)
        o->FUN_001d63b0(1);
    return false;
}
} // namespace fn_00016120

