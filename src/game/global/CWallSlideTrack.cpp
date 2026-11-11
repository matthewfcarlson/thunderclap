// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b140..0x0006b220 (kind game, layer game, confidence high), dominant class CWallSlideTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3696309 {
#define TREE_TU_END }
namespace fn_f3696309 {} using namespace fn_f3696309;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3696309 {
extern int* hulk_at_004dd020;
class CCondition_6b160 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6b1d0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6b1d0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Alloc_6b1f0 {
  public:
    int method_00020d50(CWallSlideTrack*, hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);


// 0x0006b140 FUN_0006b140 (19 B): matches/0x0006b140.cpp
// sym: ?FUN_0006b140@fn_f3696309@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006b140() {
    FUN_00234810(((char*)&DAT_004dd020), ((char*)&DAT_004dd024));
}

} // namespace fn_f3696309

// 0x0006b160 CWallSlideTrack::vfunc_0 (16 B): matches/0x0006b160.cpp
// sym: ?vfunc_0@CWallSlideTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CWallSlideTrack::vfunc_0(int index) {
    int* p = hulk_at_004dd020;
    return p[index];
}


// 0x0006b170 FUN_0006b170 (60 B): matches/0x0006b170.cpp [wrapped: conflict: CWallSlideTrack]
// sym: ??0CWallSlideTrack@fn_0006b170@@QAE@XZ
namespace fn_0006b170 {
class CTrack_6b170 {
  public:
    CTrack_6b170();
    virtual void vf();
    char pad[8];
};
class CWallSlideTrack : public CTrack_6b170 {
  public:
    CWallSlideTrack();
    int a;
    float b, c;
    int d;
    float e, ff;
    int g, h, i;
    virtual void vf();
};
CWallSlideTrack::CWallSlideTrack() : CTrack_6b170() {
    a = 0;
    b = -1.0f;
    c = 20.0f;
    d = 0;
    e = 20.0f;
    ff = 1.0f;
    g = 0;
    h = 0;
    i = 0;
}
} // namespace fn_0006b170


// 0x0006b1b0 CWallSlideTrack::vfunc_13 (13 B): matches/0x0006b1b0.cpp
// sym: ?vfunc_13@CWallSlideTrack@@UAEXPAX@Z
void CWallSlideTrack::vfunc_13(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    *out = 0xff7f1f1f;
}


// 0x0006b1c0 CWallSlideTrack::vfunc_6 (4 B): matches/0x0006b1c0.cpp
// sym: ?vfunc_6@CWallSlideTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CWallSlideTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006b1d0 CWallSlideTrack::vfunc_7 (7 B): matches/0x0006b1d0.cpp
// sym: ?vfunc_7@CWallSlideTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CWallSlideTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006b1e0 FUN_0006b1e0 (11 B): matches/0x0006b1e0.cpp [wrapped: conflict: CTrack]
// sym: ??1CTrack@fn_0006b1e0@@UAE@XZ
namespace fn_0006b1e0 {
class Track_6b1e0 {
  public:
    virtual ~Track_6b1e0() throw();
};
class CTrack : public Track_6b1e0 {
  public:
    virtual ~CTrack() throw();
};
CTrack::~CTrack() throw() {}
} // namespace fn_0006b1e0


// 0x0006b1f0 CWallSlideTrack::vfunc_12 (40 B): matches/0x0006b1f0.cpp
// sym: ?vfunc_12@CWallSlideTrack@@UAEHH@Z
hulk_intptr CWallSlideTrack::vfunc_12(hulk_intptr param) {
    Alloc_6b1f0* p = (Alloc_6b1f0*)FUN_0008d690(0x38);
    if (p)
        return p->method_00020d50(this, param);
    return 0;
}

