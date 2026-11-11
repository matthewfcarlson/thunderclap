// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001707c0..0x00170870 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f79dcf9e {
#define TREE_TU_END }
namespace fn_f79dcf9e {} using namespace fn_f79dcf9e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f79dcf9e {
struct Tail_1707c0 {
    void Init();
};
struct PushOutTrack_1707c0 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_1707c0;
extern int* gTable_170800;
class CCondition_170800 {
  public:
    virtual int vfunc_0(int);
};
class Track_170810 {
  public:
    Track_170810();
    virtual void v0();
    char pad[8];
};
struct Pair {
    int b, c;
    void reset() {
        b = 0;
        c = 0;
    }
};
class TeleportTrack : public Track_170810 {
  public:
    TeleportTrack();
    virtual void v0();
    int a;
    Pair pair;
    float d;
};


// 0x001707c0 FUN_001707c0 (25 B): matches/0x001707c0.cpp
// sym: ?Run@PushOutTrack_1707c0@fn_f79dcf9e@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void PushOutTrack_1707c0::Run() {
    vptr = &vftable_1707c0;
    ((Tail_1707c0*)((char*)this + 0x18))->Init();
    Finish();
}


// 0x001707e0 FUN_001707e0 (19 B): matches/0x001707e0.cpp
// sym: ?FUN_001707e0@fn_f79dcf9e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001707e0() {
    FUN_00234810(((char*)&DAT_004e1360), ((char*)&DAT_004e1364));
}

} // namespace fn_f79dcf9e

// 0x00170800 hulkfight::motion::TeleportTrack::vfunc_0 (16 B): matches/0x00170800.cpp
// sym: ?vfunc_0@TeleportTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TeleportTrack::vfunc_0(int index) {
    int* p = gTable_170800;
    return p[index];
}

namespace fn_f79dcf9e {

// 0x00170810 FUN_00170810 (43 B): matches/0x00170810.cpp
// sym: ??0TeleportTrack@fn_f79dcf9e@@QAE@XZ
TeleportTrack::TeleportTrack() : Track_170810(), a(0) {
    pair.reset();
    d = -1.0f;
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_f79dcf9e

// 0x00170840 hulkfight::motion::TeleportTrack::vfunc_6 (4 B): matches/0x00170840.cpp
// sym: ?vfunc_6@TeleportTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TeleportTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170850 hulkfight::motion::TeleportTrack::vfunc_7 (7 B): matches/0x00170850.cpp
// sym: ?vfunc_7@TeleportTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::TeleportTrack::vfunc_7() {
    return DAT_003f32e0;
}

