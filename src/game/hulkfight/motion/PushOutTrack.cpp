// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170710..0x001707c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PushOutTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8d58f20 {
#define TREE_TU_END }
namespace fn_f8d58f20 {} using namespace fn_f8d58f20;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8d58f20 {
extern int* hulk_at_004e1358;
class CCondition_170730 {
  public:
    virtual int vfunc_0(int);
};
class Track_170740 {
  public:
    Track_170740();
    virtual hulk_intptr Fnf_00170730(int);
    char pad[4];
};
class Part {
  public:
    Part();
    char pad[8];
};
class PushOutTrack : public Track_170740 {
  public:
    PushOutTrack();
    char pad0[4];
    int a;
    float b;
    char pad1[4];
    Part part;
    int c, d, e, f, g;
    float h, i, j;
    char flag;
};
struct Param_1707b0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1707b0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170710 FUN_00170710 (19 B): matches/0x00170710.cpp
// sym: ?FUN_00170710@fn_f8d58f20@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170710() {
    FUN_00234810(((char*)&DAT_004e1358), ((char*)&DAT_004e135c));
}

} // namespace fn_f8d58f20

// 0x00170730 hulkfight::motion::PushOutTrack::vfunc_0 (16 B): matches/0x00170730.cpp
// sym: ?vfunc_0@PushOutTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PushOutTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1358;
    return p[index];
}

namespace fn_f8d58f20 {

// 0x00170740 FUN_00170740 (86 B): matches/0x00170740.cpp
// sym: ??0PushOutTrack@fn_f8d58f20@@QAE@XZ
PushOutTrack::PushOutTrack() : Track_170740(), a(0), b(-1.0f), part(), c(0), d(0), e(0), f(0), g(0) {
    h = -1.0f;
    _ReadWriteBarrier();
    flag = 0;
    i = 1.0f;
    j = 10.0f;
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_f8d58f20

// 0x001707a0 hulkfight::motion::PushOutTrack::vfunc_6 (4 B): matches/0x001707a0.cpp
// sym: ?vfunc_6@PushOutTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PushOutTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001707b0 hulkfight::motion::PushOutTrack::vfunc_7 (7 B): matches/0x001707b0.cpp
// sym: ?vfunc_7@PushOutTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::PushOutTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

