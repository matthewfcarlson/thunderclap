// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069400..0x000694f0 (kind game, layer game, confidence high), dominant class CDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f21eb17b {
#define TREE_TU_END }
namespace fn_f21eb17b {} using namespace fn_f21eb17b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f21eb17b {
extern int* hulk_at_004dcf28;
struct Param_694a0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_694a0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_694c0 {
  public:
    int FUN_000190a0(CDropTrack*, hulk_intptr);
};


// 0x00069400 FUN_00069400 (19 B): matches/0x00069400.cpp
// sym: ?FUN_00069400@fn_f21eb17b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069400(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf28), ((char*)&DAT_004dcf2c));
}

} // namespace fn_f21eb17b

// 0x00069420 CDropTrack::vfunc_0 (16 B): matches/0x00069420.cpp
// sym: ?vfunc_0@CDropTrack@@UAEHH@Z
hulk_intptr CDropTrack::vfunc_0(int index) {
    return hulk_at_004dcf28[index];
}


// 0x00069430 FUN_00069430 (68 B): matches/0x00069430.cpp [wrapped: conflict: CDropTrack]
// sym: ??0CDropTrack@fn_00069430@@QAE@XZ
namespace fn_00069430 {
class CTrack_69430 {
  public:
    virtual void F0();
    virtual bool F1_00234270(void*);
    virtual ~CTrack_69430() throw();
    CTrack_69430();
    char pad[8];
};

class CDropTrack : public CTrack_69430 {
  public:
    virtual void F0();
    virtual ~CDropTrack() throw();
    CDropTrack();

  private:
    float mX; // 0xc
    float mY; // 0x10
    float mZ; // 0x14
    float mW; // 0x18
    float mA; // 0x1c
    char mB;  // 0x20
    float mC; // 0x24
    float mD; // 0x28
    float mE; // 0x2c
    int mF;   // 0x30
    float mG; // 0x34
    float mH; // 0x38
    char pad2[4];
};

CDropTrack::CDropTrack() {
    mX = 0.0f;
    mY = -1.0f;
    mZ = 0.0f;
    mW = 0.0f;
    mA = 0.0f;
    mB = 0;
    mC = 0.0f;
    mD = 9.8f;
    mE = 0.0f;
    mF = -5;
    mG = 0.0f;
    mH = 0.0f;
}
} // namespace fn_00069430


// 0x00069480 CDropTrack::vfunc_13 (13 B): matches/0x00069480.cpp
// sym: ?vfunc_13@CDropTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CDropTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x00069490 CDropTrack::vfunc_6 (4 B): matches/0x00069490.cpp
// sym: ?vfunc_6@CDropTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CDropTrack::vfunc_6() {
    return this->f_0c;
}


// 0x000694a0 CDropTrack::vfunc_7 (7 B): matches/0x000694a0.cpp
// sym: ?vfunc_7@CDropTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CDropTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x000694c0 CDropTrack::vfunc_12 (40 B): matches/0x000694c0.cpp
// sym: ?vfunc_12@CDropTrack@@UAEHH@Z
hulk_intptr CDropTrack::vfunc_12(hulk_intptr param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_694c0*)p)->FUN_000190a0(this, param);
    return 0;
}

