// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170ae0..0x00170b70 (kind game, layer game, confidence high), dominant class hulkfight::motion::CriticalMassDrainTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_faf05650 {
#define TREE_TU_END }
namespace fn_faf05650 {} using namespace fn_faf05650;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_faf05650 {
extern int* gTable_170b00;
class CCondition_170b00 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char hulk_at_00417c24[];
class Track_170b10 {
  public:
    Track_170b10();
    virtual void V0();
};
class CriticalMassDrainTrack_170b10 : public Track_170b10 {
  public:
    CriticalMassDrainTrack_170b10();
    virtual void V1();
    char pad[4];
    int mBase8;
    int mC;
    int m10;
};


// 0x00170ae0 FUN_00170ae0 (19 B): matches/0x00170ae0.cpp
// sym: ?FUN_00170ae0@fn_faf05650@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170ae0() {
    FUN_00234810(((char*)&DAT_004e1380), ((char*)&DAT_004e1384));
}

} // namespace fn_faf05650

// 0x00170b00 hulkfight::motion::CriticalMassDrainTrack::vfunc_0 (16 B): matches/0x00170b00.cpp
// sym: ?vfunc_0@CriticalMassDrainTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CriticalMassDrainTrack::vfunc_0(int index) {
    int* p = gTable_170b00;
    return p[index];
}

namespace fn_faf05650 {

// 0x00170b10 FUN_00170b10 (33 B): matches/0x00170b10.cpp
// sym: ??0CriticalMassDrainTrack_170b10@fn_faf05650@@QAE@XZ
CriticalMassDrainTrack_170b10::CriticalMassDrainTrack_170b10() : Track_170b10() {
    mC = 0;
    m10 = 0;
    *(hulk_intptr*)this = ((hulk_intptr)(hulk_at_00417c24 + 0x4));
    mBase8 = 1;
}

} // namespace fn_faf05650

// 0x00170b40 hulkfight::motion::CriticalMassDrainTrack::vfunc_6 (4 B): matches/0x00170b40.cpp
// sym: ?vfunc_6@CriticalMassDrainTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::CriticalMassDrainTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170b50 hulkfight::motion::CriticalMassDrainTrack::vfunc_7 (7 B): matches/0x00170b50.cpp
// sym: ?vfunc_7@CriticalMassDrainTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::CriticalMassDrainTrack::vfunc_7() {
    return DAT_003f32e0;
}

