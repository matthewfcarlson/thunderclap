// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180cf0..0x00180d80 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f39f3913 {
#define TREE_TU_END }
namespace fn_f39f3913 {} using namespace fn_f39f3913;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f39f3913 {
extern int* hulk_at_004e1480;
class CCondition_180d10 {
  public:
    virtual int vfunc_0(int);
};
class Track_180d20 {
  public:
    Track_180d20();
    virtual hulk_intptr Fnf_00180d10(int);
};
class PropDropTrack : public ::hulkfight::motion::PropDropTrack {
  public:
    PropDropTrack();
};


// 0x00180cf0 FUN_00180cf0 (19 B): matches/0x00180cf0.cpp
// sym: ?FUN_00180cf0@fn_f39f3913@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180cf0() {
    FUN_00234810(((char*)&DAT_004e1480), ((char*)&DAT_004e1484));
}

} // namespace fn_f39f3913

// 0x00180d10 hulkfight::motion::PropDropTrack::vfunc_0 (16 B): matches/0x00180d10.cpp
// sym: ?vfunc_0@PropDropTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropDropTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1480;
    return p[index];
}

namespace fn_f39f3913 {

// 0x00180d20 FUN_00180d20 (39 B): matches/0x00180d20.cpp
// sym: ??0PropDropTrack@fn_f39f3913@@QAE@XZ
PropDropTrack::PropDropTrack() {
    f_0c = 0;
    f_10 = -1;
    f_08 = 1;
}

} // namespace fn_f39f3913

// 0x00180d50 hulkfight::motion::PropDropTrack::vfunc_6 (4 B): matches/0x00180d50.cpp
// sym: ?vfunc_6@PropDropTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropDropTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00180d60 hulkfight::motion::PropDropTrack::vfunc_7 (7 B): matches/0x00180d60.cpp
// sym: ?vfunc_7@PropDropTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropDropTrack::vfunc_7() {
    return DAT_003f32e0;
}

