// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016fd90..0x0016fe50 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f70986fd {
#define TREE_TU_END }
namespace fn_f70986fd {} using namespace fn_f70986fd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f70986fd {
struct Tail_16fd90 {
    void Init_0027af50();
};
struct JointTrackerTrack_16fd90 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_00417898;
extern int* hulk_at_004e12f0;
class CCondition_16fdd0 {
  public:
    virtual int vfunc_0(int);
};
class Track_16fde0 {
  public:
    Track_16fde0();
    virtual void f();
    int m;
};
class ChargeTrack : public ::hulkfight::motion::ChargeTrack {
  public:
    ChargeTrack();
};
struct Param_16fe30 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_16fe30 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0016fd90 FUN_0016fd90 (25 B): matches/0x0016fd90.cpp
// sym: ?Run@JointTrackerTrack_16fd90@fn_f70986fd@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void JointTrackerTrack_16fd90::Run() {
    vptr = &hulk_at_00417898;
    ((Tail_16fd90*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0016fdb0 FUN_0016fdb0 (19 B): matches/0x0016fdb0.cpp
// sym: ?FUN_0016fdb0@fn_f70986fd@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0016fdb0() {
    FUN_00234810(((char*)&DAT_004e12f0), ((char*)&DAT_004e12f4));
}

} // namespace fn_f70986fd

// 0x0016fdd0 hulkfight::motion::ChargeTrack::vfunc_0 (16 B): matches/0x0016fdd0.cpp
// sym: ?vfunc_0@ChargeTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ChargeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e12f0;
    return p[index];
}

namespace fn_f70986fd {

// 0x0016fde0 FUN_0016fde0 (50 B): matches/0x0016fde0.cpp
// sym: ??0ChargeTrack@fn_f70986fd@@QAE@XZ
ChargeTrack::ChargeTrack() {
    f_0c = 0;
    f_14 = 0;
    f_18 = 0;
    f_10 = -1.0f;
    f_1c = 1.0f;
    f_08 = 1;
}

} // namespace fn_f70986fd

// 0x0016fe20 hulkfight::motion::ChargeTrack::vfunc_6 (4 B): matches/0x0016fe20.cpp
// sym: ?vfunc_6@ChargeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::ChargeTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0016fe30 hulkfight::motion::ChargeTrack::vfunc_7 (7 B): matches/0x0016fe30.cpp
// sym: ?vfunc_7@ChargeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::ChargeTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

