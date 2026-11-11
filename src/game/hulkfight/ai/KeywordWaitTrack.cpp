// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d2a0..0x0010d350 (kind game, layer game, confidence high), dominant class hulkfight::ai::KeywordWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f14b3cf2 {
#define TREE_TU_END }
namespace fn_f14b3cf2 {} using namespace fn_f14b3cf2;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f14b3cf2 {
struct Tail_10d2a0 {
    void Init_0027af50();
};
struct HulkActionTrack_10d2a0 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0040dc14;
extern int* hulk_at_004e0b80;
class CCondition_10d2e0 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d2f0 {
  public:
    Track_10d2f0();
    virtual void Fn();
    char pad[4];
    int c;
};
class Part {
  public:
    Part();
    char pad[4];
};
class KeywordWaitTrack : public Track_10d2f0 {
  public:
    KeywordWaitTrack();
    virtual void Fn();
    int a;
    float b;
    char gap[4];
    Part part;
    char pad2[4];
    char flag;
};
struct Param_10d340 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10d340 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0010d2a0 FUN_0010d2a0 (25 B): matches/0x0010d2a0.cpp
// sym: ?Run@HulkActionTrack_10d2a0@fn_f14b3cf2@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void HulkActionTrack_10d2a0::Run() {
    vptr = &hulk_at_0040dc14;
    ((Tail_10d2a0*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0010d2c0 FUN_0010d2c0 (19 B): matches/0x0010d2c0.cpp
// sym: ?FUN_0010d2c0@fn_f14b3cf2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d2c0() {
    FUN_00234810(((char*)&DAT_004e0b80), ((char*)&DAT_004e0b84));
}

} // namespace fn_f14b3cf2

// 0x0010d2e0 hulkfight::ai::KeywordWaitTrack::vfunc_0 (16 B): matches/0x0010d2e0.cpp
// sym: ?vfunc_0@KeywordWaitTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::KeywordWaitTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0b80;
    return p[index];
}

namespace fn_f14b3cf2 {

// 0x0010d2f0 FUN_0010d2f0 (51 B): matches/0x0010d2f0.cpp
// sym: ??0KeywordWaitTrack@fn_f14b3cf2@@QAE@XZ
KeywordWaitTrack::KeywordWaitTrack() : Track_10d2f0(), a(0), b(-1.0f), part() {
    flag = 0;
    c = 1;
}

} // namespace fn_f14b3cf2

// 0x0010d330 hulkfight::ai::KeywordWaitTrack::vfunc_6 (4 B): matches/0x0010d330.cpp
// sym: ?vfunc_6@KeywordWaitTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::KeywordWaitTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0010d340 hulkfight::ai::KeywordWaitTrack::vfunc_7 (7 B): matches/0x0010d340.cpp
// sym: ?vfunc_7@KeywordWaitTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::KeywordWaitTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

