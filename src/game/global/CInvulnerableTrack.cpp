// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a970..0x0006aa50 (kind game, layer game, confidence high), dominant class CInvulnerableTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fb04fe61 {
#define TREE_TU_END }
namespace fn_fb04fe61 {} using namespace fn_fb04fe61;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb04fe61 {
extern int* hulk_at_004dcfd8;
class CCondition_6a990 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6a9f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a9f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0006a970 FUN_0006a970 (19 B): matches/0x0006a970.cpp
// sym: ?FUN_0006a970@fn_fb04fe61@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a970() {
    FUN_00234810(((char*)&DAT_004dcfd8), ((char*)&DAT_004dcfdc));
}

} // namespace fn_fb04fe61

// 0x0006a990 CInvulnerableTrack::vfunc_0 (16 B): matches/0x0006a990.cpp
// sym: ?vfunc_0@CInvulnerableTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CInvulnerableTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcfd8;
    return p[index];
}


// 0x0006a9a0 FUN_0006a9a0 (40 B): matches/0x0006a9a0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CInvulnerableTrack@fn_0006a9a0@@QAE@XZ
namespace fn_0006a9a0 {
class CTrack_6a9a0 {
  public:
    virtual void BPlaceholder();
    CTrack_6a9a0();
};

class CInvulnerableTrack : public CTrack_6a9a0 {
  public:
    virtual void Placeholder();
    int m4;
    int m8;
    int mC;
    float m10;
    int m14;
    CInvulnerableTrack();
};
void CInvulnerableTrack::Placeholder() {}

CInvulnerableTrack::CInvulnerableTrack() {
    mC = 0;
    m14 = 0;
    m10 = -1.0f;
    m8 = 1;
}
} // namespace fn_0006a9a0


// 0x0006a9d0 CInvulnerableTrack::vfunc_13 (13 B): matches/0x0006a9d0.cpp
// sym: ?vfunc_13@CInvulnerableTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CInvulnerableTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a9e0 CInvulnerableTrack::vfunc_6 (4 B): matches/0x0006a9e0.cpp
// sym: ?vfunc_6@CInvulnerableTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CInvulnerableTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a9f0 CInvulnerableTrack::vfunc_7 (7 B): matches/0x0006a9f0.cpp
// sym: ?vfunc_7@CInvulnerableTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CInvulnerableTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006aa10 CInvulnerableTrack::vfunc_12 (52 B): equivalent/0x0006aa10.cpp [wrapped: conflict: CInvulnerableTrack]
// sym: ?vfunc_12@CInvulnerableTrack@fn_0006aa10@@QAEPAUCInvulnerableAction_6aa10@2@PAX@Z @d6b56f4b32ce @w70346cf95fe3
namespace fn_0006aa10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CInvulnerableTrack::vfunc_12 @ 0x0006aa10
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
struct CInvulnerableAction_6aa10 {
    CInvulnerableAction_6aa10* FUN_000200a0(void* argument, void* source);
};
struct CInvulnerableTrack {
    char pad[0x14];
    void* source;
    CInvulnerableAction_6aa10* vfunc_12(void* argument);
};
CInvulnerableAction_6aa10* CInvulnerableTrack::vfunc_12(void* argument)
{
    CInvulnerableAction_6aa10* object = (CInvulnerableAction_6aa10*)FUN_0008d690(0x24);
    if (object != 0)
        return object->FUN_000200a0(argument, source);
    return 0;
}
} // namespace fn_0006aa10

