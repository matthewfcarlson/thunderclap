// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006ae30..0x0006aee0 (kind game, layer game, confidence high), dominant class CDeathTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f2d8fc32 {
#define TREE_TU_END }
namespace fn_f2d8fc32 {} using namespace fn_f2d8fc32;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2d8fc32 {
extern int* hulk_at_004dd000;
class CTrack_6ae80 {
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
    virtual void vfunc_13(unsigned int*);
};
class Helper_6aec0 {
  public:
    int go_00020b50(hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);


// 0x0006ae30 FUN_0006ae30 (19 B): matches/0x0006ae30.cpp
// sym: ?FUN_0006ae30@fn_f2d8fc32@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006ae30(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dd000), ((char*)&DAT_004dd004));
}

} // namespace fn_f2d8fc32

// 0x0006ae50 CDeathTrack::vfunc_0 (16 B): matches/0x0006ae50.cpp
// sym: ?vfunc_0@CDeathTrack@@UAEHH@Z
hulk_intptr CDeathTrack::vfunc_0(int arg) {
    return hulk_at_004dd000[arg];
}


// 0x0006ae60 FUN_0006ae60 (25 B): matches/0x0006ae60.cpp [wrapped: conflict: CDeathTrack]
// sym: ??0CDeathTrack@fn_0006ae60@@QAE@XZ
namespace fn_0006ae60 {
class CTrack_6ae60 {
  public:
    virtual void f0();
    virtual void f1();
    CTrack_6ae60();
};

class CDeathTrack : public CTrack_6ae60 {
  public:
    virtual void f0();
    virtual void f1();
    char pad[8];
    int m_field;
    CDeathTrack();
};

CDeathTrack::CDeathTrack() {
    m_field = 0;
}
} // namespace fn_0006ae60


// 0x0006ae80 CDeathTrack::vfunc_13 (13 B): matches/0x0006ae80.cpp
// sym: ?vfunc_13@CDeathTrack@@UAEXPAX@Z
void CDeathTrack::vfunc_13(void* __p0) { unsigned int * param = (unsigned int *)__p0;

    *param = 0xff000000;
}


// 0x0006ae90 CDeathTrack::vfunc_6 (4 B): matches/0x0006ae90.cpp
// sym: ?vfunc_6@CDeathTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CDeathTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006aea0 CDeathTrack::vfunc_7 (7 B): matches/0x0006aea0.cpp
// sym: ?vfunc_7@CDeathTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CDeathTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0006aec0 CDeathTrack::vfunc_12 (26 B): matches/0x0006aec0.cpp
// sym: ?vfunc_12@CDeathTrack@@UAEHH@Z
// Same code shape as 0x0005e050 (propagated; names are from that function)
hulk_intptr CDeathTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_6aec0*)p)->go_00020b50(a);
    return 0;
}

