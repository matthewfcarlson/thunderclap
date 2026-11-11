// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014580..0x00014bb0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4b0ec38 {
#define TREE_TU_END }
namespace fn_f4b0ec38 {} using namespace fn_f4b0ec38;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4b0ec38 {
class A_14580 {
  public:
    char pad[0x20];
    struct B_14580* p;
    float f();
};
struct B_14580 {
    char pad[0x2c];
    float value;
};
extern "C" void *FUN_0008d690(unsigned int size);
struct Vec3_145b0 {
    float x, y, z;
};
class Ref_145b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    Ref_145b0 *FUN_00059260(void *arg);
};
struct Slot_145b0 {
    bool FUN_00231e80(struct Node *n);
};
struct Node {
    void FUN_00231ad0(Slot_145b0 *slot, Ref_145b0 *ref, int flag);
};
class Source_145b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Node *vfunc_8(Ref_145b0 *ref, int flag);
};
struct Link_145b0 {
    Ref_145b0 *first;
};
struct Pos_145b0 {
    void FUN_00059a50(Vec3_145b0 *out);
};
struct Actor_145b0 {
    char pad000[0x10];
    Link_145b0 *link;                 // 0x10
    char pad014[0xdc - 0x14];
    Slot_145b0 slot;                  // 0xdc
    char pad0dd[0x11c - 0xdd];
    void *f11c;
    char pad120[0x20b0 - 0x120];
    int f20b0;
    int FUN_00038f90(int a1, int f2c, int zero);   // tested as a full int (test eax,eax)
};
struct Body_145b0 {
    char pad00[0x10];
    Pos_145b0 *pos;
};
struct Handle_145b0 {
    Body_145b0 *FUN_00059a30();
    void FUN_00059a40();
};
struct Config_145b0 {
    char pad00[0x2c];
    int f2c;
    int limit;                  // 0x30
    Source_145b0 *source34;           // 0x34
    char pad38[0x40 - 0x38];
    Source_145b0 *source40;           // 0x40
};
struct Roster_145b0 {
    char pad00[0x0c];
    int count;                  // 0x0c
    Actor_145b0 *FUN_00024190(int index);
};
} // namespace fn_f4b0ec38
struct World {
    char pad00[0x20];
    Roster_145b0 *roster;
};
namespace fn_f4b0ec38 {
struct Owner_145b0 {
    char pad00[8];
    void *f08;
};
class Tracker_145b0 {
public:
    char pad00[0x1c];
    Owner_145b0 *owner;               // 0x1c
    Config_145b0 *config;             // 0x20
    char pad24[0x34 - 0x24];
    Actor_145b0 *seen[8];             // 0x34
    int seenCount;              // 0x54
    int counter;                // 0x58

