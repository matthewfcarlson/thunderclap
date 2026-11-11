// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006ab20..0x0006abf0 (kind game, layer game, confidence high), dominant class CStageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3bfd77d {
#define TREE_TU_END }
namespace fn_f3bfd77d {} using namespace fn_f3bfd77d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3bfd77d {
class CTrack_6ab40 {
  public:
    virtual int vfunc_0(int index);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};
extern int* hulk_at_004dcfe8;
class Other_6abc0 {
  public:
    int call_000201a0(hulk_intptr, int);
};
extern "C" Other_6abc0* __cdecl FUN_0008d690(int);


// 0x0006ab20 FUN_0006ab20 (19 B): matches/0x0006ab20.cpp
// sym: ?FUN_0006ab20@fn_f3bfd77d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006ab20() {
    FUN_00234810(((char*)&DAT_004dcfe8), ((char*)&DAT_004dcfec));
}

} // namespace fn_f3bfd77d

// 0x0006ab40 CStageTrack::vfunc_0 (16 B): matches/0x0006ab40.cpp
// sym: ?vfunc_0@CStageTrack@@UAEHH@Z
hulk_intptr CStageTrack::vfunc_0(int index) {
    return hulk_at_004dcfe8[index];
}


// 0x0006ab50 FUN_0006ab50 (33 B): matches/0x0006ab50.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CStageTrack@fn_0006ab50@@QAE@XZ
namespace fn_0006ab50 {
struct CTrack_00236d40 {
    CTrack_00236d40();
    virtual void v_00236d40();
};

class Base_6ab50 : public CTrack_00236d40 {
  public:
    Base_6ab50();
};

class CStageTrack : public Base_6ab50 {
  public:
    CStageTrack();
    virtual void SomeVirtual();
    char pad[4];
    int m8;
    int mC;
    int m10;
};

Base_6ab50::Base_6ab50() : CTrack_00236d40() {
}

CStageTrack::CStageTrack() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
} // namespace fn_0006ab50


// 0x0006ab80 CStageTrack::vfunc_13 (13 B): matches/0x0006ab80.cpp
// sym: ?vfunc_13@CStageTrack@@UAEXPAX@Z
// Same code shape as 0x0005e010 (propagated; names are from that function)
void CStageTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = -1;
}


// 0x0006ab90 CStageTrack::vfunc_6 (4 B): matches/0x0006ab90.cpp
// sym: ?vfunc_6@CStageTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CStageTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006aba0 CStageTrack::vfunc_7 (7 B): matches/0x0006aba0.cpp
// sym: ?vfunc_7@CStageTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CStageTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0006abc0 CStageTrack::vfunc_12 (43 B): matches/0x0006abc0.cpp
// sym: ?vfunc_12@CStageTrack@@UAEHH@Z
// Same code shape as 0x0006aaf0 (propagated; names are from that function)
hulk_intptr CStageTrack::vfunc_12(hulk_intptr param) {
    Other_6abc0* p = FUN_0008d690(0x24);
    if (p)
        return p->call_000201a0(param, this->f_10);
    return 0;
}

