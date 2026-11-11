// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180e20..0x00180ed0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrapplePropDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8ded1c2 {
#define TREE_TU_END }
namespace fn_f8ded1c2 {} using namespace fn_f8ded1c2;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8ded1c2 {
struct Tail_180e20 {
    void Init_0027af50();
};
struct PropAnimationTrack_180e20 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0041938c;
extern int* hulk_at_004e1490;
class CCondition_180e60 {
  public:
    virtual int vfunc_0(int);
};
class Track_180e70 {
  public:
    Track_180e70();
    virtual void f();
    char pad[4];
};
class GrapplePropDamageTrack : public Track_180e70 {
  public:
    GrapplePropDamageTrack();
    int flag, a, b, c, d;
    virtual void f();
};


// 0x00180e20 FUN_00180e20 (25 B): matches/0x00180e20.cpp
// sym: ?Run@PropAnimationTrack_180e20@fn_f8ded1c2@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void PropAnimationTrack_180e20::Run() {
    vptr = &hulk_at_0041938c;
    ((Tail_180e20*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x00180e40 FUN_00180e40 (19 B): matches/0x00180e40.cpp
// sym: ?FUN_00180e40@fn_f8ded1c2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180e40() {
    FUN_00234810(((char*)&DAT_004e1490), ((char*)&DAT_004e1494));
}

} // namespace fn_f8ded1c2

// 0x00180e60 hulkfight::motion::GrapplePropDamageTrack::vfunc_0 (16 B): matches/0x00180e60.cpp
// sym: ?vfunc_0@GrapplePropDamageTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrapplePropDamageTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1490;
    return p[index];
}

namespace fn_f8ded1c2 {

// 0x00180e70 FUN_00180e70 (39 B): matches/0x00180e70.cpp
// sym: ??0GrapplePropDamageTrack@fn_f8ded1c2@@QAE@XZ
GrapplePropDamageTrack::GrapplePropDamageTrack() : Track_180e70(), a(0), b(0), c(0), d(0) {
    flag = 1;
}

} // namespace fn_f8ded1c2

// 0x00180ea0 hulkfight::motion::GrapplePropDamageTrack::vfunc_6 (4 B): matches/0x00180ea0.cpp
// sym: ?vfunc_6@GrapplePropDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrapplePropDamageTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00180eb0 hulkfight::motion::GrapplePropDamageTrack::vfunc_7 (7 B): matches/0x00180eb0.cpp
// sym: ?vfunc_7@GrapplePropDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrapplePropDamageTrack::vfunc_7() {
    return DAT_003f32e0;
}

