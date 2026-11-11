// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00068ed0..0x00068f90 (kind game, layer game, confidence high), dominant class CClimbingTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fbaf860d {
#define TREE_TU_END }
namespace fn_fbaf860d {} using namespace fn_fbaf860d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbaf860d {
extern int* hulk_at_004dcf18;
struct Param_68f40 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_68f40 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class R_68f60 {
  public:
    int invoke_00018c20(CClimbingTrack*, hulk_intptr);
};
extern "C" R_68f60* FUN_0008d690(int);


// 0x00068ed0 FUN_00068ed0 (19 B): matches/0x00068ed0.cpp
// sym: ?FUN_00068ed0@fn_fbaf860d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00068ed0() {
    FUN_00234810(((char*)&DAT_004dcf18), ((char*)&DAT_004dcf1c));
}

} // namespace fn_fbaf860d

// 0x00068ef0 CClimbingTrack::vfunc_0 (16 B): matches/0x00068ef0.cpp
// sym: ?vfunc_0@CClimbingTrack@@UAEHH@Z
hulk_intptr CClimbingTrack::vfunc_0(int index) {
    return hulk_at_004dcf18[index];
}


// 0x00068f00 FUN_00068f00 (39 B): matches/0x00068f00.cpp [wrapped: conflict: CClimbingTrack]
// sym: ??0CClimbingTrack@fn_00068f00@@QAE@XZ
namespace fn_00068f00 {
class CTrack_68f00 {
  public:
    virtual void b0();
    virtual void b1();
    CTrack_68f00();
};

class CClimbingTrack : public CTrack_68f00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4_00068f30();
    CClimbingTrack();
    char pad[4]; // offset 4
    int m8;      // offset 8
    int m_c;     // offset 0xc
    float m10;   // offset 0x10
};

CClimbingTrack::CClimbingTrack() {
    m_c = 0;
    m10 = -1.0f;
    m8 = 1;
}
} // namespace fn_00068f00


// 0x00068f30 CClimbingTrack::vfunc_6 (4 B): matches/0x00068f30.cpp
// sym: ?vfunc_6@CClimbingTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CClimbingTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00068f40 CClimbingTrack::vfunc_7 (7 B): matches/0x00068f40.cpp
// sym: ?vfunc_7@CClimbingTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CClimbingTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x00068f60 CClimbingTrack::vfunc_12 (40 B): matches/0x00068f60.cpp
// sym: ?vfunc_12@CClimbingTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CClimbingTrack::vfunc_12(hulk_intptr param) {
    R_68f60* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_00018c20(this, param);
    return 0;
}

