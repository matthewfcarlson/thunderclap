// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010df90..0x0010e040 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f83e04cb {
#define TREE_TU_END }
namespace fn_f83e04cb {} using namespace fn_f83e04cb;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f83e04cb {
struct Param_10df90 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10df90 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Context_10dfa0;
struct Inner_10dfa0 {
    Context_10dfa0* Get();
    void* FUN_00059a30();
};
struct Context_10dfa0 {
    void* FUN_00059a30();
};
struct Context_10dfd0;
struct Inner_10dfd0 {
    Context_10dfd0* Get();
    void* FUN_00059a30();
};
struct Context_10dfd0 {
    void* FUN_00059a30();
};
struct Inner_10e000;
struct Mid_10e000 {
    int a;
};
struct Ret_10e000 {
    void last();
};
struct Obj_10e000 {
};
struct Inner_10e000 {
    Mid_10e000* getB();
};
struct State_10e000 {
    char pad[0x14];
    u8 flag;
};
Ret_10e000* FUN_678d0();

} // namespace fn_f83e04cb

// 0x0010df90 hulkfight::ai::TokenTrack::vfunc_7 (7 B): matches/0x0010df90.cpp
// sym: ?vfunc_7@TokenTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::TokenTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0010dfa0 hulkfight::ai::TokenAction::vfunc_3 (36 B): matches/0x0010dfa0.cpp
// sym: ?vfunc_3@TokenAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::TokenAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    Context_10dfa0* c = (*(Context_10dfa0 * *)&this->f_20);
    if (!c)
        return false;
    Context_10dfa0* d = ((Context_10dfa0 *)((owners::Object_592a0 *)c)->FUN_000592a0());
    char* p = (char*)d->FUN_00059a30();
    p[0x1b84] = 1;
    return true;
}


// 0x0010dfd0 hulkfight::ai::TokenAction::vfunc_5 (36 B): matches/0x0010dfd0.cpp
// sym: ?vfunc_5@TokenAction@ai@hulkfight@@UAE_NHH@Z
// Same code shape as 0x0010dfa0 (propagated; names are from that function)
bool hulkfight::ai::TokenAction::vfunc_5(hulk_intptr __p0, int __p1) {
    Context_10dfd0* c = (*(Context_10dfd0 * *)&this->f_20);
    if (!c)
        return false;
    Context_10dfd0* d = ((Context_10dfd0 *)((owners::Object_592a0 *)c)->FUN_000592a0());
    char* p = (char*)d->FUN_00059a30();
    p[0x1b84] = 1;
    return true;
}


// 0x0010e000 hulkfight::ai::TokenAction::vfunc_4 (54 B): matches/0x0010e000.cpp
// sym: ?vfunc_4@TokenAction@ai@hulkfight@@UAEXXZ
void hulkfight::ai::TokenAction::vfunc_4() {
    if ((*(Obj_10e000 * *)&this->f_20)) {
        Inner_10e000* a = ((Inner_10e000 *)((owners::Object_592a0 *)((*(Obj_10e000 * *)&this->f_20)))->FUN_000592a0());
        Mid_10e000* b = a->getB();
        *((u8*)b + 0x1b84) = 0;
        if ((*(State_10e000 * *)&this->f_1c)->flag) {
            FUN_678d0()->last();
        }
    }
}

