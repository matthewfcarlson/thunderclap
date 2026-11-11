// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181480..0x00181510 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToMissileCountTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f79bd28d {
#define TREE_TU_END }
namespace fn_f79bd28d {} using namespace fn_f79bd28d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f79bd28d {
extern int* hulk_at_004e14d0;
class CCondition_1814a0 {
  public:
    virtual int vfunc_0(int);
};
class Track {
  public:
    Track();
    virtual void Fn();
    int pad;
};
class PropAddToMissileCountTrack : public Track {
  public:
    PropAddToMissileCountTrack();
    virtual void Fn();
    int count;
    int a;
    int b;
    int c;
};


// 0x00181480 FUN_00181480 (19 B): matches/0x00181480.cpp
// sym: ?FUN_00181480@fn_f79bd28d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00181480() {
    FUN_00234810(((char*)&DAT_004e14d0), ((char*)&DAT_004e14d4));
}

} // namespace fn_f79bd28d

// 0x001814a0 hulkfight::motion::PropAddToMissileCountTrack::vfunc_0 (16 B): matches/0x001814a0.cpp
// sym: ?vfunc_0@PropAddToMissileCountTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropAddToMissileCountTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14d0;
    return p[index];
}

namespace fn_f79bd28d {

// 0x001814b0 FUN_001814b0 (36 B): matches/0x001814b0.cpp
// sym: ??0PropAddToMissileCountTrack@fn_f79bd28d@@QAE@XZ
PropAddToMissileCountTrack::PropAddToMissileCountTrack() {
    a = 0;
    b = 0;
    c = 0;
    count = 1;
}

} // namespace fn_f79bd28d

// 0x001814e0 hulkfight::motion::PropAddToMissileCountTrack::vfunc_6 (4 B): matches/0x001814e0.cpp
// sym: ?vfunc_6@PropAddToMissileCountTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropAddToMissileCountTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x001814f0 hulkfight::motion::PropAddToMissileCountTrack::vfunc_7 (7 B): matches/0x001814f0.cpp
// sym: ?vfunc_7@PropAddToMissileCountTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropAddToMissileCountTrack::vfunc_7() {
    return DAT_003f32e0;
}

