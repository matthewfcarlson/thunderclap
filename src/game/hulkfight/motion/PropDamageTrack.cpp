// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181510..0x001815a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fd69616c {
#define TREE_TU_END }
namespace fn_fd69616c {} using namespace fn_fd69616c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd69616c {
extern int* gTable_181530;
class CCondition_181530 {
  public:
    virtual int vfunc_0(int);
};
class Base {
  public:
    virtual void f();
    char pad[8];
    Base();
};
class Track_181540 : public Base {
  public:
    int a, b, c;
    Track_181540() : a(0), b(0), c(0) {}
};
class PropDamageTrack : public Track_181540 {
  public:
    PropDamageTrack();
    virtual void f();
};


// 0x00181510 FUN_00181510 (19 B): matches/0x00181510.cpp
// sym: ?FUN_00181510@fn_fd69616c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00181510() {
    FUN_00234810(((char*)&DAT_004e14d8), ((char*)&DAT_004e14dc));
}

} // namespace fn_fd69616c

// 0x00181530 hulkfight::motion::PropDamageTrack::vfunc_0 (16 B): matches/0x00181530.cpp
// sym: ?vfunc_0@PropDamageTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropDamageTrack::vfunc_0(int index) {
    int* p = gTable_181530;
    return p[index];
}

namespace fn_fd69616c {

// 0x00181540 FUN_00181540 (36 B): matches/0x00181540.cpp
// sym: ??0PropDamageTrack@fn_fd69616c@@QAE@XZ
PropDamageTrack::PropDamageTrack() {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_fd69616c

// 0x00181570 hulkfight::motion::PropDamageTrack::vfunc_6 (4 B): matches/0x00181570.cpp
// sym: ?vfunc_6@PropDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropDamageTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00181580 hulkfight::motion::PropDamageTrack::vfunc_7 (7 B): matches/0x00181580.cpp
// sym: ?vfunc_7@PropDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropDamageTrack::vfunc_7() {
    return DAT_003f32e0;
}

