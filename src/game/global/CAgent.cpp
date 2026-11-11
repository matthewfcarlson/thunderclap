// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fc460..0x000fc720 (kind game, layer game, confidence high), dominant class CAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ffab1cd7 {
#define TREE_TU_END }
namespace fn_ffab1cd7 {} using namespace fn_ffab1cd7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffab1cd7 {
class Scorer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float v3(int a, int b);
};
class CAgent_fc4e0 {
public:
    char pad0[0x10];
    int count;
    Scorer *items[(0x54 - 0x14) / 4];
    int selected;
    float FUN_000fc4e0(hulk_intptr a, int b);
};
extern "C" char DAT_004a19e0[];
extern "C" char DAT_004a19f8[];
class Target_fc550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
class Elem_fc550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Act(int a, int b, int c);
    virtual void v5();
    virtual void v6();
    virtual void Fin(int x);
    char pad[4];
    float f;
};
class Other_fc550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Notify();
    char pad[0x54];
    Target_fc550* t;
};
extern "C" void* FUN_00344e74(void*, int, void*, void*, int);
class Owner_fc550 {
  public:
    char pad[0x14];
    Elem_fc550* items[1];
    char pad2[0x3c];
    int cur;
    void Fn(int a, int b, char c);
};
class Item_fc5d0 {
  public:
    virtual void F();
};
class Container_fc5d0 {
  public:
    char pad[0x10];
    int count;
    Item_fc5d0* items[1];
    int Add(Item_fc5d0* p);
};
extern "C" void FUN_000964d0();
struct CCharacterAgent_fc630 {
    void* vt;
    char pad[0x54];
    void* field58;
    void target();
    void finish_000fc460();
};
extern int hulk_at_0040cfe4;
struct Ref_fc630 {
    virtual void A();
    virtual void B();
};

} // namespace fn_ffab1cd7

// 0x000fc460 FUN_000fc460 (52 B): matches/0x000fc460.cpp [wrapped: conflict: CAgent]
// sym: ?FUN_000fc460@fn_000fc460@@YIXPAUCAgent@1@@Z
namespace fn_000fc460 {
struct IRefCount {
    virtual void f0();
    virtual void Release();
};
extern int hulk_at_0040cf84;
extern int hulk_at_003f6098;
struct CAgent {
    void* vptr;
    char pad[0x10];
    IRefCount* refs[16];
};
void __fastcall FUN_000fc460(CAgent* self) {
    self->vptr = &hulk_at_0040cf84;
    for (int i = 0; i < 16; ++i) {
        IRefCount* p = self->refs[i];
        if (p) {
            p->Release();
            self->refs[i] = 0;
        }
    }
    self->vptr = &hulk_at_003f6098;
}
} // namespace fn_000fc460


// 0x000fc4a0 CAgent::vfunc_5 (3 B): matches/0x000fc4a0.cpp
// sym: ?vfunc_5@CAgent@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void CAgent::vfunc_5(int a, int b) {}


// 0x000fc4b0 CAgent::vfunc_6 (10 B): matches/0x000fc4b0.cpp
// sym: ?vfunc_6@CAgent@@UAEXH@Z
void CAgent::vfunc_6(int value) {
    this->f_08 = value;
}


// 0x000fc4c0 CAgent::vfunc_7 (3 B): matches/0x000fc4c0.cpp
// sym: ?vfunc_7@CAgent@@UAEXH@Z
void CAgent::vfunc_7(int a) {
    (void)a;
}

namespace fn_ffab1cd7 {

// 0x000fc4d0 CAgent::vfunc_10 (3 B): matches/0x000fc4d0.cpp
// sym: ?GetZero@fn_ffab1cd7@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x000fc4e0 FUN_000fc4e0 (108 B): matches/0x000fc4e0.cpp
// sym: ?FUN_000fc4e0@CAgent_fc4e0@fn_ffab1cd7@@QAEMHH@Z
// FUN_000fc4e0 @ 0x000fc4e0
float CAgent_fc4e0::FUN_000fc4e0(hulk_intptr a, int b)
{
    float best = 0.0f;
    int idx = -1;
    for (int i = 0; i < count; i++) {
        float v = items[i]->v3(a, b);
        if (v > best) {
            best = v;
            idx = i;
        }
    }
    selected = idx;
    return best;
}


// 0x000fc550 FUN_000fc550 (123 B): matches/0x000fc550.cpp
// sym: ?Fn@Owner_fc550@fn_ffab1cd7@@QAEXHHD@Z
// data: gZero_fc550 = DAT_003f32e0
void Owner_fc550::Fn(int a, int b, char c) {
    if (cur == -1)
        return;
    if (c) {
        Elem_fc550* e = items[cur];
        if (e->f <= DAT_003f32e0) {
            Other_fc550* o = (Other_fc550*)FUN_00344e74(e, 0, (void*)((hulk_intptr)DAT_004a19e0), (void*)((hulk_intptr)DAT_004a19f8), 0);
            if (o) {
                Target_fc550* t = o->t;
                if (t)
                    t->v6();
            }
        }
    }
    items[cur]->Act(a, b, *(int*)&c);  // the original forwards the whole stack word of the char argument
    items[cur]->Fin(1);
}


// 0x000fc5d0 FUN_000fc5d0 (34 B): matches/0x000fc5d0.cpp
// sym: ?Add@Container_fc5d0@fn_ffab1cd7@@QAEHPAVItem_fc5d0@2@@Z
int Container_fc5d0::Add(Item_fc5d0* p) {
    items[count] = p;
    p->F();
    count = count + 1;
    return count - 1;
}

} // namespace fn_ffab1cd7

// 0x000fc600 CAgent::vfunc_8 (8 B): matches/0x000fc600.cpp
// sym: ?vfunc_8@CAgent@@UAEXHHH@Z
void CAgent::vfunc_8(int , int , int ) {
    FUN_000964d0();
}


// 0x000fc610 FUN_000fc610 (32 B): matches/0x000fc610.cpp [wrapped: conflict: CActorAgent]
// sym: ?target@CActorAgent@fn_000fc610@@QAEXXZ
namespace fn_000fc610 {
struct CActorAgent {
    void* vt;
    char pad[0x54];
    void* field58;
    void target();
    void finish_000fc460();
};
extern int hulk_at_0040cfb4;
struct Ref_fc610 {
    virtual void A();
    virtual void B();
};
void CActorAgent::target() {
    vt = &hulk_at_0040cfb4;
    ((Ref_fc610*)field58)->B();
    field58 = 0;
    finish_000fc460();
}
} // namespace fn_000fc610

namespace fn_ffab1cd7 {

// 0x000fc630 FUN_000fc630 (32 B): matches/0x000fc630.cpp
// sym: ?target@CCharacterAgent_fc630@fn_ffab1cd7@@QAEXXZ
// Same code shape as 0x000fc610 (propagated; names are from that function)
void CCharacterAgent_fc630::target() {
    vt = &hulk_at_0040cfe4;
    ((Ref_fc630*)field58)->B();
    field58 = 0;
    finish_000fc460();
}

} // namespace fn_ffab1cd7

// 0x000fc6a0 CAgent::vfunc_2 (30 B): matches/0x000fc6a0.cpp
// sym: ??_GCAgent@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CAgent::~CAgent() {}

