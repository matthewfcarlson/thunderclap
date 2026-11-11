// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170cb0..0x00170d40 (kind game, layer game, confidence high), dominant class hulkfight::motion::IntentionClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f138d560 {
#define TREE_TU_END }
namespace fn_f138d560 {} using namespace fn_f138d560;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f138d560 {
extern int* hulk_at_004e1398;
class CCondition_170cd0 {
  public:
    virtual int vfunc_0(int);
};
class Track_170ce0 {
  public:
    Track_170ce0();
    virtual hulk_intptr Fnf_00170cd0(int);
};
class IntentionClearTrack : public Track_170ce0 {
  public:
    IntentionClearTrack();
    char pad[4];
    volatile int a;
    int b;
    float c;
};
struct Param_170d20 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170d20 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170cb0 FUN_00170cb0 (19 B): matches/0x00170cb0.cpp
// sym: ?FUN_00170cb0@fn_f138d560@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170cb0() {
    FUN_00234810(((char*)&DAT_004e1398), ((char*)&DAT_004e139c));
}

} // namespace fn_f138d560

// 0x00170cd0 hulkfight::motion::IntentionClearTrack::vfunc_0 (16 B): matches/0x00170cd0.cpp
// sym: ?vfunc_0@IntentionClearTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::IntentionClearTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1398;
    return p[index];
}

namespace fn_f138d560 {

// 0x00170ce0 FUN_00170ce0 (39 B): matches/0x00170ce0.cpp
// sym: ??0IntentionClearTrack@fn_f138d560@@QAE@XZ
IntentionClearTrack::IntentionClearTrack() : Track_170ce0() {
    b = 0;
    c = -1.0f;
    a = 1;
}

} // namespace fn_f138d560

// 0x00170d10 hulkfight::motion::IntentionClearTrack::vfunc_6 (4 B): matches/0x00170d10.cpp
// sym: ?vfunc_6@IntentionClearTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::IntentionClearTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170d20 hulkfight::motion::IntentionClearTrack::vfunc_7 (7 B): matches/0x00170d20.cpp
// sym: ?vfunc_7@IntentionClearTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::IntentionClearTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

