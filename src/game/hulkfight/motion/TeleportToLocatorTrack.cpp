// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170d40..0x00170dc0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportToLocatorTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f44fe395 {
#define TREE_TU_END }
namespace fn_f44fe395 {} using namespace fn_f44fe395;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f44fe395 {
extern int* gTable_170d60;
class CCondition_170d60 {
  public:
    virtual int vfunc_0(int);
};
class Base {
  public:
    virtual void f();
    Base();
    char pad[8];
};
struct Pair {
    int a, b;
    Pair() : a(0), b(0) {}
};
class Track_170d70 : public Base {
  public:
    Pair pair;
    Track_170d70() : pair() {}
};
struct Tail {
    int a, b;
    float t;
    Tail() : a(0), b(0), t(-1.0f) {}
};
class TeleportToLocatorTrack_170d70 : public Track_170d70 {
  public:
    virtual void f();
    TeleportToLocatorTrack_170d70();
    Tail tail;
};


// 0x00170d40 FUN_00170d40 (19 B): matches/0x00170d40.cpp
// sym: ?FUN_00170d40@fn_f44fe395@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170d40() {
    FUN_00234810(((char*)&DAT_004e13a0), ((char*)&DAT_004e13a4));
}

} // namespace fn_f44fe395

// 0x00170d60 hulkfight::motion::TeleportToLocatorTrack::vfunc_0 (16 B): matches/0x00170d60.cpp
// sym: ?vfunc_0@TeleportToLocatorTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TeleportToLocatorTrack::vfunc_0(int index) {
    int* p = gTable_170d60;
    return p[index];
}

namespace fn_f44fe395 {

// 0x00170d70 FUN_00170d70 (46 B): matches/0x00170d70.cpp
// sym: ??0TeleportToLocatorTrack_170d70@fn_f44fe395@@QAE@XZ
TeleportToLocatorTrack_170d70::TeleportToLocatorTrack_170d70() {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_f44fe395

// 0x00170da0 hulkfight::motion::TeleportToLocatorTrack::vfunc_6 (4 B): matches/0x00170da0.cpp
// sym: ?vfunc_6@TeleportToLocatorTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TeleportToLocatorTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170db0 hulkfight::motion::TeleportToLocatorTrack::vfunc_7 (7 B): matches/0x00170db0.cpp
// sym: ?vfunc_7@TeleportToLocatorTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::TeleportToLocatorTrack::vfunc_7() {
    return DAT_003f32e0;
}

