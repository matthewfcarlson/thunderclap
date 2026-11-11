// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fe270..0x002fe570 (kind game, layer engine, confidence high), dominant class physics::SimStateHairclub
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc07f3fa {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc07f3fa {} using namespace fn_fc07f3fa;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fc07f3fa {
class SimState {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void vfunc_14(int);
};
class Inner_2fe270 {
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
};
class Owner_2fe270 {
  public:
    char pad[0x20];
    Inner_2fe270* inner;
    char pad2[0x50 - 0x24];
    char flag;
    void Helper_003046f0(int);
};
namespace physics {
class SimStateHairclub : public SimState {
  public:
    char pad[0x74 - sizeof(SimState)];
    Owner_2fe270* owner;
    void vfunc_14(int);
};
}
struct Inner_2fe2c0 {
    char pad[0x24];
    int value;
};
struct Obj_2fe2c0 {
    char pad[0x70];
    Inner_2fe2c0* p;
    void Fn();
};
class A_2fe2e0 {
  public:
    char pad[0x70];
    void* m70;
    void* m74;
};
extern void __fastcall thunk_00309490(void*);
extern void __fastcall other_003062a0(void*);
extern "C" char DAT_004319a4[];
class Ref_2fe3a0 {
  public:
    virtual void First();
    virtual void Release();
};
class SimState_2fe3a0 {
  public:
    SimState_2fe3a0(void*);
};
class SimStateHairclub : public SimState_2fe3a0 {
  public:
    char pad0[0x85];
    unsigned char flag;
    char pad1[2];
    Ref_2fe3a0* mRef;
    SimStateHairclub(Ref_2fe3a0* r, void* p);
};
struct Ref_2fe3f0 {
    virtual void a();
    virtual void release();
};
struct SimStateHairclub_2fe3f0 {
    volatile hulk_uintptr vptr;
    char pad[0x84];
    Ref_2fe3f0* volatile ptr;
    void run();
};
extern void __fastcall FUN_002ef2c0(SimStateHairclub_2fe3f0*);
class A_2fe420 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int Get(int);
    char pad[0x34];
    int count;
};
class B_2fe420 {
  public:
    char pad[0x24];
    int state;
};
class C_2fe420 {
  public:
    char pad70[0x70];
    B_2fe420* b;
    A_2fe420* a;
    void Run(hulk_intptr);
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
struct Source_2fe480 {
    char pad0[0x18];
    int value;                // 0x18
};
struct Channel {
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
    char pad04[0x19 - 4];
    char muted;               // 0x19
};
struct Item_2fe480 {
    char pad0[0x20];
    Channel *channel;         // 0x20
    char pad24[0x50 - 0x24];
    char keep;                // 0x50
    char pad51[0x68 - 0x51];
    char active;              // 0x68
    char pending;             // 0x69
};
class SimStateHairclub_2fe480 {
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
    virtual void v13(Source_2fe480 *src);
    virtual void v14(Item_2fe480 *item);
    char pad[0x8c - 8];
    SimStateHairclub_2fe480 *FUN_002fe3a0(int a, int b);
};
class Owner_2fe480 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Item_2fe480 *v5(SimStateHairclub_2fe480 *e);
};
class Provider_2fe480 {
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual Source_2fe480 *v28(SimStateHairclub_2fe480 *e);
};


// 0x002fe270 physics::SimStateHairclub::vfunc_14 (67 B): matches/0x002fe270.cpp
// sym: ?vfunc_14@SimStateHairclub@physics@fn_fc07f3fa@@UAEXH@Z
void physics::SimStateHairclub::vfunc_14(int x) {
    SimState::vfunc_14(x);
    Owner_2fe270* o = owner;
    if (o->flag) {
        owner->Helper_003046f0(0);
        owner->inner->f10();
        owner->Helper_003046f0(1);
    } else {
        o->inner->f10();
    }
}


// 0x002fe2c0 FUN_002fe2c0 (19 B): matches/0x002fe2c0.cpp
// sym: ?Fn@Obj_2fe2c0@fn_fc07f3fa@@QAEXXZ
void Obj_2fe2c0::Fn() {
    if (p != 0 && p->value == 2) {
        ((owners::C_308e00 *)p)->FUN_00308e00();
    }
}


// 0x002fe2e0 FUN_002fe2e0 (39 B): matches/0x002fe2e0.cpp
// sym: ?target@fn_fc07f3fa@@YIXPAVA_2fe2e0@1@@Z
void __fastcall target(A_2fe2e0* self) {
    void* p = self->m70;
    if (p && *(int*)((char*)p + 0x24) == 2)
        thunk_00309490(p);
    void* q = self->m74;
    if (q)
        other_003062a0(*(void**)((char*)q + 0x20));
}

} // namespace fn_fc07f3fa

// 0x002fe310 physics::SimStateHairclub::vfunc_4 (53 B): matches/0x002fe310.cpp [wrapped: conflict: physics::SimStateHairclub]
// sym: ?vfunc_4@SimStateHairclub@physics@fn_002fe310@@QAEPAXH@Z
namespace fn_002fe310 {
struct HairMap {
    char padding[0x20];
    int handle;
    int FUN_00304cb0(int handle, int index);
};
struct HairData {
    char padding[0x1c];
    char* base;
};
namespace physics {
struct SimStateHairclub {
    char padding[0x10];
    char fallback[0x64];
    HairMap* map;
    char padding2[0x10];
    HairData* data;
    void* vfunc_4(int index);
};
} // namespace physics
void* physics::SimStateHairclub::vfunc_4(int index) {
    if (index >= 0) {
        int handle = map->handle;
        int item = map->FUN_00304cb0(handle, index);
        if (item >= 0)
            return data->base + item * 64;
    }
    return fallback;
}
} // namespace fn_002fe310


