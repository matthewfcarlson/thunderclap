// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d350..0x0010d400 (kind game, layer game, confidence high), dominant class hulkfight::ai::ButtonTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f5040848 {
#define TREE_TU_END }
namespace fn_f5040848 {} using namespace fn_f5040848;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f5040848 {
struct Tail_10d350 {
    void Init_0027af50();
};
struct KeywordWaitTrack_10d350 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0040dc44;
extern int* hulk_at_004e0b88;
class CCondition_10d390 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d3a0 {
  public:
    Track_10d3a0();
    virtual void f();
    char pad[8];
};
class ButtonTrack : public Track_10d3a0 {
  public:
    ButtonTrack();
    virtual void f();
    int a;
    float v;
    int b;
    int c;
    int d;
    int e;
};
struct Param_10d3e0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10d3e0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0010d350 FUN_0010d350 (25 B): matches/0x0010d350.cpp
// sym: ?Run@KeywordWaitTrack_10d350@fn_f5040848@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void KeywordWaitTrack_10d350::Run() {
    vptr = &hulk_at_0040dc44;
    ((Tail_10d350*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0010d370 FUN_0010d370 (19 B): matches/0x0010d370.cpp
// sym: ?FUN_0010d370@fn_f5040848@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d370(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0b88), ((char*)&DAT_004e0b8c));
}

} // namespace fn_f5040848

// 0x0010d390 hulkfight::ai::ButtonTrack::vfunc_0 (16 B): matches/0x0010d390.cpp
// sym: ?vfunc_0@ButtonTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ButtonTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0b88;
    return p[index];
}

namespace fn_f5040848 {

// 0x0010d3a0 FUN_0010d3a0 (42 B): matches/0x0010d3a0.cpp
// sym: ??0ButtonTrack@fn_f5040848@@QAE@XZ
ButtonTrack::ButtonTrack() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    v = -1.0f;
}

} // namespace fn_f5040848

// 0x0010d3d0 hulkfight::ai::ButtonTrack::vfunc_6 (4 B): matches/0x0010d3d0.cpp
// sym: ?vfunc_6@ButtonTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::ButtonTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0010d3e0 hulkfight::ai::ButtonTrack::vfunc_7 (7 B): matches/0x0010d3e0.cpp
// sym: ?vfunc_7@ButtonTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::ButtonTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

