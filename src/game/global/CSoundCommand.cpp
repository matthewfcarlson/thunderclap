// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001eecb0..0x001eee90 (kind game, layer game, confidence medium), dominant class CSoundCommand
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f15f39d0 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f15f39d0 {} using namespace fn_f15f39d0;
namespace fn_f15f39d0 { extern "C" char DAT_004245a4[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f15f39d0 {
class Obj_1eecb0 {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    int d;
    float value;
};
extern "C" void __fastcall FUN_0027af00(void*);
class Sub_1eed20 {
  public:
};
class Obj_1eed20 {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    unsigned char d;
    char pad2[11];
    float f;
    int g;
};
struct Pair {
    int a, b;
};
struct Sub {
    int q, r;
};
struct Obj {
    char pad0[8];
    int a;
    float f;
    int zero;
    char flag;
    char pad1[3];
    Sub sub;
    int other;
    float old;
    void Fn(int, Pair*, int, float);
};
struct Sub_1eedd0 {
    int x;
};
struct X_1eedd0 {
    void* vptr;
    char pad[0x14];
    Sub_1eedd0 sub;
};
extern "C" void __fastcall Init_0027af50(Sub_1eedd0*);
extern void* hulk_at_003f6098;
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001eecb0 FUN_001eecb0 (33 B): matches/0x001eecb0.cpp
// sym: ?FUN_001eecb0@fn_f15f39d0@@YIPAVObj_1eecb0@1@PAV21@@Z
Obj_1eecb0* __fastcall FUN_001eecb0(Obj_1eecb0* self) {
    FUN_0027af00((void*)(self));
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->value = 100.0f;
    return self;
}


// 0x001eed20 FUN_001eed20 (34 B): matches/0x001eed20.cpp
// sym: ?FUN_001eed20@fn_f15f39d0@@YIXPAVObj_1eed20@1@@Z
void __fastcall FUN_001eed20(Obj_1eed20* self) {
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->f = 100.0f;
    self->g = 0;
    ((owners::Target_27b040 *)(((Sub_1eed20*)((char*)self + 0x18))))->FUN_0027b040((hulk_uintptr)0);
}


// 0x001eed50 FUN_001eed50 (79 B): matches/0x001eed50.cpp
// sym: ?Fn@Obj@fn_f15f39d0@@QAEXHPAUPair@2@HM@Z
void Obj::Fn(int x, Pair* p, int y, float z) {
    f -= old;
    a = x;
    zero = 0;
    flag = 1;
    other = y;
    old = z;
    if (p)
        ((owners::Pair_27af60 *)&sub)->FUN_0027af60(p->a, p->b);
    else
        ((owners::Pair_27af60 *)&sub)->FUN_0027af60(0, 0);
}


// 0x001eedd0 FUN_001eedd0 (19 B): matches/0x001eedd0.cpp
// sym: ?Target@fn_f15f39d0@@YIXPAUX_1eedd0@1@@Z
void __fastcall Target(X_1eedd0* self) {
    Init_0027af50(&self->sub);
    self->vptr = &hulk_at_003f6098;
}


// 0x001eee70 CSoundCommand::vfunc_0 (31 B): matches/0x001eee70.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f15f39d0@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004245a4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f15f39d0
