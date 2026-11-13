// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a680..0x0006a760 (kind game, layer game, confidence high), dominant class COrientTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fe8db869 {
#define TREE_TU_END }
namespace fn_fe8db869 {} using namespace fn_fe8db869;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe8db869 {
extern int* hulk_at_004dcfc0;
class CCondition_6a6a0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6a710 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a710 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_6a730 {
    int FUN_0001fa20(COrientTrack*, hulk_intptr);
};


// 0x0006a680 FUN_0006a680 (19 B): matches/0x0006a680.cpp
// sym: ?FUN_0006a680@fn_fe8db869@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a680(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcfc0), ((char*)&DAT_004dcfc4));
}

} // namespace fn_fe8db869

// 0x0006a6a0 COrientTrack::vfunc_0 (16 B): matches/0x0006a6a0.cpp
// sym: ?vfunc_0@COrientTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr COrientTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcfc0;
    return p[index];
}


// 0x0006a6b0 FUN_0006a6b0 (59 B): matches/0x0006a6b0.cpp [wrapped: conflict: COrientTrack]
// sym: ??0COrientTrack@fn_0006a6b0@@QAE@XZ
namespace fn_0006a6b0 {
class CTrack_6a6b0 {
  public:
    CTrack_6a6b0();
    virtual hulk_intptr FnB_0006a6a0(int);
};
class COrientTrack : public CTrack_6a6b0 {
  public:
    COrientTrack();
    virtual ~COrientTrack() throw();
    virtual bool FnF_002342b0(int);
    char pad4[4];
    int m8;
    int m0c;
    float m10;
    float m14;
    int m18;
    char m1c;
    int m20;
    int m24;
    int m28;
};

COrientTrack::COrientTrack() {
    m0c = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m10 = -1.0f;
    m14 = -0.0174532925f;
    m8 = 1;
}
} // namespace fn_0006a6b0


// 0x0006a6f0 COrientTrack::vfunc_13 (13 B): matches/0x0006a6f0.cpp
// sym: ?vfunc_13@COrientTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void COrientTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x0006a700 COrientTrack::vfunc_6 (4 B): matches/0x0006a700.cpp
// sym: ?vfunc_6@COrientTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg COrientTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a710 COrientTrack::vfunc_7 (7 B): matches/0x0006a710.cpp
// sym: ?vfunc_7@COrientTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg COrientTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006a730 COrientTrack::vfunc_12 (40 B): matches/0x0006a730.cpp
// sym: ?vfunc_12@COrientTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr COrientTrack::vfunc_12(hulk_intptr param) {
    Helper_6a730* p = (Helper_6a730*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001fa20(this, param);
    return 0;
}

