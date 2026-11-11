// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014de80..0x0014df20 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f7901a76 {
#define TREE_TU_END }
namespace fn_f7901a76 {} using namespace fn_f7901a76;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7901a76 {
struct Tail_14de80 {
    void Init_0027af50();
};
struct HitReactionTrack_14de80 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_004142d0;
extern int* hulk_at_004e10f8;
class CCondition_14dec0 {
  public:
    virtual int vfunc_0(int);
};
struct Track_14ded0 {
    Track_14ded0();
    virtual void vfn();
};
class HitWaitTrack_14ded0 : public Track_14ded0 {
  public:
    char pad[8];
    int m0c;
    int m10;
    HitWaitTrack_14ded0();
};
extern int hulk_at_00414300[];
extern float hulk_at_003f3388;


// 0x0014de80 FUN_0014de80 (25 B): matches/0x0014de80.cpp
// sym: ?Run@HitReactionTrack_14de80@fn_f7901a76@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void HitReactionTrack_14de80::Run() {
    vptr = &hulk_at_004142d0;
    ((Tail_14de80*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0014dea0 FUN_0014dea0 (19 B): matches/0x0014dea0.cpp
// sym: ?FUN_0014dea0@fn_f7901a76@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014dea0() {
    FUN_00234810(((char*)&DAT_004e10f8), ((char*)&DAT_004e10fc));
}

} // namespace fn_f7901a76

// 0x0014dec0 hulkfight::motion::HitWaitTrack::vfunc_0 (16 B): matches/0x0014dec0.cpp
// sym: ?vfunc_0@HitWaitTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitWaitTrack::vfunc_0(int index) {
    int* p = hulk_at_004e10f8;
    return p[index];
}

namespace fn_f7901a76 {

// 0x0014ded0 FUN_0014ded0 (26 B): matches/0x0014ded0.cpp
// sym: ??0HitWaitTrack_14ded0@fn_f7901a76@@QAE@XZ
HitWaitTrack_14ded0::HitWaitTrack_14ded0() {
    m0c = 0;
    m10 = 0;
    *(hulk_intptr*)this = (hulk_intptr)hulk_at_00414300;
}

} // namespace fn_f7901a76

// 0x0014def0 hulkfight::motion::HitWaitTrack::vfunc_6 (4 B): matches/0x0014def0.cpp
// sym: ?vfunc_6@HitWaitTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitWaitTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014df00 hulkfight::motion::HitWaitTrack::vfunc_7 (7 B): matches/0x0014df00.cpp
// sym: ?vfunc_7@HitWaitTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitWaitTrack::vfunc_7() {
    return hulk_at_003f3388;
}

