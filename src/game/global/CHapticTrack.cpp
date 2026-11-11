// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005d190..0x0005d370 (kind game, layer game, confidence high), dominant class CHapticTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3580c47 {
#define TREE_TU_END }
namespace fn_f3580c47 {} using namespace fn_f3580c47;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3580c47 {
extern int* hulk_at_004dc5c8;
class CCondition_5d190 {
  public:
    virtual int vfunc_0(int);
};
class R_5d200 {
  public:
    int invoke_00020a40(CHapticTrack*, hulk_intptr);
};
extern "C" R_5d200* FUN_0008d690(int);
class CStageCondition_5d2d0;
class ParamValue_5d2d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5d2d0 : public ParamValue_5d2d0 {
  public:
    int pad;
};
class CStageCondition_5d320;
class ParamValue_5d320 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5d320 : public ParamValue_5d320 {
  public:
    int pad;
};

} // namespace fn_f3580c47

// 0x0005d190 CHapticTrack::vfunc_0 (16 B): matches/0x0005d190.cpp
// sym: ?vfunc_0@CHapticTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CHapticTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5c8;
    return p[index];
}


// 0x0005d1b0 CHapticTrack::vfunc_13 (13 B): matches/0x0005d1b0.cpp
// sym: ?vfunc_13@CHapticTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CHapticTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0005d1c0 CHapticTrack::vfunc_6 (4 B): matches/0x0005d1c0.cpp
// sym: ?vfunc_6@CHapticTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CHapticTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005d1d0 CHapticTrack::vfunc_14 (4 B): matches/0x0005d1d0.cpp
// sym: ?vfunc_14@CHapticTrack@@UAEMXZ
hulk_freg CHapticTrack::vfunc_14() {
    return this->f_10;
}


// 0x0005d1e0 CHapticTrack::vfunc_7 (21 B): matches/0x0005d1e0.cpp
// sym: ?vfunc_7@CHapticTrack@@UAEMXZ
// data: gMinusOne_5d1e0 = DAT_003f3388, gZero_5d1e0 = DAT_003f32e0
hulk_freg CHapticTrack::vfunc_7() {
    if (this->f_1c)
        return DAT_003f3388;
    return DAT_003f32e0;
}


// 0x0005d200 CHapticTrack::vfunc_12 (40 B): matches/0x0005d200.cpp
// sym: ?vfunc_12@CHapticTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CHapticTrack::vfunc_12(hulk_intptr param) {
    R_5d200* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_00020a40(this, param);
    return 0;
}


// 0x0005d230 FUN_0005d230 (46 B): matches/0x0005d230.cpp [wrapped: conflict: CHapticTrack]
// sym: ??0CHapticTrack@fn_0005d230@@QAE@XZ
namespace fn_0005d230 {
class CTrack_5d230 {
  public:
    CTrack_5d230();
    virtual hulk_intptr Fn_0005d190(int);
};

class CHapticTrack : public CTrack_5d230 {
  public:
    CHapticTrack();
    virtual bool Fn0_00234270(void*);
    virtual bool Fn1_002342b0(int);
    virtual bool Fn2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool Fn3_00234350(int, int);

  private:
    char pad[4];
    int m0x8;
    int m0xc;
    float m0x10;
    int m0x14;
    int m0x18;
    char m0x1c;
};

CHapticTrack::CHapticTrack() {
    m0xc = 0;
    m0x14 = 0;
    m0x18 = 0;
    m0x1c = 0;
    m0x10 = -1.0f;
    m0x8 = 1;
}
} // namespace fn_0005d230


// 0x0005d260 CHapticTrack::vfunc_5 (36 B): matches/0x0005d260.cpp [wrapped: conflict: CHapticTrack; CTrack]
// sym: ?vfunc_5@CHapticTrack@fn_0005d260@@QAEPAV12@C@Z
namespace fn_0005d260 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fa034[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CHapticTrack : public CTrack {
  public:
    CHapticTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CHapticTrack* CHapticTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fa034;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_0005d260


// 0x0005d2b0 fight::ParamFloatConstRange<CHapticTrack>::vfunc_6 (26 B): matches/0x0005d2b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCHapticTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CHapticTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CHapticTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CHapticTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CHapticTrack>::**)(int))&this->f_10))(b);
}


// 0x0005d2d0 fight::ParamFloatConstRange<CHapticTrack>::vfunc_2 (11 B): matches/0x0005d2d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCHapticTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CHapticTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005d300 fight::ParamBool<CHapticTrack>::vfunc_6 (26 B): matches/0x0005d300.cpp
// sym: ?vfunc_6@?$ParamBool@VCHapticTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CHapticTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CHapticTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CHapticTrack>*)a)->*(*(bool (fight::ParamBool<CHapticTrack>::**)(int))&this->f_10))(b);
}


// 0x0005d320 fight::ParamBool<CHapticTrack>::vfunc_2 (11 B): matches/0x0005d320.cpp
// sym: ?vfunc_2@?$ParamBool@VCHapticTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CHapticTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005d330 fight::ParamFloatConstRange<CHapticTrack>::vfunc_0 (30 B): matches/0x0005d330.cpp
// sym: ??_G?$ParamFloatConstRange@VCHapticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CHapticTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CHapticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5d330)
#endif


// 0x0005d350 fight::ParamBool<CHapticTrack>::vfunc_0 (30 B): matches/0x0005d350.cpp
// sym: ??_G?$ParamBool@VCHapticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CHapticTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CHapticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5d350)
#endif

