// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180b60..0x00180bd0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorToPropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fd743b52 {
#define TREE_TU_END }
namespace fn_fd743b52 {} using namespace fn_fd743b52;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd743b52 {
extern int* gTable_180b60;
class CCondition_180b60 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_fd743b52

// 0x00180b60 hulkfight::motion::PropActorToPropTrack::vfunc_0 (16 B): matches/0x00180b60.cpp
// sym: ?vfunc_0@PropActorToPropTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropActorToPropTrack::vfunc_0(int index) {
    int* p = gTable_180b60;
    return p[index];
}


// 0x00180b70 FUN_00180b70 (36 B): matches/0x00180b70.cpp [wrapped: conflict: hulkfight::motion::PropActorToPropTrack]
// sym: ??0PropActorToPropTrack@motion@hulkfight@fn_00180b70@@QAE@XZ
namespace fn_00180b70 {
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack();
    virtual void f();
    char pad[8];
};
class PropActorToPropTrack : public BaseTrack {
  public:
    PropActorToPropTrack();
    virtual void f();
    int value;
    int state;
    char flag1;
    char flag2;
};
PropActorToPropTrack::PropActorToPropTrack() : value(0), state(-1), flag1(0), flag2(0) {}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00180b70


// 0x00180ba0 hulkfight::motion::PropActorToPropTrack::vfunc_6 (4 B): matches/0x00180ba0.cpp
// sym: ?vfunc_6@PropActorToPropTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropActorToPropTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00180bb0 hulkfight::motion::PropActorToPropTrack::vfunc_7 (7 B): matches/0x00180bb0.cpp
// sym: ?vfunc_7@PropActorToPropTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropActorToPropTrack::vfunc_7() {
    return DAT_003f32e0;
}

