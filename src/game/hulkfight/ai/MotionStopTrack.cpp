// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115910..0x00115990 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionStopTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f2c145d4 {
#define TREE_TU_END }
namespace fn_f2c145d4 {} using namespace fn_f2c145d4;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f2c145d4 {
extern int* hulk_at_004e0c4c;
class CCondition_115930 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0040eb50[];
class Track_115940 {
  public:
    Track_115940();
    virtual ~Track_115940();
    char pad0[8];
};
class MotionStopTrack : public Track_115940 {
  public:
    MotionStopTrack();
    virtual ~MotionStopTrack();
    int m0c;
    float m10;
};
struct Param_115970 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115970 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115910 FUN_00115910 (19 B): matches/0x00115910.cpp
// sym: ?FUN_00115910@fn_f2c145d4@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115910() {
    FUN_00234810(((char*)&DAT_004e0c4c), ((char*)&DAT_004e0c50));
}

} // namespace fn_f2c145d4

// 0x00115930 hulkfight::ai::MotionStopTrack::vfunc_0 (16 B): matches/0x00115930.cpp
// sym: ?vfunc_0@MotionStopTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionStopTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0c4c;
    return p[index];
}

namespace fn_f2c145d4 {

// 0x00115940 FUN_00115940 (32 B): matches/0x00115940.cpp
// sym: ??0MotionStopTrack@fn_f2c145d4@@QAE@XZ
MotionStopTrack::MotionStopTrack() : Track_115940() {
    *(void**)((char*)this + 0) = hulk_at_0040eb50;
    m0c = 0;
    m10 = -1.0f;
}

} // namespace fn_f2c145d4

// 0x00115960 hulkfight::ai::MotionStopTrack::vfunc_6 (4 B): matches/0x00115960.cpp
// sym: ?vfunc_6@MotionStopTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionStopTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115970 hulkfight::ai::MotionStopTrack::vfunc_7 (7 B): matches/0x00115970.cpp
// sym: ?vfunc_7@MotionStopTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionStopTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

