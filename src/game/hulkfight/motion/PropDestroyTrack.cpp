// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181640..0x001817d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDestroyTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1f16d33 {
#define TREE_TU_END }
namespace fn_f1f16d33 {} using namespace fn_f1f16d33;
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1f16d33 {
extern "C" char DAT_0041959c[];
class Sub_181640 {
  public:
    void init_0027af50();
};
// (nat2, D134) the track's record: its name (+0x10 on 32-bit) is a pointer, freed with operator delete[]; the name id
// at +0x18 its own words
class PropSpawnTrack : public ::hulkfight::motion::PropSpawnTrack {
  public:
    void finish_00236d60();
    void run();
};
extern "C" void* __cdecl FUN_0008d6d0(int);   // (decl1) as defined (unk_08ceb0.cpp)
extern int* hulk_at_004e14e8;
class CCondition_1816f0 {
  public:
    virtual int vfunc_0(int);
};
class Track_181700 {
  public:
    Track_181700();
    virtual void f();
    int pad;
};
class PropDestroyTrack : public ::hulkfight::motion::PropDestroyTrack {
  public:
    PropDestroyTrack();
};


// 0x00181640 FUN_00181640 (37 B): matches/0x00181640.cpp
// sym: ?run@PropSpawnTrack@fn_f1f16d33@@QAEXXZ
void PropSpawnTrack::run() {
    *(void**)this = (void*)((hulk_intptr)DAT_0041959c);
    ::operator delete[](f_10);
    ((Sub_181640*)f_18)->init_0027af50();
    finish_00236d60();
}

} // namespace fn_f1f16d33

// 0x00181670 FUN_00181670 (82 B): matches/0x00181670.cpp
// sym: ?FUN_00181670@X_181670@owners@@QAEEPBD@Z
unsigned char owners::X_181670::FUN_00181670(const char* s) {
    ::operator delete[](p);
    if (!s) {
        p = 0;
        return 1;
    }
    p = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(p, s);
    return 1;
}

namespace fn_f1f16d33 {

// 0x001816d0 FUN_001816d0 (19 B): matches/0x001816d0.cpp
// sym: ?FUN_001816d0@fn_f1f16d33@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001816d0() {
    FUN_00234810(((char*)&DAT_004e14e8), ((char*)&DAT_004e14ec));
}

} // namespace fn_f1f16d33

// 0x001816f0 hulkfight::motion::PropDestroyTrack::vfunc_0 (16 B): matches/0x001816f0.cpp
// sym: ?vfunc_0@PropDestroyTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropDestroyTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14e8;
    return p[index];
}

namespace fn_f1f16d33 {

// 0x00181700 FUN_00181700 (33 B): matches/0x00181700.cpp
// sym: ??0PropDestroyTrack@fn_f1f16d33@@QAE@XZ
PropDestroyTrack::PropDestroyTrack() {
    f_0c = 0;
    f_10 = 0;
    f_08 = 1;
}

} // namespace fn_f1f16d33

// 0x00181730 hulkfight::motion::PropDestroyTrack::vfunc_6 (4 B): matches/0x00181730.cpp
// sym: ?vfunc_6@PropDestroyTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropDestroyTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00181740 hulkfight::motion::PropDestroyTrack::vfunc_7 (7 B): matches/0x00181740.cpp
// sym: ?vfunc_7@PropDestroyTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropDestroyTrack::vfunc_7() {
    return DAT_003f32e0;
}

