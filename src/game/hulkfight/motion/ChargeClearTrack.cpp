// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170dc0..0x00170ed0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f18c5a89 {
#define TREE_TU_END }
namespace fn_f18c5a89 {} using namespace fn_f18c5a89;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f18c5a89 {
class TeleportToLocatorTrack_170dc0 {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish();
    void run();
};
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct TextHolder {
    char pad[0x10];
    char *text;
    bool SetText_00170de0(const char *value);
};
extern int* gTable_170e60;
class CCondition_170e60 {
  public:
    virtual int vfunc_0(int);
};
class Track_170e70 {
  public:
    Track_170e70();
    virtual void f();
    char pad[4];
};
class ChargeClearTrack : public Track_170e70 {
  public:
    ChargeClearTrack();
    int a;
    int zero;
    float b;
    char c;
    virtual void f();
};
struct Param_170eb0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170eb0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170dc0 FUN_00170dc0 (29 B): matches/0x00170dc0.cpp
// sym: ?run@TeleportToLocatorTrack_170dc0@fn_f18c5a89@@QAEXXZ
// Same code shape as 0x000f99b0 (propagated; names are from that function)
void TeleportToLocatorTrack_170dc0::run() {
    vptr = &rawVtable;
    thunk(mArg);
    finish();
}


// 0x00170de0 FUN_00170de0 (82 B): equivalent/0x00170de0.cpp
// sym: ?SetText_00170de0@TextHolder@fn_f18c5a89@@QAE_NPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetText_00170de0 @ 0x00170de0
bool TextHolder::SetText_00170de0(const char *value)
{
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return true;
    }
    unsigned int length = 0;
    while (value[length]) ++length;
    text = (char *)FUN_0008d6d0(length + 1);
    char *dest = text;
    do {
        *dest++ = *value;
    } while (*value++);
    return true;
}


// 0x00170e40 FUN_00170e40 (19 B): matches/0x00170e40.cpp
// sym: ?FUN_00170e40@fn_f18c5a89@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170e40() {
    FUN_00234810(((char*)&DAT_004e13a8), ((char*)&DAT_004e13ac));
}

} // namespace fn_f18c5a89

// 0x00170e60 hulkfight::motion::ChargeClearTrack::vfunc_0 (16 B): matches/0x00170e60.cpp
// sym: ?vfunc_0@ChargeClearTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ChargeClearTrack::vfunc_0(int index) {
    int* p = gTable_170e60;
    return p[index];
}

namespace fn_f18c5a89 {

// 0x00170e70 FUN_00170e70 (43 B): matches/0x00170e70.cpp
// sym: ??0ChargeClearTrack@fn_f18c5a89@@QAE@XZ
ChargeClearTrack::ChargeClearTrack() : Track_170e70() {
    c = 1;
    a = 1;
    zero = 0;
    b = -1.0f;
}

} // namespace fn_f18c5a89

// 0x00170ea0 hulkfight::motion::ChargeClearTrack::vfunc_6 (4 B): matches/0x00170ea0.cpp
// sym: ?vfunc_6@ChargeClearTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::ChargeClearTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00170eb0 hulkfight::motion::ChargeClearTrack::vfunc_7 (7 B): matches/0x00170eb0.cpp
// sym: ?vfunc_7@ChargeClearTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::ChargeClearTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

