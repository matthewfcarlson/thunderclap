// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016fee0..0x0016ff70 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ffbea55e {
#define TREE_TU_END }
namespace fn_ffbea55e {} using namespace fn_ffbea55e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ffbea55e {
struct Tail_16fee0 {
    void Init();
};
struct RestPoseTrack_16fee0 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_16fee0;
extern int* gTable_16ff20;
class CCondition_16ff20 {
  public:
    virtual int vfunc_0(int);
};
class Track_16ff30 {
  public:
    Track_16ff30();
    void* vptr;
};
class SnapToGroundTrack : public Track_16ff30 {
  public:
    SnapToGroundTrack();
    char pad[4];
    int m8;
    int mC;
};


// 0x0016fee0 FUN_0016fee0 (25 B): matches/0x0016fee0.cpp
// sym: ?Run@RestPoseTrack_16fee0@fn_ffbea55e@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void RestPoseTrack_16fee0::Run() {
    vptr = &vftable_16fee0;
    ((Tail_16fee0*)((char*)this + 0x18))->Init();
    Finish();
}


// 0x0016ff00 FUN_0016ff00 (19 B): matches/0x0016ff00.cpp
// sym: ?FUN_0016ff00@fn_ffbea55e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0016ff00() {
    FUN_00234810(((char*)&DAT_004e1300), ((char*)&DAT_004e1304));
}

} // namespace fn_ffbea55e

// 0x0016ff20 hulkfight::motion::SnapToGroundTrack::vfunc_0 (16 B): matches/0x0016ff20.cpp
// sym: ?vfunc_0@SnapToGroundTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SnapToGroundTrack::vfunc_0(int index) {
    int* p = gTable_16ff20;
    return p[index];
}

namespace fn_ffbea55e {

// 0x0016ff30 FUN_0016ff30 (32 B): matches/0x0016ff30.cpp
// sym: ??0SnapToGroundTrack@fn_ffbea55e@@QAE@XZ
SnapToGroundTrack::SnapToGroundTrack() : Track_16ff30() {
    *(void* volatile*)&vptr = (void*)((char*)g_vftable);
    mC = 0;
    m8 = 1;
}

} // namespace fn_ffbea55e

// 0x0016ff50 hulkfight::motion::SnapToGroundTrack::vfunc_6 (4 B): matches/0x0016ff50.cpp
// sym: ?vfunc_6@SnapToGroundTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SnapToGroundTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0016ff60 hulkfight::motion::SnapToGroundTrack::vfunc_7 (7 B): matches/0x0016ff60.cpp
// sym: ?vfunc_7@SnapToGroundTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::SnapToGroundTrack::vfunc_7() {
    return DAT_003f32e0;
}

