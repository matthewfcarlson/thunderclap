// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a370..0x0006a4d0 (kind game, layer game, confidence high), dominant class CCameraDramaticTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fdd20f3b {
#define TREE_TU_END }
namespace fn_fdd20f3b {} using namespace fn_fdd20f3b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdd20f3b {
extern int* hulk_at_004dcfa8;
class CCondition_6a390 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6a460 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a460 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct CCameraDramaticTrack_6a470 {
    char pad[0x60];
};
struct Sub_6a470 {
    void Init_0027af50();
};
struct CCameraDramaticTrack_nv_6a470 {
    void Finish_00236d60();
};
extern int hulk_at_003fbeb8;
extern int hulk_at_003f98d0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_6a4a0 {
    int FUN_0001f880(CCameraDramaticTrack*, hulk_intptr);
};


// 0x0006a370 FUN_0006a370 (19 B): matches/0x0006a370.cpp
// sym: ?FUN_0006a370@fn_fdd20f3b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a370() {
    FUN_00234810(((char*)&DAT_004dcfa8), ((char*)&DAT_004dcfac));
}

} // namespace fn_fdd20f3b

// 0x0006a390 CCameraDramaticTrack::vfunc_0 (16 B): matches/0x0006a390.cpp
// sym: ?vfunc_0@CCameraDramaticTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCameraDramaticTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcfa8;
    return p[index];
}


// 0x0006a3a0 FUN_0006a3a0 (152 B): matches/0x0006a3a0.cpp [wrapped: conflict: CCameraDramaticTrack]
// sym: ??0CCameraDramaticTrack@fn_0006a3a0@@QAE@XZ
namespace fn_0006a3a0 {
// FUN_0006a3a0 @ 0x0006a3a0
struct Name_6a3a0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) CTrack_6a3a0 {
public:
    virtual hulk_intptr b0_0006a390(int);
    int pad04;
    int mode;
    void FUN_00236d40();
    CTrack_6a3a0() { FUN_00236d40(); }
};

class CCameraDramaticTrack : public CTrack_6a3a0 {
public:
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    virtual bool v3_00236c50(hulk_intptr, int, hulk_intptr);
    int f0c;
    float f10;
    int f14, f18, f1c;
    Name_6a3a0 names[8];
    float weights[8];
    float scale;
    char flag;
    char pad85[3];
    int f88, f8c, f90, f94, f98, f9c;

    CCameraDramaticTrack();
};

CCameraDramaticTrack::CCameraDramaticTrack() {
    f0c = 0;
    f10 = -1.0f;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    for (int i = 0; i < 8; i++)
        names[i].FUN_0027af00();
    scale = 1.0f;
    flag = 0;
    f88 = 0; f8c = 0; f90 = 0; f94 = 0; f98 = 0; f9c = 0;
    mode = 1;
    for (int i = 0; i < 8; i++)
        weights[i] = 1.0f;
}
} // namespace fn_0006a3a0


// 0x0006a440 CCameraDramaticTrack::vfunc_13 (13 B): matches/0x0006a440.cpp
// sym: ?vfunc_13@CCameraDramaticTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CCameraDramaticTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a450 CCameraDramaticTrack::vfunc_6 (4 B): matches/0x0006a450.cpp
// sym: ?vfunc_6@CCameraDramaticTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CCameraDramaticTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a460 CCameraDramaticTrack::vfunc_7 (7 B): matches/0x0006a460.cpp
// sym: ?vfunc_7@CCameraDramaticTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CCameraDramaticTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fdd20f3b {

// 0x0006a470 FUN_0006a470 (48 B): matches/0x0006a470.cpp
// sym: ?Target@fn_fdd20f3b@@YIXPAUCCameraDramaticTrack_6a470@1@@Z
void __fastcall Target(CCameraDramaticTrack_6a470* self) {
    *(int**)self = &hulk_at_003fbeb8;
    Sub_6a470* p = (Sub_6a470*)((char*)self + 0x60);
    int n = 8;
    do {
        p = (Sub_6a470*)((char*)p - 8);
        p->Init_0027af50();
        --n;
    } while (n != 0);
    *(int**)self = &hulk_at_003f98d0;
    ((CCameraDramaticTrack_nv_6a470*)(((CCameraDramaticTrack*)self)))->Finish_00236d60();
}

} // namespace fn_fdd20f3b

// 0x0006a4a0 CCameraDramaticTrack::vfunc_12 (40 B): matches/0x0006a4a0.cpp
// sym: ?vfunc_12@CCameraDramaticTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CCameraDramaticTrack::vfunc_12(hulk_intptr param) {
    Helper_6a4a0* p = (Helper_6a4a0*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001f880(this, param);
    return 0;
}

