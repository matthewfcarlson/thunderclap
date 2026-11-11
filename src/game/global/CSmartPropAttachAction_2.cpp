// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001e870..0x0001ec50 (kind game, layer game, confidence medium), dominant class CSmartPropAttachAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa260338 {
#define TREE_TU_END }
namespace fn_fa260338 {} using namespace fn_fa260338;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa260338 {
struct V3_1e870 {
    float x, y, z;
};
struct RefObj_1e870 {
    virtual void AddRef();
    virtual void Release();
};
struct Drawable_1e870;
struct Source_1e870 {
    char pad0[0xfc];
    int state;
};
struct Request_1e870 {
    char pad0[0x14];
    unsigned char active;
    char pad15[0x28 - 0x15];
    V3_1e870 target;
    char pad34[0x4c - 0x34];
    RefObj_1e870 *f4c;
    RefObj_1e870 *f50;
    char pad54[0x60 - 0x54];
    int f60;
    char pad64[0x6c - 0x64];
    RefObj_1e870 *f6c;
    int f70;
    char pad74[0x84 - 0x74];
    int f84;
    char pad88[0x98 - 0x88];
    Request_1e870 *FUN_00059820();
    void FUN_00059300();
};
struct CFightParamsCollision_nv_1e870 {
    CFightParamsCollision *FUN_000598e0(void *a, Request_1e870 *req);
    void FUN_00059790(RefObj_1e870 *obj);
};
struct Sink;
struct Slot_1e870 {
    char FUN_00231ad0(Sink *sink, CFightParamsCollision *job, int zero);
};
struct Queue_1e870 {
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual Slot_1e870 *Submit(CFightParamsCollision *job, int zero);
};
struct Pad_1e870 {
    char pad0[0x10];
    void **chain;
    char pad14[0xdc - 0x14];
    int f0dc;
    char pad0e0[0x12c - 0xe0];
    RefObj_1e870 *f12c;
    char pad130[0x334 - 0x130];
    int f334;
    void FUN_0003a9d0(RefObj_1e870 *obj);
};
struct Fighter_1e870 { char pad[4]; };
Fighter_1e870 *__fastcall FUN_000592a0(void *owner);
Pad_1e870 *__fastcall FUN_00059a30(Fighter_1e870 *f);
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj_1e870 **slot, RefObj_1e870 *obj);
void __cdecl FUN_000187a0(RefObj_1e870 **slot, RefObj_1e870 *obj);
struct Holder_1e870 {
    char pad0[0x34];
    unsigned char ready;
    char pad35[0x44 - 0x35];
    Queue_1e870 *queue;
};
class Spawner_1e870 {
public:
    char pad0[0x1c];
    void *owner;
    Holder_1e870 *holder;
    char pad24[0x38 - 0x24];
    char spawned;
    char pad39[3];
    RefObj_1e870 *ref;

    bool FUN_0001e870(Source_1e870 *src, const V3_1e870 *pos);
};
class Arg_1ea30 {
  public:
    virtual void F0();
    virtual void F1();
};
class CSmartPropAttachAction_1ea30 : public Ctor_00232660 {
  public:
    CSmartPropAttachAction_1ea30(int value, Arg_1ea30* arg);
    char pad[0x1c];
    Arg_1ea30* mThing;
    int mValue;
    int mA;
    int mB;
};
class RefObj_1ea90 {
  public:
    virtual void v0();
    virtual void Release();
};
struct Tidier {
};


// 0x0001e870 FUN_0001e870 (441 B): equivalent/0x0001e870.cpp
// sym: ?FUN_0001e870@Spawner_1e870@fn_fa260338@@QAE_NPAUSource_1e870@2@PBUV3_1e870@2@@Z @f321e232d267 @w2d8089523df2
// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 20/20)
// FUN_0001e870 @ 0x0001e870
bool Spawner_1e870::FUN_0001e870(Source_1e870 *src, const V3_1e870 *pos)
{
    if (!holder->ready || spawned)
        return false;
    if (src == 0)
        return false;
    if (src->state == 2 || src->state == 3)
        return false;

    Pad_1e870 *pad = FUN_00059a30(FUN_000592a0(owner));
    if (((unsigned int)((owners::Thing_36020 *)pad)->FUN_00036020()))
        return false;
    if (pad->f334)
        return false;
    if (((int)((owners::C_35ef0 *)pad)->FUN_00035ef0((hulk_intptr)0)))
        return false;
    pad->FUN_0003a9d0(((RefObj_1e870 *)((owners::C_1d72e0 *)src)->FUN_001d72e0()));

    Request_1e870 req;
    req.FUN_00059820();
    FUN_00018810(&req.f4c, ((RefObj_1e870 *)((owners::C_1d72e0 *)src)->FUN_001d72e0()));
    FUN_00018810(&req.f50, pad->f12c);
    FUN_000187a0(&req.f6c, ref);
    req.active = 1;
    req.target = *pos;

    CFightParamsCollision *job = (CFightParamsCollision *)FUN_0008d690(0xb0);
    if (job)
        job = ((CFightParamsCollision_nv_1e870*)(((CFightParamsCollision*)(job))))->FUN_000598e0(*pad->chain, &req);
    job->vfunc_0();
    ((CFightParamsCollision_nv_1e870*)(((CFightParamsCollision*)(job))))->FUN_00059790(((RefObj_1e870 *)((owners::C_1d72e0 *)src)->FUN_001d72e0()));
    Slot_1e870 *slot = holder->queue->Submit(job, 0);
    if (slot) {
        slot->FUN_00231ad0((Sink *)&pad->f0dc, job, 0);
        spawned = 1;
        job->vfunc_1();
        req.FUN_00059300();
        return true;
    }
    job->vfunc_1();
    req.FUN_00059300();
    return false;
}


