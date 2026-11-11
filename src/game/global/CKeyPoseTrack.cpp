// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000694f0..0x00069690 (kind game, layer game, confidence high), dominant class CKeyPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7e28208 {
#define TREE_TU_END }
namespace fn_f7e28208 {} using namespace fn_f7e28208;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7e28208 {
extern int* gTable_69510;
class CCondition_69510 {
  public:
    virtual int vfunc_0(int);
};
extern float gNegOne;
struct Helper_695b0 {
    void Fin();
};
class CTrack_695b0 {
  public:
    void Base();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_69660 {
  public:
    int FUN_0001d100(CKeyPoseTrack*, hulk_intptr);
};


// 0x000694f0 FUN_000694f0 (19 B): matches/0x000694f0.cpp
// sym: ?FUN_000694f0@fn_f7e28208@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000694f0() {
    FUN_00234810(((char*)&DAT_004dcf30), ((char*)&DAT_004dcf34));
}

} // namespace fn_f7e28208

// 0x00069510 CKeyPoseTrack::vfunc_0 (16 B): matches/0x00069510.cpp
// sym: ?vfunc_0@CKeyPoseTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CKeyPoseTrack::vfunc_0(int index) {
    int* p = gTable_69510;
    return p[index];
}


// 0x00069520 FUN_00069520 (109 B): matches/0x00069520.cpp [wrapped: conflict: CKeyPoseTrack]
// sym: ??0CKeyPoseTrack@fn_00069520@@QAE@XZ
namespace fn_00069520 {
class CTrack_69520 {
  public:
    virtual void Fn();
    CTrack_69520();
    char pad[0x0c];
};

class Member_69520 {
  public:
    Member_69520();
    char pad[8];
};

class CKeyPoseTrack : public CTrack_69520 {
  public:
    virtual ~CKeyPoseTrack() throw();
    Member_69520 m10;
    float arr[16];
    char m58;
    char pad1[7];
    Member_69520 m60;
    int m68;
    float m6c;
    float m70;
    CKeyPoseTrack();
};

CKeyPoseTrack::CKeyPoseTrack() : CTrack_69520(), m10(), m58(1), m60() {
    {
        int* q = &m68;
        *q = 0;
    }
    m6c = 0.1f;
    m70 = 0.1f;
    arr[0] = -1.0f;
    arr[8] = -1.0f;
    arr[1] = -1.0f;
    arr[9] = -1.0f;
    arr[2] = -1.0f;
    arr[10] = -1.0f;
    arr[3] = -1.0f;
    arr[11] = -1.0f;
    arr[4] = -1.0f;
    arr[12] = -1.0f;
    arr[5] = -1.0f;
    arr[13] = -1.0f;
    arr[6] = -1.0f;
    arr[14] = -1.0f;
    arr[7] = -1.0f;
    arr[15] = -1.0f;
}
} // namespace fn_00069520


// 0x00069590 CKeyPoseTrack::vfunc_13 (13 B): matches/0x00069590.cpp
// sym: ?vfunc_13@CKeyPoseTrack@@UAEXPAX@Z
// Same code shape as 0x0005dd10 (propagated; names are from that function)
void CKeyPoseTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffff0000;
}


// 0x000695a0 CKeyPoseTrack::vfunc_7 (7 B): matches/0x000695a0.cpp
// sym: ?vfunc_7@CKeyPoseTrack@@UAEMXZ
hulk_freg CKeyPoseTrack::vfunc_7() {
    return gNegOne;
}


// 0x000695b0 FUN_000695b0 (39 B): matches/0x000695b0.cpp
// sym: ?FUN_000695b0@CKeyPoseTrack@@QAEXXZ
void CKeyPoseTrack::FUN_000695b0() {
    *(void**)this = (void*)((hulk_intptr)DAT_003fbb34);
    ((Helper_695b0*)((char*)this + 0x60))->Fin();
    ((Helper_695b0*)((char*)this + 0x10))->Fin();
    *(void**)this = (void*)((hulk_intptr)DAT_003f98d0);
    ((CTrack_695b0*)this)->Base();
}


// 0x000695e0 FUN_000695e0 (29 B): matches/0x000695e0.cpp
// sym: ?FUN_000695e0@A_695e0@owners@@QAEMH@Z
// data: minusOne = DAT_003f3388
float owners::A_695e0::FUN_000695e0(int i) {
    if (i >= 0 && i < 8)
        return values[i];
    return DAT_003f3388;
}


// 0x00069620 FUN_00069620 (29 B): matches/0x00069620.cpp
// sym: ?FUN_00069620@Thing_69620@owners@@QAEMH@Z
float owners::Thing_69620::FUN_00069620(int i) {
    if (i >= 0 && i < 8)
        return *(float*)((char*)this + 0x38 + i * 4);
    return -1.0f;
}


// 0x00069660 CKeyPoseTrack::vfunc_12 (40 B): matches/0x00069660.cpp
// sym: ?vfunc_12@CKeyPoseTrack@@UAEHH@Z
// Same code shape as 0x000694c0 (propagated; names are from that function)
hulk_intptr CKeyPoseTrack::vfunc_12(hulk_intptr param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_69660*)p)->FUN_0001d100(this, param);
    return 0;
}

