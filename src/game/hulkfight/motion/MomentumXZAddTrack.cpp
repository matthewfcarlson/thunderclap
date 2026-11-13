// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170600..0x00170690 (kind game, layer game, confidence high), dominant class hulkfight::motion::MomentumXZAddTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f2cad3c1 {
#define TREE_TU_END }
namespace fn_f2cad3c1 {} using namespace fn_f2cad3c1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2cad3c1 {
extern int* hulk_at_004e1348;
class CCondition_170620 {
  public:
    virtual int vfunc_0(int);
};
class Track_170630 {
  public:
    Track_170630();
    virtual void f();
    char pad[4];
};
class MomentumXZAddTrack : public ::hulkfight::motion::MomentumXZAddTrack {
  public:
    MomentumXZAddTrack();
};
struct Param_170670 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170670 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170600 FUN_00170600 (19 B): matches/0x00170600.cpp
// sym: ?FUN_00170600@fn_f2cad3c1@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170600() {
    FUN_00234810(((char*)&DAT_004e1348), ((char*)&DAT_004e134c));
}

} // namespace fn_f2cad3c1

// 0x00170620 hulkfight::motion::MomentumXZAddTrack::vfunc_0 (16 B): matches/0x00170620.cpp
// sym: ?vfunc_0@MomentumXZAddTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MomentumXZAddTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1348;
    return p[index];
}

namespace fn_f2cad3c1 {

// 0x00170630 FUN_00170630 (43 B): matches/0x00170630.cpp
// sym: ??0MomentumXZAddTrack@fn_f2cad3c1@@QAE@XZ
MomentumXZAddTrack::MomentumXZAddTrack() {
    timeEnd = -1.0f;
    finalVelocity = -1.0f;
    timeBegin = 0;
    f_08 = 1;
}

} // namespace fn_f2cad3c1

// 0x00170660 hulkfight::motion::MomentumXZAddTrack::vfunc_6 (4 B): matches/0x00170660.cpp
// sym: ?vfunc_6@MomentumXZAddTrack@motion@hulkfight@@UAEMXZ
hulk_freg hulkfight::motion::MomentumXZAddTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00170670 hulkfight::motion::MomentumXZAddTrack::vfunc_7 (7 B): matches/0x00170670.cpp
// sym: ?vfunc_7@MomentumXZAddTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::MomentumXZAddTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