// 0x0001ea30 FUN_0001ea30 (85 B): matches/0x0001ea30.cpp
// sym: ??0CSmartPropAttachAction_1ea30@fn_fa260338@@QAE@HPAVArg_1ea30@1@@Z
// Same code shape as 0x0001d420 (propagated; names are from that function)
CSmartPropAttachAction_1ea30::CSmartPropAttachAction_1ea30(int value, Arg_1ea30* arg) : Ctor_00232660() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableAction;
    mThing = 0;
    if (arg)
        arg->F0();
    if (mThing)
        mThing->F1();
    mThing = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&vtableSweep;
    mA = 0;
    mB = 0;
}

} // namespace fn_fa260338

// 0x0001ea90 FUN_0001ea90 (61 B): matches/0x0001ea90.cpp
// sym: ?FUN_0001ea90@CSmartPropAttachAction@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CSmartPropAttachAction::FUN_0001ea90() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_1ea90* b = (*(RefObj_1ea90 *volatile *)&this->f_24);
    if (b) {
        b->Release();
        (*(RefObj_1ea90 *volatile *)&this->f_24) = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1ea90* a = (*(RefObj_1ea90 *volatile *)&this->f_1c);
    if (a) {
        a->Release();
        (*(RefObj_1ea90 *volatile *)&this->f_1c) = 0;
    }
    ((fight::Action *)(((Tidier*)this)))->FUN_002326a0();
}


// 0x0001ead0 CSmartPropAttachAction::vfunc_6 (376 B): equivalent/0x0001ead0.cpp [wrapped: conflict: CSmartPropAttachAction; FUN_000592a0]
// sym: ?vfunc_6@CSmartPropAttachAction@fn_0001ead0@@UAE_NH@Z @617d7119fd34 @w24ef7fdb51fa
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0001ead0 {
// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 26/26)
// CSmartPropAttachAction::vfunc_6 @ 0x0001ead0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_1ead0 { int x, y, z; };

struct Sub_1ead0 {
    void FUN_001d82d0();
    void FUN_001d7590();
};

class Entity {
public:
    virtual void v0();
    virtual void v1();
    int f04;
    Sub_1ead0* sub;
    int kind;
};

class Holder_1ead0 {
public:
    char pad00[0x1ec];
    char flag;
    char pad1ed[3];
    Vec3_1ead0 pos;
    Entity* FUN_001d72e0();
};

struct Table_1ead0 {
    Holder_1ead0* FUN_001dee40(int a, int b);
};

struct World {
    char pad0[0xc];
    Table_1ead0* table;
};

struct Slot_1ead0 {
    char pad00[0x128];
    Holder_1ead0* holder;
};

struct Fighter_1ead0 { char pad[4]; };
struct Stats_1ead0 {
    char pad0[0x334];
    Slot_1ead0* slotA;
    Slot_1ead0* slotB;
    char pad33c[0x3a4 - 0x33c];
    Entity* defaultEntity;
    Holder_1ead0* FUN_00035ef0(int index);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
};
Fighter_1ead0* __fastcall FUN_000592a0(void* owner);
Stats_1ead0* __fastcall FUN_00059a30(Fighter_1ead0* f);

struct Singleton_1ead0 {
    bool FUN_000665e0(int* key, Stats_1ead0* stats);
    void FUN_00065ee0(int* key);
};
Singleton_1ead0* FUN_000678d0();

struct Owner_1ead0 {
    char pad00[0x10];
    Entity* entity;
};

struct Config_1ead0 {
    char pad00[0x14];
    int index;
    char pad18[0x48 - 0x18];
    char useWorld;
    char pad49[3];
    Vec3_1ead0 pos;
};

class CSmartPropAttachAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused);
    char pad04[0x1c - 4];
    Owner_1ead0* owner;
    Config_1ead0* config;
    Entity* current;
};

bool CSmartPropAttachAction::vfunc_6(int unused)
{
    Stats_1ead0* stats = FUN_00059a30(FUN_000592a0(owner));
    Entity* e;
    int index = config->index;
    if (config->useWorld) {
        if (!FUN_000678d0()->FUN_000665e0(DAT_004dc010, stats)) {
            stats->FUN_0003acf0(index, 0, -1, 0, 0, 0);
            return false;
        }
        Holder_1ead0* h = DAT_004dd700->table->FUN_001dee40(DAT_004dc010[0], DAT_004dc010[1]);
        if (!h) {
            stats->FUN_0003acf0(index, 0, -1, 0, 0, 0);
            return false;
        }
        h->flag = 1;
        Vec3_1ead0 p = config->pos;
        h->pos = p;
        e = h->FUN_001d72e0();
        FUN_000678d0()->FUN_00065ee0(DAT_004dc010);
    } else {
        e = 0;
        if (stats->FUN_00035ef0(index)) {
            e = stats->FUN_00035ef0(index)->FUN_001d72e0();
        }
        if (!e) {
            Slot_1ead0* s = stats->slotA;
            if (!s)
                s = stats->slotB;
            if (s && s->holder) {
                e = s->holder->FUN_001d72e0();
            }
            if (!e) {
                e = owner->entity;
                if (!e)
                    e = stats->defaultEntity;
            }
        }
    }
    if (!e) {
        stats->FUN_0003acf0(index, 0, -1, 0, 0, 0);
        return false;
    }
    if (e->kind == 5) {
        Sub_1ead0* sub = e->sub;
        sub->FUN_001d82d0();
        sub->FUN_001d7590();
    }
    e->v0();
    if (current)
        current->v1();
    current = e;
    return true;
}
} // namespace fn_0001ead0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

