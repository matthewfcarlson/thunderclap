// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00048440..0x00048650 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f7d9f22f {
#define TREE_TU_END }
namespace fn_f7d9f22f {} using namespace fn_f7d9f22f;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f7d9f22f {
extern int* hulk_at_004dc400;
class CCondition_48470 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc408;
class CCondition_48510 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_f7d9f22f

// 0x00048440 CControllerCondition::vfunc_7 (5 B): matches/0x00048440.cpp [wrapped: conflict: CControllerCondition]
// sym: ?vfunc_7@CControllerCondition@fn_00048440@@UAEXXZ
namespace fn_00048440 {
class CControllerCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
};

void CControllerCondition::vfunc_7() {
    return vfunc_8();
}
} // namespace fn_00048440

namespace fn_f7d9f22f {

// 0x00048450 FUN_00048450 (19 B): matches/0x00048450.cpp
// sym: ?FUN_00048450@fn_f7d9f22f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048450() {
    FUN_00234810(((char*)&DAT_004dc400), ((char*)&DAT_004dc404));
}

} // namespace fn_f7d9f22f

// 0x00048470 CButtonCondition::vfunc_0 (16 B): matches/0x00048470.cpp
// sym: ?vfunc_0@CButtonCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CButtonCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc400;
    return p[index];
}


// 0x00048480 FUN_00048480 (41 B): matches/0x00048480.cpp [wrapped: conflict: CButtonCondition]
// sym: ?FUN_00048480@fn_00048480@@YIPAUCButtonCondition@1@PAU21@@Z
namespace fn_00048480 {
struct CButtonCondition {
    void* vptr;
    int x04, x08, x0c, x10, x14;
};
struct ThisCall_00234590 {
    void Init_00234590(int);
};
extern char hulk_at_003f6dc0;
CButtonCondition* __fastcall FUN_00048480(CButtonCondition* self) {
    ((ThisCall_00234590*)(self))->Init_00234590(0);
    self->vptr = &hulk_at_003f6dc0;
    self->x0c = 0;
    self->x10 = 4;
    self->x14 = 0;
    return self;
}
} // namespace fn_00048480


// 0x000484c0 CButtonCondition::vfunc_8 (44 B): matches/0x000484c0.cpp [wrapped: conflict: CButtonCondition]
// sym: ?f9@CButtonCondition@fn_000484c0@@UAEXPAX@Z
namespace fn_000484c0 {
struct A_484c0 {
    void* Fnf_000592a0();
};
struct B_484c0 {
    int Fnf_00059a30();
};
struct CButtonCondition {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(void*);
    virtual void f10();
    char pad[8];
    int mIndex;
};
void CButtonCondition::f9(void* arg) {
    void* p = ((A_484c0*)arg)->Fnf_000592a0();
    hulk_intptr v = ((B_484c0*)p)->Fnf_00059a30();
    f9((void*)(v + 0x1f58 + mIndex * 12));
}
} // namespace fn_000484c0

namespace fn_f7d9f22f {

// 0x000484f0 FUN_000484f0 (19 B): matches/0x000484f0.cpp
// sym: ?FUN_000484f0@fn_f7d9f22f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000484f0() {
    FUN_00234810(((char*)&DAT_004dc408), ((char*)&DAT_004dc40c));
}

} // namespace fn_f7d9f22f

// 0x00048510 CButtonValueCondition::vfunc_0 (16 B): matches/0x00048510.cpp
// sym: ?vfunc_0@CButtonValueCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CButtonValueCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc408;
    return p[index];
}


// 0x00048520 FUN_00048520 (52 B): matches/0x00048520.cpp [wrapped: conflict: CButtonValueCondition]
// sym: ?FUN_00048520@fn_00048520@@YIPAVCButtonValueCondition@1@PAV21@@Z
namespace fn_00048520 {
extern int hulk_at_003f6df0;
class CButtonValueCondition {
  public:
    hulk_intptr vf;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
};
struct ThisCall_00234590 {
    void* FUN_00234590(void*);   // (x64t7) fight::Condition's constructor: takes a pointer (was `int`), returns `this`
};
CButtonValueCondition* __fastcall FUN_00048520(CButtonValueCondition* self) {
    ((ThisCall_00234590*)(self))->FUN_00234590(0);
    self->x4 = 4;
    self->x6 = 4;
    self->x3 = 0;
    self->x5 = 0;
    self->vf = (hulk_intptr)&hulk_at_003f6df0;
    self->x7 = 0;
    return self;
}
} // namespace fn_00048520


// 0x00048570 CButtonPressCondition::vfunc_10 (17 B): matches/0x00048570.cpp
// sym: ?vfunc_10@CButtonPressCondition@@UAE_NPAXH@Z
bool CButtonPressCondition::vfunc_10(void* __p0, hulk_intptr unused) { int * param = (int *)__p0;

    return *param == 1;
}


// 0x00048590 CButtonDownCondition::vfunc_10 (46 B): matches/0x00048590.cpp
// sym: ?vfunc_10@CButtonDownCondition@@UAE_NPAXH@Z
bool CButtonDownCondition::vfunc_10(void* __p0, hulk_intptr __p1) { int * p = (int *)__p0; int * out = (int *)__p1;

    switch (*p) {
    case 1:
        *out = 0;
        return true;
    case 2:
        *out = p[1];
        return true;
    default:
        return false;
    }
}


// 0x000485c0 CButtonReleaseCondition::vfunc_10 (17 B): matches/0x000485c0.cpp
// sym: ?vfunc_10@CButtonReleaseCondition@@UAE_NPAXH@Z
bool CButtonReleaseCondition::vfunc_10(void* __p0, hulk_intptr unused) { int * param = (int *)__p0;

    return *param == 3;
}


// 0x000485e0 CButtonUpCondition::vfunc_10 (49 B): matches/0x000485e0.cpp
// sym: ?vfunc_10@CButtonUpCondition@@UAE_NPAXH@Z
bool CButtonUpCondition::vfunc_10(void* __p0, hulk_intptr __p1) { int * p = (int *)__p0; int * out = (int *)__p1;

    int n = *p;
    if (n != 0) {
        if (n != 3)
            return (bool)(false);
        *out = 0;
    } else {
        *out = p[1];
    }
    return (bool)(true);
}

