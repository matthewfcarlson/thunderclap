// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069690..0x00069790 (kind game, layer game, confidence high), dominant class CSoundTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fdda11e6 {
#define TREE_TU_END }
namespace fn_fdda11e6 {} using namespace fn_fdda11e6;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdda11e6 {
extern int* hulk_at_004dcf38;
class CCondition_696b0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" int FUN_00267760(void* buf, int size, const char* fmt, ...);
class A_69730 {
  public:
    bool Fn(int x);
    char header[0x10];
    char buf[0x40];
};
class Obj_69750 {
  public:
    char pad[0x50];
    unsigned char mFlag;
    unsigned char FUN_00069750(unsigned char v);
};
class R_69760 {
  public:
    int invoke_0001d190(CSoundTrack*, hulk_intptr);
};
extern "C" R_69760* FUN_0008d690(int);


// 0x00069690 FUN_00069690 (19 B): matches/0x00069690.cpp
// sym: ?FUN_00069690@fn_fdda11e6@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069690(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf38), ((char*)&DAT_004dcf3c));
}

} // namespace fn_fdda11e6

// 0x000696b0 CSoundTrack::vfunc_0 (16 B): matches/0x000696b0.cpp
// sym: ?vfunc_0@CSoundTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSoundTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf38;
    return p[index];
}


// 0x000696c0 FUN_000696c0 (36 B): matches/0x000696c0.cpp [wrapped: conflict: CSoundTrack]
// sym: ??0CSoundTrack@fn_000696c0@@QAE@XZ
namespace fn_000696c0 {
class CTrack_696c0 {
  public:
    CTrack_696c0();
    virtual void v0();
    int m4;
};

class CSoundTrack : public CTrack_696c0 {
  public:
    CSoundTrack();
    virtual void v0();
    virtual bool v1_00234270(void*);
    int m8;
    int mC;
    char m10;
    char pad[0x3f];
    char m50;
};

CSoundTrack::CSoundTrack() {
    mC = 0;
    m10 = 0;
    m50 = 0;
    m8 = 1;
}
} // namespace fn_000696c0


// 0x000696f0 CSoundTrack::vfunc_13 (13 B): matches/0x000696f0.cpp
// sym: ?vfunc_13@CSoundTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CSoundTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00069700 CSoundTrack::vfunc_6 (4 B): matches/0x00069700.cpp
// sym: ?vfunc_6@CSoundTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSoundTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069710 CSoundTrack::vfunc_7 (7 B): matches/0x00069710.cpp
// sym: ?vfunc_7@CSoundTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CSoundTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fdda11e6 {

// 0x00069730 FUN_00069730 (29 B): matches/0x00069730.cpp
// sym: ?Fn@A_69730@fn_fdda11e6@@QAE_NH@Z
bool A_69730::Fn(int x) {
    FUN_00267760(buf, 0x40, "%s", x);
    return true;
}


// 0x00069750 FUN_00069750 (12 B): matches/0x00069750.cpp
// sym: ?FUN_00069750@Obj_69750@fn_fdda11e6@@QAEEE@Z
unsigned char Obj_69750::FUN_00069750(unsigned char v) {
    unsigned char r = 1;
    mFlag = v;
    return r;
}

} // namespace fn_fdda11e6

// 0x00069760 CSoundTrack::vfunc_12 (40 B): matches/0x00069760.cpp
// sym: ?vfunc_12@CSoundTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CSoundTrack::vfunc_12(hulk_intptr param) {
    R_69760* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001d190(this, param);
    return 0;
}

