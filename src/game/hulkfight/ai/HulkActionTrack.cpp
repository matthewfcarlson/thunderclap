// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d230..0x0010d2a0 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f9ffd634 {
#define TREE_TU_END }
namespace fn_f9ffd634 {} using namespace fn_f9ffd634;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f9ffd634 {
extern int* hulk_at_004e0b78;
class CCondition_10d230 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d240 {
  public:
    Track_10d240();
    virtual void f();
    char pad[4];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class HulkActionTrack : public Track_10d240 {
  public:
    HulkActionTrack();
    int flag;
    int a;
    float b;
    char p2[4];
    char sub[8];
    int c;
    virtual void g();
};
struct Param_10d290 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10d290 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

} // namespace fn_f9ffd634

// 0x0010d230 hulkfight::ai::HulkActionTrack::vfunc_0 (16 B): matches/0x0010d230.cpp
// sym: ?vfunc_0@HulkActionTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HulkActionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0b78;
    return p[index];
}

namespace fn_f9ffd634 {

// 0x0010d240 FUN_0010d240 (54 B): matches/0x0010d240.cpp
// sym: ??0HulkActionTrack@fn_f9ffd634@@QAE@XZ
HulkActionTrack::HulkActionTrack() : Track_10d240() {
    a = 0;
    b = -1.0f;
    ((Sub*)sub)->Sub::Sub();
    c = 0;
    flag = 1;
}

} // namespace fn_f9ffd634

// 0x0010d280 hulkfight::ai::HulkActionTrack::vfunc_6 (4 B): matches/0x0010d280.cpp
// sym: ?vfunc_6@HulkActionTrack@ai@hulkfight@@UAEMXZ
 // namespace hulkfight
hulk_freg hulkfight::ai::HulkActionTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0010d290 hulkfight::ai::HulkActionTrack::vfunc_7 (7 B): matches/0x0010d290.cpp
// sym: ?vfunc_7@HulkActionTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::HulkActionTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