// 0x002fe350 physics::SimStateHairclub::vfunc_5 (55 B): matches/0x002fe350.cpp [wrapped: conflict: physics::SimStateHairclub]
// sym: ?vfunc_5@SimStateHairclub@physics@fn_002fe350@@QAEPAXH@Z
namespace fn_002fe350 {
struct HairEntry {
    char header[0x30];
    char data[0x10];
};
struct HairStorage {
    char pad[0x1c];
    HairEntry* entries;
};
struct HairLookup {
    char pad[0x20];
    void* value;
    int FUN_00304cb0(void*, int);
};
namespace physics {
struct SimStateHairclub {
    char pad[0x40];
    char fallback[0x34];
    HairLookup* lookup;
    char pad2[0x10];
    HairStorage* storage;
    void* vfunc_5(int index);
};
void* SimStateHairclub::vfunc_5(int index) {
    if (index >= 0) {
        HairLookup* l = lookup;
        void* value = l->value;
        int found = l->FUN_00304cb0(value, index);
        if (found >= 0)
            return storage->entries[found].data;
    }
    return fallback;
}
} // namespace physics
} // namespace fn_002fe350

namespace fn_fc07f3fa {

// 0x002fe3a0 FUN_002fe3a0 (79 B): matches/0x002fe3a0.cpp
// sym: ??0SimStateHairclub@fn_fc07f3fa@@QAE@PAVRef_2fe3a0@1@PAX@Z
SimStateHairclub::SimStateHairclub(Ref_2fe3a0* r, void* p) : SimState_2fe3a0(p) {
    *(void**)this = (void*)((hulk_intptr)DAT_004319a4);
    mRef = 0;
    if (r)
        r->First();
    if (mRef)
        mRef->Release();
    mRef = r;
    flag = 1;
}


// 0x002fe3f0 FUN_002fe3f0 (42 B): matches/0x002fe3f0.cpp
// sym: ?run@SimStateHairclub_2fe3f0@fn_fc07f3fa@@QAEXXZ
void SimStateHairclub_2fe3f0::run() {
    vptr = ((hulk_intptr)DAT_004319a4);
    Ref_2fe3f0* p = ptr;
    if (p) {
        p->release();
        ptr = 0;
    }
    FUN_002ef2c0(this);
}


// 0x002fe420 FUN_002fe420 (82 B): matches/0x002fe420.cpp
// sym: ?Run@C_2fe420@fn_fc07f3fa@@QAEXH@Z
void C_2fe420::Run(hulk_intptr x) {
    if (a) {
        int* result = (int*)a->Get(x);
        if (b && b->state == 2) {
            int n = a->count;
            for (hulk_intptr i = 0; i < n; ++i)
                ((owners::C_308e10 *)b)->FUN_00308e10((int)i, *(unsigned char*)(result[2] + i));
        }
    }
}


// 0x002fe480 FUN_002fe480 (167 B): equivalent/0x002fe480.cpp
// sym: _FUN_002fe480 @87f5e38e9333 @w8644d1f8886e
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 15/16, incomplete)
// FUN_002fe480 @ 0x002fe480
extern "C" SimStateHairclub_2fe480 *__cdecl FUN_002fe480(int a, Owner_2fe480 *owner, Provider_2fe480 *provider)
{
    SimStateHairclub_2fe480 *mem = (SimStateHairclub_2fe480 *)FUN_0008d690(0x8c);
    SimStateHairclub_2fe480 *e = 0;
    if (mem)
        e = mem->FUN_002fe3a0(a, 0);
    if (e == 0)
        return 0;
    Source_2fe480 *src = 0;
    if (provider) {
        src = provider->v28(e);
        e->v13(src);
    }
    if (owner) {
        Item_2fe480 *item = owner->v5(e);
        e->v14(item);
        if (item->active || item->pending)
            item->channel->v10();
        item->channel->v8();
        if (!item->keep) {
            item->channel->muted = 0;
            item->active = 1;
            item->pending = 1;
        }
        if (src)
            ((owners::C_304740 *)item)->FUN_00304740((hulk_intptr)(src->value));
    }
    return e;
}

} // namespace fn_fc07f3fa

// 0x002fe530 physics::SimStateHairclub::vfunc_2 (63 B): matches/0x002fe530.cpp [wrapped: conflict: SimStateHairclub]
// sym: ?vfunc_2@SimStateHairclub@fn_002fe530@@UAEPAV12@E@Z
namespace fn_002fe530 {
extern "C" char DAT_004319a4[];
class SimStateHairclub {
  public:
    virtual void v0();
    virtual void v1();
    virtual SimStateHairclub* vfunc_2(unsigned char);
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
    virtual void v14();
    void cleanup_002ef2c0();
    char pad[0x84];
    struct Ref_2fe530* member;
};
struct Ref_2fe530 {
    virtual void a();
    virtual void b();
};
void release_0008d330(SimStateHairclub*);
SimStateHairclub* SimStateHairclub::vfunc_2(unsigned char p) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_004319a4);
    Ref_2fe530* volatile* pm = &member;
    Ref_2fe530* m = *pm;
    if (m) {
        m->b();
        member = 0;
    }
    cleanup_002ef2c0();
    if (p & 1)
        release_0008d330(this);
    return this;
}
} // namespace fn_002fe530

