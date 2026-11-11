// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a760..0x0006a890 (kind game, layer game, confidence high), dominant class CDriftTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f37c1e1b {
#define TREE_TU_END }
namespace fn_f37c1e1b {} using namespace fn_f37c1e1b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f37c1e1b {
class A_6a760 {
  public:
    char pad[0x33c];
    A_6a760* Next_00059a30();
};
class B_6a760 {
  public:
};
class D {
  public:
    int Run_0001fc60(COrientTargetTrack*, void*, int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
extern D* __cdecl FUN_0001fc60(void*);
extern int* hulk_at_004dcfc8;
struct Param_6a840 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a840 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class R_6a860 {
  public:
    int invoke_0001fde0(CDriftTrack*, hulk_intptr);
};
extern R_6a860* FUN_0008d690(int);

} // namespace fn_f37c1e1b

// 0x0006a760 COrientTargetTrack::vfunc_12 (91 B): matches/0x0006a760.cpp
// sym: ?vfunc_12@COrientTargetTrack@@UAEHH@Z
hulk_intptr COrientTargetTrack::vfunc_12(hulk_intptr __p0) { void * p = (void *)__p0;

    B_6a760* b = (B_6a760*)p;
    A_6a760* a = ((A_6a760 *)((owners::Object_592a0 *)b)->FUN_000592a0());
    a = a->Next_00059a30();
    int v = *(int*)((char*)a + 0x338);
    if (!v)
        v = *(int*)((char*)a + 0x334);
    if (!v)
        v = *(int*)((char*)a + 0x330);
    if (v) {
        D* d = (D*)FUN_0008d690(0x2c);
        if (d)
            return d->Run_0001fc60(this, p, v);
    }
    return 0;
}

namespace fn_f37c1e1b {

// 0x0006a7c0 FUN_0006a7c0 (19 B): matches/0x0006a7c0.cpp
// sym: ?FUN_0006a7c0@fn_f37c1e1b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a7c0() {
    FUN_00234810(((char*)&DAT_004dcfc8), ((char*)&DAT_004dcfcc));
}

} // namespace fn_f37c1e1b

// 0x0006a7e0 CDriftTrack::vfunc_0 (16 B): matches/0x0006a7e0.cpp
// sym: ?vfunc_0@CDriftTrack@@UAEHH@Z
hulk_intptr CDriftTrack::vfunc_0(int a) {
    return hulk_at_004dcfc8[a];
}


// 0x0006a7f0 FUN_0006a7f0 (47 B): matches/0x0006a7f0.cpp [wrapped: conflict: CDriftTrack]
// sym: ??0CDriftTrack@fn_0006a7f0@@QAE@XZ
namespace fn_0006a7f0 {
class CTrack_6a7f0 {
  public:
    CTrack_6a7f0();
    virtual ~CTrack_6a7f0();
};
class CDriftTrack : public CTrack_6a7f0 {
  public:
    CDriftTrack();
    virtual ~CDriftTrack();
    char pad4[4];
    int m8;
    int mC;
    float m10;
    int m14;
    float m18;
};
CDriftTrack::CDriftTrack() {
    mC = 0;
    m14 = 0;
    m10 = -1.0f;
    m18 = 1.0f;
    m8 = 1;
}
} // namespace fn_0006a7f0


// 0x0006a820 CDriftTrack::vfunc_13 (13 B): matches/0x0006a820.cpp
// sym: ?vfunc_13@CDriftTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CDriftTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x0006a830 CDriftTrack::vfunc_6 (4 B): matches/0x0006a830.cpp
// sym: ?vfunc_6@CDriftTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CDriftTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a840 CDriftTrack::vfunc_7 (7 B): matches/0x0006a840.cpp
// sym: ?vfunc_7@CDriftTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CDriftTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006a860 CDriftTrack::vfunc_12 (40 B): matches/0x0006a860.cpp
// sym: ?vfunc_12@CDriftTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CDriftTrack::vfunc_12(hulk_intptr param) {
    R_6a860* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001fde0(this, param);
    return 0;
}

