// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170100..0x00170240 (kind game, layer game, confidence high), dominant class hulkfight::motion::SuckTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fefa0dcd {
#define TREE_TU_END }
namespace fn_fefa0dcd {} using namespace fn_fefa0dcd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fefa0dcd {
typedef unsigned int u32_170100;
extern void __cdecl thunk_FUN_00267090(u32_170100);
extern int SyncVftable;
struct Helper_170100 {
    void call();
};
class SyncToLocatorTrack {
  public:
    int* vftable;
    char pad[0x28 - 4];
    u32_170100 field;
    void f();
    void finish();
};
void thunk_FUN_00267090(void*);
extern "C" char* __cdecl FUN_0008d6d0(unsigned int);
extern int* gTable_1701c0;
class CCondition_1701c0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1701d0 {
  public:
    Track_1701d0();
    virtual void f();
    char pad[4];
};
class SuckTrack : public Track_1701d0 {
  public:
    SuckTrack();
    virtual void f();
    int a;
    int b;
    float c;
    int d, e, f1, g;
};
struct Param_170220 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170220 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170100 FUN_00170100 (37 B): matches/0x00170100.cpp
// sym: ?f@SyncToLocatorTrack@fn_fefa0dcd@@QAEXXZ
void SyncToLocatorTrack::f() {
    u32_170100 x = field;
    vftable = &SyncVftable;
    thunk_FUN_00267090(x);
    ((Helper_170100*)((char*)this + 0x20))->call();
    finish();
}

} // namespace fn_fefa0dcd

// 0x00170130 FUN_00170130 (102 B): matches/0x00170130.cpp
// sym: ?FUN_00170130@StrHolder_170130@owners@@QAE_NPBDH@Z
// FUN_00170130 @ 0x00170130
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
bool owners::StrHolder_170130::FUN_00170130(const char* src, int len) {
    thunk_FUN_00267090(text);
    if (src != 0 && len > 0) {
        text = FUN_0008d6d0(len + 1);
        memcpy(text, src, len);
        text[len] = 0;
        length = len;
        return true;
    }
    text = 0;
    length = 0;
    return true;
}

namespace fn_fefa0dcd {

// 0x001701a0 FUN_001701a0 (19 B): matches/0x001701a0.cpp
// sym: ?FUN_001701a0@fn_fefa0dcd@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001701a0() {
    FUN_00234810(((char*)&DAT_004e1318), ((char*)&DAT_004e131c));
}

} // namespace fn_fefa0dcd

// 0x001701c0 hulkfight::motion::SuckTrack::vfunc_0 (16 B): matches/0x001701c0.cpp
// sym: ?vfunc_0@SuckTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SuckTrack::vfunc_0(int index) {
    int* p = gTable_1701c0;
    return p[index];
}

namespace fn_fefa0dcd {

// 0x001701d0 FUN_001701d0 (49 B): matches/0x001701d0.cpp
// sym: ??0SuckTrack@fn_fefa0dcd@@QAE@XZ
SuckTrack::SuckTrack() : b(0), d(0), e(0), f1(0), g(0) {
    c = -1.0f;
    a = 1;
}

} // namespace fn_fefa0dcd

// 0x00170210 hulkfight::motion::SuckTrack::vfunc_6 (4 B): matches/0x00170210.cpp
// sym: ?vfunc_6@SuckTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SuckTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170220 hulkfight::motion::SuckTrack::vfunc_7 (7 B): matches/0x00170220.cpp
// sym: ?vfunc_7@SuckTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::SuckTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

