// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d480..0x0010d5b0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8109a4a {
#define TREE_TU_END }
namespace fn_f8109a4a {} using namespace fn_f8109a4a;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f8109a4a {
struct Tail_10d480 {
    void Init_0027af50();
};
struct AIHistorySetTrack_10d480 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0040dca4;
extern int* hulk_at_004e0b98;
class CCondition_10d4c0 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d4d0 {
  public:
    Track_10d4d0();
    virtual void f();
    char pad[4];
};
class TokenTrack : public Track_10d4d0 {
  public:
    TokenTrack();
    virtual void f();
    int a;
    int b;
    float c;
    char d;
};
extern int* hulk_at_004e0ba0;
class CCondition_10d540 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d550 {
  public:
    Track_10d550();
    virtual void f();
};
class Part {
  public:
    Part();
    char pad[8];
};
class SemaphoreWaitTrack : public Track_10d550 {
    char gap[8];
    int a;
    float b;
    char gap2[4];
    Part part;
    char x, y;
    char gap3[2];
    int z;

  public:
    SemaphoreWaitTrack();
    virtual void f();
};
struct Param_10d5a0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10d5a0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0010d480 FUN_0010d480 (25 B): matches/0x0010d480.cpp
// sym: ?Run@AIHistorySetTrack_10d480@fn_f8109a4a@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void AIHistorySetTrack_10d480::Run() {
    vptr = &hulk_at_0040dca4;
    ((Tail_10d480*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0010d4a0 FUN_0010d4a0 (19 B): matches/0x0010d4a0.cpp
// sym: ?FUN_0010d4a0@fn_f8109a4a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d4a0() {
    FUN_00234810(((char*)&DAT_004e0b98), ((char*)&DAT_004e0b9c));
}

} // namespace fn_f8109a4a

// 0x0010d4c0 hulkfight::ai::TokenTrack::vfunc_0 (16 B): matches/0x0010d4c0.cpp
// sym: ?vfunc_0@TokenTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TokenTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0b98;
    return p[index];
}

namespace fn_f8109a4a {

// 0x0010d4d0 FUN_0010d4d0 (40 B): matches/0x0010d4d0.cpp
// sym: ??0TokenTrack@fn_f8109a4a@@QAE@XZ
TokenTrack::TokenTrack() : b(0), d(0) {
    c = -1.0f;
    a = 1;
}

} // namespace fn_f8109a4a

// 0x0010d500 hulkfight::ai::TokenTrack::vfunc_6 (4 B): matches/0x0010d500.cpp
// sym: ?vfunc_6@TokenTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::TokenTrack::vfunc_6() {
    return this->timeBegin;
}

namespace fn_f8109a4a {

// 0x0010d520 FUN_0010d520 (19 B): matches/0x0010d520.cpp
// sym: ?FUN_0010d520@fn_f8109a4a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d520() {
    FUN_00234810(((char*)&DAT_004e0ba0), ((char*)&DAT_004e0ba4));
}

} // namespace fn_f8109a4a

// 0x0010d540 hulkfight::ai::SemaphoreWaitTrack::vfunc_0 (16 B): matches/0x0010d540.cpp
// sym: ?vfunc_0@SemaphoreWaitTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::SemaphoreWaitTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ba0;
    return p[index];
}

namespace fn_f8109a4a {

// 0x0010d550 FUN_0010d550 (55 B): matches/0x0010d550.cpp
// sym: ??0SemaphoreWaitTrack@fn_f8109a4a@@QAE@XZ
SemaphoreWaitTrack::SemaphoreWaitTrack() : Track_10d550(), a(0), b(-1.0f), part(), x(1), y(1), z(0) {}

} // namespace fn_f8109a4a

// 0x0010d590 hulkfight::ai::SemaphoreWaitTrack::vfunc_6 (4 B): matches/0x0010d590.cpp
// sym: ?vfunc_6@SemaphoreWaitTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::SemaphoreWaitTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0010d5a0 hulkfight::ai::SemaphoreWaitTrack::vfunc_7 (7 B): matches/0x0010d5a0.cpp
// sym: ?vfunc_7@SemaphoreWaitTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::SemaphoreWaitTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

