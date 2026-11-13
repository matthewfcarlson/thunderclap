// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a1e0..0x0006a2a0 (kind game, layer game, confidence high), dominant class CIntangibleToActorsTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fcfa2476 {
#define TREE_TU_END }
namespace fn_fcfa2476 {} using namespace fn_fcfa2476;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcfa2476 {
extern void** hulk_at_004dcf98;
struct Param_6a260 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a260 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Helper_6a280 {
  public:
    int go_0001f5d0(hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);


// 0x0006a1e0 FUN_0006a1e0 (19 B): matches/0x0006a1e0.cpp
// sym: ?FUN_0006a1e0@fn_fcfa2476@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a1e0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf98), ((char*)&DAT_004dcf9c));
}

} // namespace fn_fcfa2476

// 0x0006a200 CIntangibleToActorsTrack::vfunc_0 (16 B): matches/0x0006a200.cpp
// sym: ?vfunc_0@CIntangibleToActorsTrack@@UAEHH@Z
hulk_intptr CIntangibleToActorsTrack::vfunc_0(int i) {
    return (hulk_intptr)(hulk_at_004dcf98[i]);
}


// 0x0006a210 FUN_0006a210 (39 B): matches/0x0006a210.cpp [wrapped: conflict: CIntangibleToActorsTrack]
// sym: ??0CIntangibleToActorsTrack@fn_0006a210@@QAE@XZ
namespace fn_0006a210 {
class CTrack_6a210 {
  public:
    virtual hulk_intptr FnBase0_0006a200(int);
    virtual bool FnBase1_00234270(void*);
    CTrack_6a210();
};

class CIntangibleToActorsTrack : public CTrack_6a210 {
  public:
    virtual bool Fn0_002342b0(int);
    virtual bool Fn1_00236c50(hulk_intptr, int, hulk_intptr);
    CIntangibleToActorsTrack();

  private:
    char pad0[4];
    int mCount;
    float mFloat0;
    float mFloat1;
};

CIntangibleToActorsTrack::CIntangibleToActorsTrack() {
    mFloat0 = 0.0f;
    mFloat1 = -1.0f;
    mCount = 1;
}
} // namespace fn_0006a210


// 0x0006a240 CIntangibleToActorsTrack::vfunc_13 (13 B): matches/0x0006a240.cpp
// sym: ?vfunc_13@CIntangibleToActorsTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CIntangibleToActorsTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a250 CIntangibleToActorsTrack::vfunc_6 (4 B): matches/0x0006a250.cpp
// sym: ?vfunc_6@CIntangibleToActorsTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CIntangibleToActorsTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a260 CIntangibleToActorsTrack::vfunc_7 (7 B): matches/0x0006a260.cpp
// sym: ?vfunc_7@CIntangibleToActorsTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CIntangibleToActorsTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006a280 CIntangibleToActorsTrack::vfunc_12 (26 B): matches/0x0006a280.cpp
// sym: ?vfunc_12@CIntangibleToActorsTrack@@UAEHH@Z
// Same code shape as 0x0005e050 (propagated; names are from that function)
hulk_intptr CIntangibleToActorsTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_6a280*)p)->go_0001f5d0(a);
    return 0;
}

