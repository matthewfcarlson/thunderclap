// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014db60..0x0014dbd0 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptAccumulatorSetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f0ef64f3 {
#define TREE_TU_END }
namespace fn_f0ef64f3 {} using namespace fn_f0ef64f3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0ef64f3 {
extern int* gTable_14db60;
class CCondition_14db60 {
  public:
    virtual int vfunc_0(int);
};
class Track_14db70 {
  public:
    Track_14db70();
    virtual void f();
    int x;
};
class InterruptAccumulatorSetTrack : public Track_14db70 {
  public:
    InterruptAccumulatorSetTrack();
    virtual void f();
    int a;
    int b;
    int c;
};

} // namespace fn_f0ef64f3

// 0x0014db60 hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_0 (16 B): matches/0x0014db60.cpp
// sym: ?vfunc_0@InterruptAccumulatorSetTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_0(int index) {
    int* p = gTable_14db60;
    return p[index];
}

namespace fn_f0ef64f3 {

// 0x0014db70 FUN_0014db70 (33 B): matches/0x0014db70.cpp
// sym: ??0InterruptAccumulatorSetTrack@fn_f0ef64f3@@QAE@XZ
InterruptAccumulatorSetTrack::InterruptAccumulatorSetTrack() {
    b = 0;
    c = 0;
    a = 1;
}

} // namespace fn_f0ef64f3

// 0x0014dba0 hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_6 (4 B): matches/0x0014dba0.cpp
// sym: ?vfunc_6@InterruptAccumulatorSetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014dbb0 hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_7 (7 B): matches/0x0014dbb0.cpp
// sym: ?vfunc_7@InterruptAccumulatorSetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_7() {
    return DAT_003f32e0;
}

