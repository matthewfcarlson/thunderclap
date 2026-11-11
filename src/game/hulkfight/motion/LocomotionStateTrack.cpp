// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170240..0x001702d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotionStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8b7fc8f {
#define TREE_TU_END }
namespace fn_f8b7fc8f {} using namespace fn_f8b7fc8f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8b7fc8f {
extern int* gTable_170260;
class CCondition_170260 {
  public:
    virtual int vfunc_0(int);
};
extern char VT_004179e8[];
class Track_170270 {
  public:
    Track_170270();
    virtual void f();
    char pad[4];
};
class LocomotionStateTrack : public Track_170270 {
  public:
    LocomotionStateTrack();
    virtual void f();
    int m8;
    int mc;
    int m10;
};


// 0x00170240 FUN_00170240 (19 B): matches/0x00170240.cpp
// sym: ?FUN_00170240@fn_f8b7fc8f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170240() {
    FUN_00234810(((char*)&DAT_004e1320), ((char*)&DAT_004e1324));
}

} // namespace fn_f8b7fc8f

// 0x00170260 hulkfight::motion::LocomotionStateTrack::vfunc_0 (16 B): matches/0x00170260.cpp
// sym: ?vfunc_0@LocomotionStateTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionStateTrack::vfunc_0(int index) {
    int* p = gTable_170260;
    return p[index];
}

namespace fn_f8b7fc8f {

// 0x00170270 FUN_00170270 (33 B): matches/0x00170270.cpp
// sym: ??0LocomotionStateTrack@fn_f8b7fc8f@@QAE@XZ
LocomotionStateTrack::LocomotionStateTrack() {
    mc = 0;
    m10 = 0;
    *(void**)this = (void*)((hulk_intptr)VT_004179e8);
    m8 = 1;
}

} // namespace fn_f8b7fc8f

// 0x001702a0 hulkfight::motion::LocomotionStateTrack::vfunc_6 (4 B): matches/0x001702a0.cpp
// sym: ?vfunc_6@LocomotionStateTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::LocomotionStateTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001702b0 hulkfight::motion::LocomotionStateTrack::vfunc_7 (7 B): matches/0x001702b0.cpp
// sym: ?vfunc_7@LocomotionStateTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::LocomotionStateTrack::vfunc_7() {
    return DAT_003f32e0;
}

