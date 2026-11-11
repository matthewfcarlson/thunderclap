// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001817d0..0x001819f0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropStateByIndexCondition
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc016f38 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc016f38 {} using namespace fn_fc016f38;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc016f38 {
typedef unsigned int u32_1817d0;
struct ThisCall_00035ef0 {
};
class Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(void*, void*, void*);
};
namespace hulkfight { namespace motion {
class PropAtRestCondition : public Condition {
  public:
    char pad[8];
    char value;
    char vfunc_6(void*, void*, void*);
};
} }
struct Item_181800 {
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
    virtual char f11();
};
struct A_181800 {
    void* get_000592a0();
};
struct B_181800 {
    void* get_00059a30();
};
struct S_181800 {
    char ready_001d7300();
    void* part_001d72e0();
};
extern "C" int __cdecl Check(void*, void*, void*, void*, void*);
extern char hulk_at_00494b44[];
extern char hulk_at_00494b60[];
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
struct Status_181880 {
    char FUN_001d4e40();
};
struct Part_181880 {
    char pad0[0xec];
    Status_181880 *status;
};
struct Res_181880 {
    char pad00[0x128];
    Part_181880 *mainPart;
    Part_181880 *FUN_00035ef0(int index);
};
struct Resolver_181880 {
    Res_181880 *FUN_00059a30();
};
struct Target_181880 {
    Resolver_181880 *FUN_000592a0();
};
namespace hulkfight { namespace motion {
class PropMissionCriticalCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, void *obj, int c);
    char pad04[8];
    int partIndex;      // +0x0c
    char wanted;        // +0x10
};
} }


// 0x001817d0 FUN_001817d0 (38 B): matches/0x001817d0.cpp
// sym: _FUN_001817d0
extern "C" u32_1817d0 __cdecl FUN_001817d0(void* p, int n) {
    if (p) {
        if (n < 0)
            return *(u32_1817d0*)((char*)p + 0x128);
        if (n < 8)
            return ((unsigned int)((owners::C_35ef0 *)(((ThisCall_00035ef0*)(p))))->FUN_00035ef0((hulk_intptr)n));
    }
    return 0;
}


// 0x00181800 hulkfight::motion::PropAtRestCondition::vfunc_6 (124 B): matches/0x00181800.cpp
// sym: ?vfunc_6@PropAtRestCondition@motion@hulkfight@fn_fc016f38@@UAEDPAX00@Z
char hulkfight::motion::PropAtRestCondition::vfunc_6(void* a, void* c, void* d) {
    if (!Check(c, 0, hulk_at_00494b44, hulk_at_00494b60, 0))
        return 0;
    char result = 0;
    A_181800* obj = (A_181800*)c;
    void* p = obj->get_000592a0();
    B_181800* mot = (B_181800*)p;
    p = mot->get_00059a30();
    void* state = *(void**)((char*)p + 0x128);
    if (state && ((S_181800*)state)->ready_001d7300() && *(int*)((char*)((S_181800*)state)->part_001d72e0() + 0x6c) == 1) {
        void* part = ((S_181800*)state)->part_001d72e0();
        Item_181800* item = *(Item_181800**)((char*)part + 0x70);
        char v = value;
        result = item->f11() == v;
    }
    return result;
}


// 0x00181880 hulkfight::motion::PropMissionCriticalCondition::vfunc_6 (124 B): equivalent/0x00181880.cpp
// sym: ?vfunc_6@PropMissionCriticalCondition@motion@hulkfight@fn_fc016f38@@UAE_NHPAXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PropMissionCriticalCondition::vfunc_6 @ 0x00181880
bool hulkfight::motion::PropMissionCriticalCondition::vfunc_6(int a, void *obj, int c) {
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0)) {
        return false;
    }
    bool result = false;
    Res_181880 *res = ((Target_181880 *)obj)->FUN_000592a0()->FUN_00059a30();
    if (res != 0) {
        Part_181880 *part;
        if (partIndex < 0) {
            part = res->mainPart;
        } else if (partIndex < 8) {
            part = res->FUN_00035ef0(partIndex);
        } else {
            return false;
        }
        if (part != 0) {
            char want = wanted;
            result = part->status->FUN_001d4e40() == want;
        }
    }
    return result;
}

} // namespace fn_fc016f38

// 0x00181900 hulkfight::motion::PropStateByIndexCondition::vfunc_6 (205 B): equivalent/0x00181900.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60]
// sym: ?vfunc_6@PropStateByIndexCondition@motion@hulkfight@fn_00181900@@UAE_NPAXPAUContext@4@0@Z
namespace fn_00181900 {
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 30/30)
// hulkfight::motion::PropStateByIndexCondition::vfunc_6 @ 0x00181900
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Prop_181900 { char pad[0x40]; int state; };
struct Collection_181900 { char pad[0x128]; Prop_181900* current; Prop_181900* FUN_00035ef0(int); };
struct Actor_181900 { Collection_181900* FUN_00059a30(); };
struct Context { Actor_181900* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct PropStateByIndexCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Context*, void*);
 char pad[8]; int index; unsigned operation; int expected;
};
bool PropStateByIndexCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
 Actor_181900* actor = context->FUN_000592a0();
 Collection_181900* collection = actor->FUN_00059a30();
 if (!collection) return false;
 Prop_181900* prop;
 if (index < 0) prop = collection->current;
 else { if (index >= 8) return false; prop = collection->FUN_00035ef0(index); }
 if (!prop) return false;
 int value = prop->state;
 switch (operation) {
 case 0: return value < expected;
 case 1: return value <= expected;
 case 2: return value == expected;
 case 3: return value != expected;
 case 4: return value >= expected;
 case 5: return value > expected;
 default: return false;
 }
}
}}
} // namespace fn_00181900

