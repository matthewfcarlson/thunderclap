// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d5b0..0x0010d840 (kind game, layer game, confidence medium), dominant class hulkfight::ai::ButtonAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb3863ec {
#define TREE_TU_END }
namespace fn_fb3863ec {} using namespace fn_fb3863ec;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fb3863ec {
struct Tail_10d5b0 {
    void Init_0027af50();
};
struct SemaphoreWaitTrack_10d5b0 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0040dd04;
extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
class P_10d6b0 {
  public:
};
class Q_10d6b0 {
  public:
    void* query_00059a30();
};
extern int __cdecl FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);
extern int cast(void*, int, const void*, const void*, int);
extern char hulk_at_00494b44[];
extern char hulk_at_00494b60[];
struct Helper1_10d710 {
    void* Get_000592a0();
};
struct Helper2_10d710 {
    void* Get_00059a30();
};
class DefendingCondition_10d710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void* a, void* p, void* b);
    char pad[8];
    u8 value;
};
struct A_10d770 {
    int f1_00059a30();
};
struct B_10d770 {
    char pad[0x14];
    int a14;
    int a18;
    int a1c;
    int a20;
};
class Action_10d7d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float Get();
    char pad04[0x10];
    int m14;
    int m18;
};
class State_10d7d0 {
  public:
    char pad[4];
};
class Manager_10d7d0 {
  public:
    char* Second_00059a30();
};


// 0x0010d5b0 FUN_0010d5b0 (25 B): matches/0x0010d5b0.cpp
// sym: ?Run@SemaphoreWaitTrack_10d5b0@fn_fb3863ec@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void SemaphoreWaitTrack_10d5b0::Run() {
    vptr = &hulk_at_0040dd04;
    ((Tail_10d5b0*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}

} // namespace fn_fb3863ec

// 0x0010d6b0 hulkfight::ai::LeashedCondition::vfunc_6 (89 B): matches/0x0010d6b0.cpp
// sym: ?vfunc_6@LeashedCondition@ai@hulkfight@@UAE_NPAX00@Z
bool hulkfight::ai::LeashedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; void * params = (void *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    int ok = FUN_00344e74(params, 0, ((hulk_intptr)DAT_00494b44), ((hulk_intptr)DAT_00494b60), 0);
    if (!ok)
        return false;
    void* a = ((void *)((owners::Object_592a0 *)(((P_10d6b0*)params)))->FUN_000592a0());
    void* b = ((Q_10d6b0*)a)->query_00059a30();
    if (!b)
        return false;
    void* c = *(void**)((char*)b + 0x1ca0);
    if (!c)
        return false;
    return *((unsigned char*)c + 0xe8) == this->f_0c;
}

namespace fn_fb3863ec {

// 0x0010d710 hulkfight::ai::DefendingCondition::vfunc_6 (96 B): matches/0x0010d710.cpp
// sym: ?vfunc_6@DefendingCondition_10d710@fn_fb3863ec@@UAE_NPAX00@Z
bool DefendingCondition_10d710::vfunc_6(void* a, void* p, void* b) {
    if (cast(p, 0, hulk_at_00494b44, hulk_at_00494b60, 0)) {
        void* x = ((Helper1_10d710*)p)->Get_000592a0();
        void* q = ((Helper2_10d710*)x)->Get_00059a30();
        if (q) {
            void* v = *(void**)((char*)q + 0x1ca0);
            if (v) {
                char* t = (char*)v + 0x58;
                if (t)
                    return *(u8*)((char*)v + 0x9e) == value;
            }
        }
    }
    return false;
}

} // namespace fn_fb3863ec

// 0x0010d770 hulkfight::ai::ButtonAction::vfunc_5 (82 B): matches/0x0010d770.cpp
// sym: ?vfunc_5@ButtonAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::ButtonAction::vfunc_5(hulk_intptr p, int q) {
    if (p == 0) {
        if (!(*(A_10d770 * *)&this->f_20))
            return (bool)(0);
        A_10d770* r = ((A_10d770 *)((owners::Object_592a0 *)((*(A_10d770 * *)&this->f_20)))->FUN_000592a0());
        hulk_intptr base = r->f1_00059a30();
        int* d = (int*)(base + 0x1f58);
        d = d + (*(B_10d770 * *)&this->f_1c)->a14 * 3;
        d[0] = (*(B_10d770 * *)&this->f_1c)->a18;
        d[1] = (*(B_10d770 * *)&this->f_1c)->a1c;
        d[2] = (*(B_10d770 * *)&this->f_1c)->a20;
    }
    return (bool)(1);
}


// 0x0010d7d0 hulkfight::ai::ButtonAction::vfunc_4 (102 B): matches/0x0010d7d0.cpp
// sym: ?vfunc_4@ButtonAction@ai@hulkfight@@UAEXXZ
// data: gZero_10d7d0 = DAT_003f32e0
void hulkfight::ai::ButtonAction::vfunc_4() {
    if ((*(State_10d7d0 * *)&this->f_20) && ((*(Action_10d7d0 * *)&this->f_1c)->m18 == 2 || (*(Action_10d7d0 * *)&this->f_1c)->m18 == 1)) {
        float f = (*(Action_10d7d0 * *)&this->f_1c)->Get();
        if (f < DAT_003f32e0 || f > DAT_003f32e0) {
            Manager_10d7d0* m = (Manager_10d7d0*)(*(State_10d7d0 * *)&this->f_20);
            char* v = ((Manager_10d7d0*)((void *)((owners::Object_592a0 *)m)->FUN_000592a0()))->Second_00059a30() + 0x1f58;
            *(int*)(v + (*(Action_10d7d0 * *)&this->f_1c)->m14 * 12) = 0;
        }
    }
}

