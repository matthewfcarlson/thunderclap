// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001813f0..0x00181480 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8c8812e {
#define TREE_TU_END }
namespace fn_f8c8812e {} using namespace fn_f8c8812e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8c8812e {
extern int* hulk_at_004e14c8;
class CCondition_181410 {
  public:
    virtual int vfunc_0(int);
};


// 0x001813f0 FUN_001813f0 (19 B): matches/0x001813f0.cpp
// sym: ?FUN_001813f0@fn_f8c8812e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001813f0() {
    FUN_00234810(((char*)&DAT_004e14c8), ((char*)&DAT_004e14cc));
}

} // namespace fn_f8c8812e

// 0x00181410 hulkfight::motion::PropAddToCollisionTrack::vfunc_0 (16 B): matches/0x00181410.cpp
// sym: ?vfunc_0@PropAddToCollisionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropAddToCollisionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14c8;
    return p[index];
}


// 0x00181420 FUN_00181420 (37 B): matches/0x00181420.cpp [wrapped: conflict: hulkfight::motion::PropAddToCollisionTrack]
// sym: ??0PropAddToCollisionTrack@motion@hulkfight@fn_00181420@@QAE@XZ
namespace fn_00181420 {
class Track_181420 {
  public:
    virtual void f();
    int x;
    Track_181420();
};
namespace hulkfight {
namespace motion {
class PropAddToCollisionTrack : public ::hulkfight::motion::PropAddToCollisionTrack {
  public:
    PropAddToCollisionTrack();
};
PropAddToCollisionTrack::PropAddToCollisionTrack() {
    f_0c = 0;
    f_10 = 0;
    f_14 = 1;
    f_08 = 1;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00181420


// 0x00181450 hulkfight::motion::PropAddToCollisionTrack::vfunc_6 (4 B): matches/0x00181450.cpp
// sym: ?vfunc_6@PropAddToCollisionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropAddToCollisionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00181460 hulkfight::motion::PropAddToCollisionTrack::vfunc_7 (7 B): matches/0x00181460.cpp
// sym: ?vfunc_7@PropAddToCollisionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropAddToCollisionTrack::vfunc_7() {
    return DAT_003f32e0;
}