    void FUN_000145b0(int a1, int a2, int a3);
};
class H1 {
  public:
    void* Fnf_000592a0();
};
struct H2_147d0 {
    void* Fnf_00059a40();
};
struct H3_147d0 {
    char p[0x64];
    void* q;
};
struct H4 {
    char p[0x1c];
    void* z;
};
struct Helper_147d0 {
    char p[0x1c];
    void Fnf_0022c2b0(void*, void*);
};
struct V {
    int a, b, c;
};
struct B_147d0 {
    char p[0x20];
    V v;
};
class B_14860;
class C_14860;
class A_14860 {
  public:
    B_14860* Fnf_000592a0();
};
class B_14860 {
  public:
    C_14860* Fnf_00059a40();
};
class C_14860 {
  public:
    bool Fnf_00222a00(void*);
};
class Obj_14860 {
  public:
    char pad[0x1c];
    A_14860* a;
    char pad2[4];
    void* b;
};
class H2_14890 {
  public:
    void* f2_00059a40();
};
class H3_14890 {
  public:
    bool f3_00222a00(void*);
};
struct R_148d0 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_148d0* __fastcall FUN_00059a40(void*);
struct CProceduralDurationAnimationAction_14900 {
    char pad[0x1c];
    void* member;
};
struct Queried {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* get();
};
struct Result_14900 {
    char pad[0x58];
    float value;
};
class Thing_14920 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int* get();
    char pad[0x5c - 4];
    float value;
};
class B_14940;
class C_14940;
class A_14940 {
  public:
    B_14940* Fnf_000592a0();
};
class B_14940 {
  public:
    C_14940* Fnf_00059a40();
};
class C_14940 {
  public:
    bool Fnf_00222a00(void*);
};
class Obj_14940 {
  public:
    char pad[0x1c];
    A_14940* a;
    char pad2[4];
    void* b;
};
class H2_14970 {
  public:
    void* f2_00059a40();
};
class H3_14970 {
  public:
    bool f3_00222a00(void*);
};
struct Obj_149b0;
struct Manager_149b0 {
    void* Find_00059bf0(int);
};
struct Root_149b0 {
    char pad[0x44];
    Manager_149b0* mgr;
};
extern Root_149b0* hulk_at_004dd700;
struct Obj_149b0 {
    void Apply_00222970(int, int);
};
struct Table_149e0 {
};
struct Info_149e0 {
    char pad0[0x10];
    float limit;
    float scale;
};
struct Anim_149e0 {
    char pad0[0x20];
    Info_149e0 *info;
    void FUN_00225e00(float a, float b, float c, float d);
};
class Segmenter {
public:
    char FUN_000149e0(int index);

    char pad0[0x20];
    Table_149e0 *table;
    Anim_149e0 *anim;
    int index;
    float accum;
};


// 0x00014580 FUN_00014580 (7 B): matches/0x00014580.cpp
// sym: ?f@A_14580@fn_f4b0ec38@@QAEMXZ
float A_14580::f() {
    return p->value;
}


