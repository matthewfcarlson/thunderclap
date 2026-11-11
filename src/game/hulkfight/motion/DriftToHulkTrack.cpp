// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170460..0x00170570 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToHulkTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f659ad5b {
#define TREE_TU_END }
namespace fn_f659ad5b {} using namespace fn_f659ad5b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f659ad5b {
extern "C" int hulk_at_00417a48;
class DriftToPositionTrack {
  public:
    hulk_intptr vf;
    char pad[0x24];
    int value;
    void f();
    void tail_00236d60();
};
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src;
        src++;
        *dst = c;
        dst++;
    } while (c);
}
class Obj {
    char pad[0x28];
    char* s;

  public:
    unsigned char Set(const char* p);
};
extern int* hulk_at_004e1338;
class CCondition_170500 {
  public:
    virtual int vfunc_0(int);
};
struct Param_170550 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170550 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170460 FUN_00170460 (29 B): matches/0x00170460.cpp
// sym: ?f@DriftToPositionTrack@fn_f659ad5b@@QAEXXZ
void DriftToPositionTrack::f() {
    vf = (hulk_intptr)&hulk_at_00417a48;
    thunk(value);
    tail_00236d60();
}


// 0x00170480 FUN_00170480 (82 B): matches/0x00170480.cpp
// sym: ?Set@Obj@fn_f659ad5b@@QAEEPBD@Z
unsigned char Obj::Set(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    char* dst = (char*)Alloc(strlen(p) + 1);
    s = dst;
    Copy(dst, p);
    return 1;
}


// 0x001704e0 FUN_001704e0 (19 B): matches/0x001704e0.cpp
// sym: ?FUN_001704e0@fn_f659ad5b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001704e0() {
    FUN_00234810(((char*)&DAT_004e1338), ((char*)&DAT_004e133c));
}

} // namespace fn_f659ad5b

// 0x00170500 hulkfight::motion::DriftToHulkTrack::vfunc_0 (16 B): matches/0x00170500.cpp
// sym: ?vfunc_0@DriftToHulkTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::DriftToHulkTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1338;
    return p[index];
}


// 0x00170510 FUN_00170510 (46 B): equivalent/0x00170510.cpp [wrapped: conflict: hulkfight::motion::DriftToHulkTrack]
// sym: ??0DriftToHulkTrack@motion@hulkfight@fn_00170510@@QAE@XZ
namespace fn_00170510 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170510 @ 0x00170510
namespace hulkfight { namespace motion {
struct Track {
    Track();
    virtual void FUN_00236d40_virtual();
    char pad[4];
    int state;
    int pointer;
    float value;
    int extra1, extra2, extra3;
};
struct DriftToHulkTrack : Track {
    virtual void FUN_00236d40_virtual();
    DriftToHulkTrack();
};
DriftToHulkTrack::DriftToHulkTrack() : Track() {
    pointer = 0;
    value = -1.0f;
    extra1 = 0;
    extra2 = 0;
    extra3 = 0;
    state = 1;
}
}}
} // namespace fn_00170510


// 0x00170540 hulkfight::motion::DriftToHulkTrack::vfunc_6 (4 B): matches/0x00170540.cpp
// sym: ?vfunc_6@DriftToHulkTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::DriftToHulkTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170550 hulkfight::motion::DriftToHulkTrack::vfunc_7 (7 B): matches/0x00170550.cpp
// sym: ?vfunc_7@DriftToHulkTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::DriftToHulkTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

