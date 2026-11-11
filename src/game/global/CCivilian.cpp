// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00081340..0x00081690 (kind game, layer game, confidence medium), dominant class CCivilian
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2e01089 {
#define TREE_TU_END }
namespace fn_f2e01089 {} using namespace fn_f2e01089;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2e01089 {
class Ref_81340 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_81340 {
  public:
    void* vptr;
    void Fin();
};
class CCivilian_81340;
class Plr {
  public:
    char pad[0x328];
    Ref_81340* m328;
    void F3b160(int);
    void F3b190(int);
    void F3ffa0(int, int);
};
class Mgr_81340 {
  public:
    char pad[0x10];
    struct Sub_81340* m10;
    char pad2[0x20 - 0x14];
    struct Pl* m20;
};
struct Pl {
    char pad[0x124];
    Plr* m124;
};
struct Sub_81340 {
    void F1b43f0(CCivilian_81340*);
};
struct Tmp_81340 {
    void F1c3b80(void*);
};
extern "C" Tmp_81340* __stdcall FUN_001c3d90();
extern Mgr_81340* g_mgr_81340;
class CCivilian_81340 : public Entity_81340 {
  public:
    char pad[0xb8 - 4];
    Ref_81340* mb8;
    char pad2[0xe8 - 0xbc];
    Ref_81340* me8;
    char pad3[4];
    Ref_81340* mf0;
    char pad4[0x100 - 0xf4];
    Ref_81340* m100;
    ~CCivilian_81340();
};
struct Vec3_81420 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Matrix {
    char pad[0x40];
};
struct Clock_81420 {
    hulk_freg FUN_000787e0(float lo, float hi);
};
struct RefObj_81420 {
    char pad00[8];
    RefObj_81420* next;       // 0x08
    int kind;           // 0x0c
};
struct Linked_81420 {
    void FUN_0003ee70(int handle);
};
struct Stats_81420 {
    char pad00[0x10];
    int* handlePtr;     // 0x10
    bool FUN_00035ab0();
};
struct Request {
    char pad00[8];
    Stats_81420* stats;       // 0x08
    int kind;           // 0x0c
};
struct Controller_81420 {
    void FUN_001ec980(Stats_81420* stats, const char* name);
};
} // namespace fn_f2e01089
struct World {
    char pad00[0x34];
    Controller_81420* controller;
};
namespace fn_f2e01089 {
struct Source_81420 {
    char b14pad[0x14];
    char flag14;        // 0x14
    char pad15[0x28 - 0x15];
    Vec3_81420 vel;           // 0x28
    char flag34;        // 0x34
    char pad35[0x4c - 0x35];
    Request* req;       // 0x4c
    char pad50[0x64 - 0x50];
    int f64;
    char pad68[0x78 - 0x68];
    float f78;
    char pad7c[0x84 - 0x7c];
    RefObj_81420* f84;
    int f88;
    float f8c;
    char flag90;        // 0x90
};
class Fx_81420 {
public:
    void FUN_00081420(Source_81420* src);

    char pad00[0x10];
    int state;          // 0x10
    char pad14[0x20 - 0x14];
    int f20;
    int f24;
    unsigned int flags; // 0x28
    char pad2c[0x34 - 0x2c];
    Matrix m34;
    char pad74[0x8c - 0x74];
    float f8c;
    float f90;
    float f94;
    int f98;
    int f9c;
    int fa0;
    Vec3_81420 fa4;
    float fb0;
    float fb4;
    RefObj_81420* fb8;
    char padbc[0x100 - 0xbc];
    int f100;
};
hulk_freg FUN_00224f10(Vec3_81420* v);
void FUN_00018810(RefObj_81420** slot, RefObj_81420* obj);


// 0x00081340 FUN_00081340 (221 B): matches/0x00081340.cpp
// sym: ??1CCivilian_81340@fn_f2e01089@@QAE@XZ
CCivilian_81340::~CCivilian_81340() {
    vptr = gV;
    _ReadWriteBarrier();
    Pl* pl = g_mgr_81340->m20;
    if (pl) {
        Plr* p = pl->m124;
        if (p) {
            if (((CCivilian_81340 *)((owners::Thing_36020 *)p)->FUN_00036020()) == this)
                p->F3b160(0);
            if (((CCivilian_81340 *)((owners::C_36030 *)p)->FUN_00036030()) == this)
                p->F3b190(0);
            if (p->m328 == m100)
                p->F3ffa0(0, 0);
        }
    }
    g_mgr_81340->m10->F1b43f0(this);
    FUN_001c3d90()->F1c3b80(&pad[4]);
    if (mb8) {
        mb8->Release();
        mb8 = 0;
    }
    if (me8) {
        me8->Release();
        me8 = 0;
    }
    if (mf0) {
        mf0->Release();
        mf0 = 0;
    }
    if (m100) {
        m100->Release();
        m100 = 0;
    }
    Fin();
}


// 0x00081420 FUN_00081420 (579 B): equivalent/0x00081420.cpp
// sym: ?FUN_00081420@Fx_81420@fn_f2e01089@@QAEXPAUSource_81420@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 30/30)
// FUN_00081420 @ 0x00081420
void Fx_81420::FUN_00081420(Source_81420* src)
{
    if (state == 5 || state == 6)
        return;
    if ((flags >> 7) & 1)
        return;

    float angle = 0.0f;
    state = 7;
    flags |= 3;
    f8c = FUN_00224f10(&src->vel);
    f98 = src->f64;
    if (src->flag90) {
        f94 = (*(Clock_81420**)&DAT_004e5acc)->FUN_000787e0(8.0f, 10.0f);
        f90 = (*(Clock_81420**)&DAT_004e5acc)->FUN_000787e0(15.0f, 27.0f);
    } else if (src->flag14) {
        f94 = (*(Clock_81420**)&DAT_004e5acc)->FUN_000787e0(10.0f, 20.0f);
        f90 = (*(Clock_81420**)&DAT_004e5acc)->FUN_000787e0(8.0f, 10.0f);
    } else {
        f94 = (float)sqrt(src->vel.x * src->vel.x + src->vel.z * src->vel.z);
        *(int*)&f90 = *(int*)&src->vel.y;
    }

    if (f94 * 3.0f < f90) {
        f9c = 3;
        angle = 3.14159274f;
    } else if (f94 > f90) {
        f9c = 2;
        angle = 3.14159274f;
    } else {
        f9c = FUN_000113e0(0, 1);
    }

    ((owners::Mat_22ba70 *)&m34)->FUN_0022ba70(angle + f8c);
    f20 -= (int)(__int64)src->f78;

    if (src->f84) {
        fa0 = src->f88;
        fa4 = src->vel;
        fb0 = fa4.FUN_0022d110();
        fb4 = src->f8c;
        FUN_00018810(&fb8, src->f84);
        RefObj_81420* r = fb8;
        if (r && r->kind == 1) {
            Linked_81420* l = (Linked_81420*)r->next;
            if (l)
                l->FUN_0003ee70(f100);
        }
        f8c = angle;
    }

    Request* req = src->req;
    if (req && req->kind == 1) {
        Stats_81420* stats = req->stats;
        f24 = *stats->handlePtr;
        if (stats->FUN_00035ab0() && !src->flag34)
            DAT_004dd700->controller->FUN_001ec980(stats, "punch_sml");
    }
}

} // namespace fn_f2e01089

// 0x00081670 CCivilian::vfunc_2 (30 B): matches/0x00081670.cpp
// sym: ??_GCCivilian@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CCivilian::~CCivilian() {}