// 0x000145b0 FUN_000145b0 (532 B): equivalent/0x000145b0.cpp
// sym: ?FUN_000145b0@Tracker_145b0@fn_f4b0ec38@@QAEXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 18665 inputs, branch coverage 43/44, incomplete)
// FUN_000145b0 @ 0x000145b0
void Tracker_145b0::FUN_000145b0(int a1, int a2, int a3)
{
    Handle_145b0 *handle = ((Handle_145b0 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Body_145b0 *self = handle->FUN_00059a30();
    handle->FUN_00059a40();
    Vec3_145b0 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    self->pos->FUN_00059a50(&v);

    Roster_145b0 *roster = DAT_004dd700->roster;
    int n = roster->count;
    for (int i = 0; i < n; i++) {
        Actor_145b0 *cand = roster->FUN_00024190(i);
        if (cand == (Actor_145b0 *)self || cand == 0)
            continue;
        if (cand->f20b0 != 0)
            continue;
        if (((owners::Thing_360f0 *)cand)->FUN_000360f0())
            continue;
        if (cand->f11c == 0)
            continue;

        bool known = false;
        for (int k = 0; k < seenCount; k++) {
            if (seen[k] == cand) {
                known = true;
                break;
            }
        }
        if (known)
            continue;

        int f2c = config->f2c;
        if (!cand->FUN_00038f90(a1, f2c, 0))
            continue;

        counter = counter + 1;
        Source_145b0 *s1 = config->source40;
        if (s1 != 0) {
            void *mem = FUN_0008d690(0x14);
            Ref_145b0 *r = 0;
            if (mem)
                r = ((Ref_145b0 *)mem)->FUN_00059260(owner->f08);
            r->vfunc_0();
            Node *node = s1->vfunc_8(r, 0);
            if (node != 0) {
                Slot_145b0 *selfSlot = (Slot_145b0 *)((char *)self + 0xdc);
                if (!selfSlot->FUN_00231e80(node))
                    node->FUN_00231ad0(selfSlot, r, -1);
            }
            r->vfunc_1();
        }

        Source_145b0 *s2 = config->source34;
        if (s2 != 0) {
            void *mem = FUN_0008d690(0x14);
            Ref_145b0 *r = 0;
            if (mem)
                r = ((Ref_145b0 *)mem)->FUN_00059260(cand->link->first);
            r->vfunc_0();
            Node *node = s2->vfunc_8(r, 0);
            if (node != 0)
                node->FUN_00231ad0(&cand->slot, r, -1);
            r->vfunc_1();
        }

        if (seenCount < 8) {
            seen[seenCount] = cand;
            seenCount = seenCount + 1;
            int limit = config->limit;
            if (limit > 0 && counter >= limit)
                break;
        }
    }
}

} // namespace fn_f4b0ec38

// 0x000147d0 COpportunityBallAction::vfunc_6 (84 B): matches/0x000147d0.cpp
// sym: ?vfunc_6@COpportunityBallAction@@UAE_NH@Z
bool COpportunityBallAction::vfunc_6(int arg) {
    void* a = ((H1*)(*(void * *)&this->f_1c))->Fnf_000592a0();
    a = ((H2_147d0*)a)->Fnf_00059a40();
    V local = ((B_147d0*)(*(void * *)&this->f_20))->v;
    void* x = ((H3_147d0*)a)->q;
    void* base = ((H4*)x)->z;
    ((Helper_147d0*)((char*)base + (this->f_24 << 6)))->Fnf_0022c2b0(&local, &this->f_28);
    return true;
}

namespace fn_f4b0ec38 {

// 0x00014860 FUN_00014860 (39 B): matches/0x00014860.cpp
// sym: ?target@fn_f4b0ec38@@YI_NPAVObj_14860@1@@Z
bool __fastcall target(Obj_14860* self) {
    B_14860* x = self->a->Fnf_000592a0();
    C_14860* y = x->Fnf_00059a40();
    if (!y)
        return true;
    return y->Fnf_00222a00(self->b);
}

} // namespace fn_f4b0ec38

// 0x00014890 CProceduralDurationAnimationAction::vfunc_8 (61 B): matches/0x00014890.cpp
// sym: ?vfunc_8@CProceduralDurationAnimationAction@@UAE_NH@Z
bool CProceduralDurationAnimationAction::vfunc_8(int ) {
    void* x = ((void *)((owners::Object_592a0 *)(((H1*)(*(void * *)&this->f_1c))))->FUN_000592a0());
    void* y = ((H2_14890*)x)->f2_00059a40();
    bool r;
    if (y == 0)
        r = true;
    else
        r = ((H3_14890*)y)->f3_00222a00((*(void * *)&this->f_24));
    return !r;
}


// 0x000148d0 CProceduralDurationAnimationAction::vfunc_4 (37 B): matches/0x000148d0.cpp
// sym: ?vfunc_4@CProceduralDurationAnimationAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CProceduralDurationAnimationAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_148d0* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}


// 0x00014900 CHitAnimationAction::vfunc_9 (23 B): matches/0x00014900.cpp
// sym: ?vfunc_9@CHitAnimationAction@@UAEMXZ
// data: zeroValue_14900 = DAT_003f32e0
hulk_freg CHitAnimationAction::vfunc_9() {
    Result_14900* p = (Result_14900*)((Queried*)(*(void * *)&this->f_1c))->get();
    if (!p)
        return DAT_003f32e0;
    return p->value;
}


// 0x00014920 CPushBackAnimationAction::vfunc_9 (23 B): matches/0x00014920.cpp
// sym: ?vfunc_9@CPushBackAnimationAction@@UAEMXZ
hulk_freg CPushBackAnimationAction::vfunc_9() {
    int* p = (*(Thing_14920 * *)&this->f_1c)->get();
    if (!p)
        return 0.0f;
    return *(float*)((char*)p + 0x5c);
}

namespace fn_f4b0ec38 {

// 0x00014940 FUN_00014940 (39 B): matches/0x00014940.cpp
// sym: ?target@fn_f4b0ec38@@YI_NPAVObj_14940@1@@Z
// Same code shape as 0x00014860 (propagated; names are from that function)
bool __fastcall target(Obj_14940* self) {
    B_14940* x = self->a->Fnf_000592a0();
    C_14940* y = x->Fnf_00059a40();
    if (!y)
        return true;
    return y->Fnf_00222a00(self->b);
}

} // namespace fn_f4b0ec38

// 0x00014970 CStunAnimationAction::vfunc_8 (61 B): matches/0x00014970.cpp
// sym: ?vfunc_8@CStunAnimationAction@@UAE_NH@Z
// Same code shape as 0x00014890 (propagated; names are from that function)
bool CStunAnimationAction::vfunc_8(int ) {
    void* x = ((void *)((owners::Object_592a0 *)(((H1*)(*(void * *)&this->f_1c))))->FUN_000592a0());
    void* y = ((H2_14970*)x)->f2_00059a40();
    bool r;
    if (y == 0)
        r = true;
    else
        r = ((H3_14970*)y)->f3_00222a00((*(void * *)&this->f_24));
    return !r;
}


// 0x000149b0 CStunAnimationAction::vfunc_4 (43 B): matches/0x000149b0.cpp
// sym: ?vfunc_4@CStunAnimationAction@@UAEXXZ
void CStunAnimationAction::vfunc_4() {
    int x = *(int*)((char*)(*(void * *)&this->f_1c) + 8);
    Obj_149b0* o = (Obj_149b0*)hulk_at_004dd700->mgr->Find_00059bf0(x);
    if (o)
        o->Apply_00222970((*(int *)&this->f_24), 0);
}

namespace fn_f4b0ec38 {

// 0x000149e0 FUN_000149e0 (324 B): matches/0x000149e0.cpp
// sym: ?FUN_000149e0@Segmenter@fn_f4b0ec38@@QAEDH@Z
// FUN_000149e0 @ 0x000149e0
char Segmenter::FUN_000149e0(int idx)
{
    if (idx >= 8)
        return 0;
    index = idx;

    float lo = ((owners::Thing_69620 *)table)->FUN_00069620(idx - 1);
    float span = ((owners::Thing_69620 *)table)->FUN_00069620(idx) - lo;
    if (span <= 0.0f)
        return 0;

    float limit = anim->info->limit - 1.0f;
    float e = ((owners::A_695e0 *)table)->FUN_000695e0(idx - 1);
    if (e < 0.0f || e > limit)
        return 0;
    float f = ((owners::A_695e0 *)table)->FUN_000695e0(idx);
    if (f < 0.0f || f > limit)
        return 0;

    float acc = span + accum;
    accum = acc;
    if (acc < 0.0f)
        return 1;

    e = (span - acc) * ((f - e) / span) + e;
    anim->FUN_00225e00(-1.0f, ((f - e) / anim->info->scale) / acc, e, f);
    return 1;
}

} // namespace fn_f4b0ec38

// 0x00014b30 CKeyPoseAction::vfunc_8 (77 B): matches/0x00014b30.cpp [wrapped: conflict: CKeyPoseAction]
// sym: ?vfunc_8@CKeyPoseAction@fn_00014b30@@UAEEM@Z
namespace fn_00014b30 {
class CKeyPoseAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual unsigned char vfunc_8(float dt);
    char pad[0x20];
    int mActive;
    int mIndex;
    float mTime;
    bool Advance_000149e0(int i);
};
unsigned char CKeyPoseAction::vfunc_8(float dt) {
    if (mActive) {
        mTime -= dt;
        if (mTime <= 0.0f) {
            do {
                if (!Advance_000149e0(mIndex + 1))
                    return 0;
            } while (mTime <= 0.0f);
        }
        return 1;
    }
    return 0;
}
} // namespace fn_00014b30

