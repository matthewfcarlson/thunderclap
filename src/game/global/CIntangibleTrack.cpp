// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a120..0x0006a1e0 (kind game, layer game, confidence high), dominant class CIntangibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fc7abc97 {
#define TREE_TU_END }
namespace fn_fc7abc97 {} using namespace fn_fc7abc97;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc7abc97 {
extern int* hulk_at_004dcf90;
class CCondition_6a140 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6a1a0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a1a0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Helper_6a1c0 {
  public:
    int go_0001f560(hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);


// 0x0006a120 FUN_0006a120 (19 B): matches/0x0006a120.cpp
// sym: ?FUN_0006a120@fn_fc7abc97@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a120(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf90), ((char*)&DAT_004dcf94));
}

} // namespace fn_fc7abc97

// 0x0006a140 CIntangibleTrack::vfunc_0 (16 B): matches/0x0006a140.cpp
// sym: ?vfunc_0@CIntangibleTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CIntangibleTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf90;
    return p[index];
}


// 0x0006a150 FUN_0006a150 (39 B): matches/0x0006a150.cpp [wrapped: conflict: CIntangibleTrack]
// sym: ??0CIntangibleTrack@fn_0006a150@@QAE@XZ
namespace fn_0006a150 {
class CTrack_6a150 {
  public:
    virtual void f0();
    virtual bool f1_00234270(void*);
    CTrack_6a150();
};

class CIntangibleTrack : public CTrack_6a150 {
  public:
    virtual void f0();
    char pad4[4];
    int m8;
    float mC;
    float m10;
    CIntangibleTrack();
};

CIntangibleTrack::CIntangibleTrack() {
    mC = 0.0f;
    m10 = -1.0f;
    m8 = 1;
}
} // namespace fn_0006a150


// 0x0006a180 CIntangibleTrack::vfunc_13 (13 B): matches/0x0006a180.cpp
// sym: ?vfunc_13@CIntangibleTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CIntangibleTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a190 CIntangibleTrack::vfunc_6 (4 B): matches/0x0006a190.cpp
// sym: ?vfunc_6@CIntangibleTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CIntangibleTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a1a0 CIntangibleTrack::vfunc_7 (7 B): matches/0x0006a1a0.cpp
// sym: ?vfunc_7@CIntangibleTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CIntangibleTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006a1c0 CIntangibleTrack::vfunc_12 (26 B): matches/0x0006a1c0.cpp
// sym: ?vfunc_12@CIntangibleTrack@@UAEHH@Z
// Same code shape as 0x0005e050 (propagated; names are from that function)
hulk_intptr CIntangibleTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_6a1c0*)p)->go_0001f560(a);
    return 0;
}

