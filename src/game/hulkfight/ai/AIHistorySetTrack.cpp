// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d400..0x0010d480 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistorySetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fd391c0c {
#define TREE_TU_END }
namespace fn_fd391c0c {} using namespace fn_fd391c0c;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fd391c0c {
extern int* gTable_10d420;
class CCondition_10d420 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d430 {
  public:
    Track_10d430();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub();
};
class AIHistorySetTrack : public Track_10d430 {
  public:
    AIHistorySetTrack();
    virtual void f();
    int a;
    float b;
    char c;
    char gap[3];
    Sub sub;
};
struct Param_10d470 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10d470 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0010d400 FUN_0010d400 (19 B): matches/0x0010d400.cpp
// sym: ?FUN_0010d400@fn_fd391c0c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d400() {
    FUN_00234810(((char*)&DAT_004e0b90), ((char*)&DAT_004e0b94));
}

} // namespace fn_fd391c0c

// 0x0010d420 hulkfight::ai::AIHistorySetTrack::vfunc_0 (16 B): matches/0x0010d420.cpp
// sym: ?vfunc_0@AIHistorySetTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::AIHistorySetTrack::vfunc_0(int index) {
    int* p = gTable_10d420;
    return p[index];
}

namespace fn_fd391c0c {

// 0x0010d430 FUN_0010d430 (48 B): matches/0x0010d430.cpp
// sym: ??0AIHistorySetTrack@fn_fd391c0c@@QAE@XZ
AIHistorySetTrack::AIHistorySetTrack() : Track_10d430(), a(0), b(-1.0f), c(0), sub() {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_fd391c0c

// 0x0010d460 hulkfight::ai::AIHistorySetTrack::vfunc_6 (4 B): matches/0x0010d460.cpp
// sym: ?vfunc_6@AIHistorySetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::AIHistorySetTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0010d470 hulkfight::ai::AIHistorySetTrack::vfunc_7 (7 B): matches/0x0010d470.cpp
// sym: ?vfunc_7@AIHistorySetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::AIHistorySetTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

