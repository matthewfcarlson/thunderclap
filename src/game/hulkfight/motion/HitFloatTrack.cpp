// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e040..0x0014e0e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitFloatTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f48e9e83 {
#define TREE_TU_END }
namespace fn_f48e9e83 {} using namespace fn_f48e9e83;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f48e9e83 {
extern int* hulk_at_004e1110;
class CCondition_14e060 {
  public:
    virtual int vfunc_0(int);
};
class Track_14e070 {
  public:
    Track_14e070();
    virtual hulk_intptr Fnf_0014e060(int);
    char pad[8];
};
class HitFloatTrack : public Track_14e070 {
  public:
    HitFloatTrack();
    int a;
    float d;
    char b;
    char gap2[3];
    int c;
    int e;
    int f;
    int g;
};
struct Param_14e0c0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14e0c0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014e040 FUN_0014e040 (19 B): matches/0x0014e040.cpp
// sym: ?FUN_0014e040@fn_f48e9e83@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e040() {
    FUN_00234810(((char*)&DAT_004e1110), ((char*)&DAT_004e1114));
}

} // namespace fn_f48e9e83

// 0x0014e060 hulkfight::motion::HitFloatTrack::vfunc_0 (16 B): matches/0x0014e060.cpp
// sym: ?vfunc_0@HitFloatTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitFloatTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1110;
    return p[index];
}

namespace fn_f48e9e83 {

// 0x0014e070 FUN_0014e070 (49 B): matches/0x0014e070.cpp
// sym: ??0HitFloatTrack@fn_f48e9e83@@QAE@XZ
HitFloatTrack::HitFloatTrack() : Track_14e070() {
    a = 0;
    b = 0;
    c = 0;
    f = 0;
    g = 0;
    d = -1.0f;
    e = -5;
}

} // namespace fn_f48e9e83

// 0x0014e0b0 hulkfight::motion::HitFloatTrack::vfunc_6 (4 B): matches/0x0014e0b0.cpp
// sym: ?vfunc_6@HitFloatTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitFloatTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e0c0 hulkfight::motion::HitFloatTrack::vfunc_7 (7 B): matches/0x0014e0c0.cpp
// sym: ?vfunc_7@HitFloatTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitFloatTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

