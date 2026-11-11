// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a4d0..0x0006a5a0 (kind game, layer game, confidence high), dominant class CCameraHintTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3c43a12 {
#define TREE_TU_END }
namespace fn_f3c43a12 {} using namespace fn_f3c43a12;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3c43a12 {
struct Param_6a550 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a550 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class R_6a570 {
  public:
    int invoke_0001f900(CCameraHintTrack*, hulk_intptr);
};
extern "C" R_6a570* FUN_0008d690(int);


// 0x0006a4d0 FUN_0006a4d0 (19 B): matches/0x0006a4d0.cpp
// sym: ?FUN_0006a4d0@fn_f3c43a12@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a4d0() {
    FUN_00234810(((char*)&DAT_004dcfb0), ((char*)&DAT_004dcfb4));
}


// 0x0006a4f0 CCameraHintTrack::vfunc_0 (16 B): matches/0x0006a4f0.cpp
// sym: _FUN_0006a4f0@4
// data: g_table_6a4f0 = DAT_004dcfb0
extern "C" int __stdcall FUN_0006a4f0(int i) {
    return (*(int**)&DAT_004dcfb0)[i];
}

} // namespace fn_f3c43a12

// 0x0006a500 FUN_0006a500 (40 B): matches/0x0006a500.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0CCameraHintTrack@fn_0006a500@@QAE@XZ
namespace fn_0006a500 {
class Base_6a500 {
  public:
    Base_6a500();
    virtual void f1();
    char m_base[4];
};

class CCameraHintTrack : public Base_6a500 {
  public:
    CCameraHintTrack();
    virtual void f1();
    virtual void f2() {}
    int m_a;
    int m_b;
    float m_c;
    int m_d;
};

void Base_6a500::f1() {}
void CCameraHintTrack::f1() {}

CCameraHintTrack::CCameraHintTrack() {
    m_b = 0;
    m_d = 0;
    m_c = -1.0f;
    m_a = 1;
}
} // namespace fn_0006a500


// 0x0006a530 CCameraHintTrack::vfunc_13 (13 B): matches/0x0006a530.cpp
// sym: ?vfunc_13@CCameraHintTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CCameraHintTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a540 CCameraHintTrack::vfunc_6 (4 B): matches/0x0006a540.cpp
// sym: ?vfunc_6@CCameraHintTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CCameraHintTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0006a550 CCameraHintTrack::vfunc_7 (7 B): matches/0x0006a550.cpp
// sym: ?vfunc_7@CCameraHintTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CCameraHintTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0006a570 CCameraHintTrack::vfunc_12 (40 B): matches/0x0006a570.cpp
// sym: ?vfunc_12@CCameraHintTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CCameraHintTrack::vfunc_12(hulk_intptr param) {
    R_6a570* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001f900(this, param);
    return 0;
}

