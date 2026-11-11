// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180c50..0x00180cf0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorThinkingTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f952d83d {
#define TREE_TU_END }
namespace fn_f952d83d {} using namespace fn_f952d83d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f952d83d {
struct Tail_180c50 {
    void Init_0027af50();
};
struct PropSetStateByNameTrack_180c50 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_004192fc;
extern int* hulk_at_004e1478;
class CCondition_180c90 {
  public:
    virtual int vfunc_0(int);
};
void* __cdecl FUN_00236d40();
class Track_180ca0 {
  public:
    void* vptr;
    Track_180ca0();
};
class PropActorThinkingTrack : public Track_180ca0 {
  public:
    char pad[8];
    int mC;
    char m10;
    PropActorThinkingTrack();
};


// 0x00180c50 FUN_00180c50 (25 B): matches/0x00180c50.cpp
// sym: ?Run@PropSetStateByNameTrack_180c50@fn_f952d83d@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void PropSetStateByNameTrack_180c50::Run() {
    vptr = &hulk_at_004192fc;
    ((Tail_180c50*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x00180c70 FUN_00180c70 (19 B): matches/0x00180c70.cpp
// sym: ?FUN_00180c70@fn_f952d83d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180c70() {
    FUN_00234810(((char*)&DAT_004e1478), ((char*)&DAT_004e147c));
}

} // namespace fn_f952d83d

// 0x00180c90 hulkfight::motion::PropActorThinkingTrack::vfunc_0 (16 B): matches/0x00180c90.cpp
// sym: ?vfunc_0@PropActorThinkingTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropActorThinkingTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1478;
    return p[index];
}

namespace fn_f952d83d {

// 0x00180ca0 FUN_00180ca0 (26 B): matches/0x00180ca0.cpp
// sym: ??0PropActorThinkingTrack@fn_f952d83d@@QAE@XZ
PropActorThinkingTrack::PropActorThinkingTrack() : Track_180ca0() {
    mC = 0;
    m10 = 0;
    vptr = g_vftable;
}

} // namespace fn_f952d83d

// 0x00180cc0 hulkfight::motion::PropActorThinkingTrack::vfunc_6 (4 B): matches/0x00180cc0.cpp
// sym: ?vfunc_6@PropActorThinkingTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropActorThinkingTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00180cd0 hulkfight::motion::PropActorThinkingTrack::vfunc_7 (7 B): matches/0x00180cd0.cpp
// sym: ?vfunc_7@PropActorThinkingTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropActorThinkingTrack::vfunc_7() {
    return DAT_003f32e0;
}

