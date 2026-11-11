// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef930..0x001efb80 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f158e6c4 {
#define TREE_TU_END }
namespace fn_f158e6c4 {} using namespace fn_f158e6c4;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f158e6c4 {
class IRefCount_1ef970 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class Sub_1ef990 {
  public:
    void Cleanup_0027af50();
};
class Obj_1ef990 {
    char pad[0xa0];

  public:
    Sub_1ef990 sub;
    void* Run(int flags);
};
extern void __cdecl thunk_0008d330(Obj_1ef990*);
void __cdecl thunk_FUN_00267090(void* p);
struct Id_1ef9c0 {
};
struct Slot_1ef9c0 {
    char pad0[8];
    int a;
    int b;
    int c;
    char flag;
    char pad15[3];
    Id_1ef9c0 id;       // 0x18
    char pad1c[4];
    float weight;
    int d;
};
struct Resource_1ef9c0 {
    void FUN_001f1c80();
};
struct Sub1_1ef9c0 { void FUN_001f4f00(); };
struct Sub2_1ef9c0 { void FUN_001eaea0(); };
class Pool_1ef9c0 {
public:
    Sub1_1ef9c0* sub1;
    Sub2_1ef9c0* sub2;
    Resource_1ef9c0* resource;
    Slot_1ef9c0* slots;
    void FUN_001ef9c0(bool release);
};

} // namespace fn_f158e6c4

// 0x001ef930 FUN_001ef930 (64 B): matches/0x001ef930.cpp [wrapped: conflict: CSoundTriggerExecutionState]
// sym: ??0CSoundTriggerExecutionState@fn_001ef930@@QAE@XZ
namespace fn_001ef930 {
class Helper_1ef930 {
  public:
    void FnA_0027af00();
    void FnB_0027b040(int);
    char pad[8];
    float x;
    int y;
};
class CSoundTriggerExecutionState {
  public:
    virtual void V();
    int a, b, c, d;
    char e;
    char pad[3];
    Helper_1ef930 m;
    CSoundTriggerExecutionState();
};
CSoundTriggerExecutionState::CSoundTriggerExecutionState() {
    a = 1;
    m.FnA_0027af00();
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    m.x = 100.0f;
    m.y = 0;
    m.FnB_0027b040(0);
}
} // namespace fn_001ef930


// 0x001ef970 CSoundTriggerExecutionState::vfunc_0 (4 B): matches/0x001ef970.cpp
// sym: ?vfunc_0@CSoundTriggerExecutionState@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void CSoundTriggerExecutionState::vfunc_0() {
    ++this->f_04;
}


// 0x001ef980 CSoundTriggerExecutionState::vfunc_1 (13 B): matches/0x001ef980.cpp [wrapped: conflict: CSoundTriggerExecutionState]
// sym: ?vfunc_1@CSoundTriggerExecutionState@fn_001ef980@@UAEXXZ
namespace fn_001ef980 {
// Same code shape as 0x001e86c0 (propagated; names are from that function)
class CSoundTriggerExecutionState {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    int mRefCount;
};
void CSoundTriggerExecutionState::vfunc_1() {
    if (--mRefCount == 0)
        vfunc_2(1);
}
} // namespace fn_001ef980

namespace fn_f158e6c4 {

// 0x001ef990 FUN_001ef990 (36 B): matches/0x001ef990.cpp
// sym: ?Run@Obj_1ef990@fn_f158e6c4@@QAEPAXH@Z
void* Obj_1ef990::Run(int flags) {
    sub.Cleanup_0027af50();
    if (flags & 1)
        thunk_0008d330(this);
    return this;
}


// 0x001ef9c0 FUN_001ef9c0 (122 B): matches/0x001ef9c0.cpp
// sym: ?FUN_001ef9c0@Pool_1ef9c0@fn_f158e6c4@@QAEX_N@Z
// FUN_001ef9c0 @ 0x001ef9c0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void Pool_1ef9c0::FUN_001ef9c0(bool release) {
    for (int off = 0; off < 100 * 0x28; off += 0x28) {
        Slot_1ef9c0* s = (Slot_1ef9c0*)((char*)slots + off);
        s->a = 0;
        s->b = 0;
        s->c = 0;
        s->flag = 0;
        s->weight = 100.0f;
        s->d = 0;
        ((owners::Target_27b040 *)&(s->id))->FUN_0027b040((hulk_uintptr)0);
    }
    if (release) {
        Resource_1ef9c0* r = resource;
        if (r) {
            r->FUN_001f1c80();
            thunk_FUN_00267090(r);
        }
        resource = 0;
    }
    sub1->FUN_001f4f00();
    if (release)
        sub2->FUN_001eaea0();
}

} // namespace fn_f158e6c4
