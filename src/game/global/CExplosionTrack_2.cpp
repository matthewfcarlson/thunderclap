// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077f30..0x000783a0 (kind game, layer game, confidence high), dominant class CExplosionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fef3904b {
#define TREE_TU_END }
namespace fn_fef3904b {} using namespace fn_fef3904b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fef3904b {
extern int* hulk_at_004dd030;
class CCondition_77f30 {
  public:
    virtual int vfunc_0(int);
};
struct Param_77f70 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_77f70 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* __cdecl FUN_0008d690(unsigned int);
struct Helper_77f80 {
    unsigned int call_00021430(CHeliDeathSpiralTrack*, unsigned int);
};
extern int* hulk_at_004dd038;
class CCondition_77fd0 {
  public:
    virtual int vfunc_0(int);
};
class R_78050 {
  public:
    int invoke_000214d0(CExplosionTrack*, hulk_intptr);
};
extern R_78050* FUN_0008d690(int);
class CStageCondition_78170;
class ParamValue_78170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_78170 : public ParamValue_78170 {
  public:
    int pad;
};
class CStageCondition_781c0;
class ParamValue_781c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_781c0 : public ParamValue_781c0 {
  public:
    int pad;
};
class CStageCondition_78210;
class ParamValue_78210 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_78210 : public ParamValue_78210 {
  public:
    int pad;
};
struct CAxisArcCondition_78250;
class CStageCondition_78260 {};
class ParamValue_78260 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_78260 : public ParamValue_78260 {
  public:
    virtual void f();
};
class CStageCondition_782f0;
class ParamValue_782f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_782f0 : public ParamValue_782f0 {
  public:
    int pad;
};

} // namespace fn_fef3904b

// 0x00077f30 CHeliDeathSpiralTrack::vfunc_0 (16 B): matches/0x00077f30.cpp
// sym: ?vfunc_0@CHeliDeathSpiralTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CHeliDeathSpiralTrack::vfunc_0(int index) {
    int* p = hulk_at_004dd030;
    return p[index];
}


// 0x00077f50 CHeliDeathSpiralTrack::vfunc_13 (13 B): matches/0x00077f50.cpp
// sym: ?vfunc_13@CHeliDeathSpiralTrack@@UAEXPAX@Z
void CHeliDeathSpiralTrack::vfunc_13(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    *out = 0xff0f0f0f;
}


// 0x00077f60 CHeliDeathSpiralTrack::vfunc_6 (4 B): matches/0x00077f60.cpp
// sym: ?vfunc_6@CHeliDeathSpiralTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CHeliDeathSpiralTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00077f70 CHeliDeathSpiralTrack::vfunc_7 (7 B): matches/0x00077f70.cpp
// sym: ?vfunc_7@CHeliDeathSpiralTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CHeliDeathSpiralTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x00077f80 CHeliDeathSpiralTrack::vfunc_12 (40 B): matches/0x00077f80.cpp
// sym: ?vfunc_12@CHeliDeathSpiralTrack@@UAEHH@Z
hulk_intptr CHeliDeathSpiralTrack::vfunc_12(hulk_intptr __p0) { unsigned int x = (unsigned int)__p0;

    void* p = FUN_0008d690(0x48);
    if (p)
        return (int)(((Helper_77f80*)p)->call_00021430(this, x));
    return (int)(0);
}

namespace fn_fef3904b {

// 0x00077fb0 FUN_00077fb0 (19 B): matches/0x00077fb0.cpp
// sym: ?FUN_00077fb0@fn_fef3904b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00077fb0() {
    FUN_00234810(((char*)&DAT_004dd038), ((char*)&DAT_004dd03c));
}

} // namespace fn_fef3904b

// 0x00077fd0 CExplosionTrack::vfunc_0 (16 B): matches/0x00077fd0.cpp
// sym: ?vfunc_0@CExplosionTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CExplosionTrack::vfunc_0(int index) {
    int* p = hulk_at_004dd038;
    return p[index];
}


// 0x00077fe0 FUN_00077fe0 (35 B): matches/0x00077fe0.cpp [wrapped: conflict: CExplosionTrack]
// sym: ??0CExplosionTrack@fn_00077fe0@@QAE@XZ
namespace fn_00077fe0 {
extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class CTrack_77fe0 : public Base {
  public:
    CTrack_77fe0() : a(0), b(0) {}
    int a, b;
};
class CExplosionTrack : public CTrack_77fe0 {
  public:
    CExplosionTrack();
    int c, d, e;
    virtual void g() {}
};
CExplosionTrack::CExplosionTrack() : CTrack_77fe0() {
    _ReadWriteBarrier();
    c = 0;
    d = 0;
    e = 0;
}
} // namespace fn_00077fe0


// 0x00078010 CExplosionTrack::vfunc_13 (13 B): matches/0x00078010.cpp
// sym: ?vfunc_13@CExplosionTrack@@UAEXPAX@Z
void CExplosionTrack::vfunc_13(void* __p0) { unsigned int * param = (unsigned int *)__p0;

    *param = 0xffbfff00;
}


// 0x00078020 CExplosionTrack::vfunc_6 (4 B): matches/0x00078020.cpp
// sym: ?vfunc_6@CExplosionTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CExplosionTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00078030 CExplosionTrack::vfunc_7 (7 B): matches/0x00078030.cpp
// sym: ?vfunc_7@CExplosionTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CExplosionTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00078050 CExplosionTrack::vfunc_12 (40 B): matches/0x00078050.cpp
// sym: ?vfunc_12@CExplosionTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CExplosionTrack::vfunc_12(hulk_intptr param) {
    R_78050* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_000214d0(this, param);
    return 0;
}


// 0x00078080 FUN_00078080 (69 B): matches/0x00078080.cpp [wrapped: conflict: CHeliDeathSpiralTrack]
// sym: ??0CHeliDeathSpiralTrack@fn_00078080@@QAE@XZ
namespace fn_00078080 {
class CTrack_78080 {
  public:
    CTrack_78080();
    virtual void vf();
    char pad[4];
};
class CHeliDeathSpiralTrack : public CTrack_78080 {
  public:
    CHeliDeathSpiralTrack();
    virtual void vf();
    char p0[4];
    int a;
    float b, c;
    int d;
    float e;
    int f, g, h;
    int i, j;
    int k;
};
CHeliDeathSpiralTrack::CHeliDeathSpiralTrack()
    : a(0), b(-1.0f), c(0.5f), d(0), e(-0.017453292f), f(0), g(0), h(0), i(-5), j(0), k(0) {}
} // namespace fn_00078080


// 0x000780d0 CHeliDeathSpiralTrack::vfunc_5 (36 B): matches/0x000780d0.cpp [wrapped: conflict: CHeliDeathSpiralTrack; CTrack]
// sym: ?vfunc_5@CHeliDeathSpiralTrack@fn_000780d0@@QAEPAV12@C@Z
namespace fn_000780d0 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fed30[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CHeliDeathSpiralTrack : public CTrack {
  public:
    CHeliDeathSpiralTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CHeliDeathSpiralTrack* CHeliDeathSpiralTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fed30;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_000780d0


// 0x00078100 CExplosionTrack::vfunc_5 (36 B): matches/0x00078100.cpp [wrapped: conflict: CExplosionTrack; CTrack]
// sym: ?vfunc_5@CExplosionTrack@fn_00078100@@QAEPAV12@C@Z
namespace fn_00078100 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fed6c[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CExplosionTrack : public CTrack {
  public:
    CExplosionTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CExplosionTrack* CExplosionTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fed6c;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00078100


// 0x00078150 fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::vfunc_6 (26 B): matches/0x00078150.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCHeliDeathSpiralTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CHeliDeathSpiralTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::**)(int))&this->f_10))(b);
}


// 0x00078170 fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::vfunc_2 (11 B): matches/0x00078170.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCHeliDeathSpiralTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000781a0 fight::ParamIntConstRange<CHeliDeathSpiralTrack>::vfunc_6 (26 B): matches/0x000781a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCHeliDeathSpiralTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CHeliDeathSpiralTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CHeliDeathSpiralTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CHeliDeathSpiralTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CHeliDeathSpiralTrack>::**)(int))&this->f_10))(b);
}


// 0x000781c0 fight::ParamIntConstRange<CHeliDeathSpiralTrack>::vfunc_2 (11 B): matches/0x000781c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCHeliDeathSpiralTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CHeliDeathSpiralTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000781f0 fight::ParamFloatConstRange<CExplosionTrack>::vfunc_6 (26 B): matches/0x000781f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCHeliDeathSpiralTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CExplosionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CExplosionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CExplosionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CExplosionTrack>::**)(int))&this->f_10))(b);
}


// 0x00078210 fight::ParamFloatConstRange<CExplosionTrack>::vfunc_2 (11 B): matches/0x00078210.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCHeliDeathSpiralTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CExplosionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00078250 fight::ParamEnumConstList<CExplosionTrack>::vfunc_7 (6 B): matches/0x00078250.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCExplosionTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CExplosionTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00078260 fight::ParamEnumConstList<CExplosionTrack>::vfunc_6 (30 B): matches/0x00078260.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCExplosionTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CExplosionTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_78260 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_78260*)&DAT_003f335c));
}


// 0x00078280 fight::ParamEnumConstList<CExplosionTrack>::vfunc_8 (26 B): matches/0x00078280.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCExplosionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CExplosionTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CExplosionTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CExplosionTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CExplosionTrack>::**)(int))&this->f_18))(b);
}


// 0x000782a0 fight::ParamEnumConstList<CExplosionTrack>::vfunc_2 (11 B): matches/0x000782a0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCExplosionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CExplosionTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x000782d0 fight::ParamVector<CExplosionTrack>::vfunc_6 (26 B): matches/0x000782d0.cpp
// sym: ?vfunc_6@?$ParamVector@VCExplosionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CExplosionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CExplosionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CExplosionTrack>*)a)->*(*(bool (fight::ParamVector<CExplosionTrack>::**)(int))&this->f_10))(b);
}


// 0x000782f0 fight::ParamVector<CExplosionTrack>::vfunc_2 (11 B): matches/0x000782f0.cpp
// sym: ?vfunc_2@?$ParamVector@VCExplosionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CExplosionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00078300 fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::vfunc_0 (30 B): matches/0x00078300.cpp
// sym: ??_G?$ParamFloatConstRange@VCHeliDeathSpiralTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::~ParamFloatConstRange() {}


// 0x00078320 fight::ParamIntConstRange<CHeliDeathSpiralTrack>::vfunc_0 (30 B): matches/0x00078320.cpp
// sym: ??_G?$ParamIntConstRange@VCHeliDeathSpiralTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CHeliDeathSpiralTrack>::~ParamIntConstRange() {}


// 0x00078340 fight::ParamFloatConstRange<CExplosionTrack>::vfunc_0 (30 B): matches/0x00078340.cpp
// sym: ??_G?$ParamFloatConstRange@VCExplosionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CExplosionTrack>::~ParamFloatConstRange() {}


// 0x00078360 fight::ParamEnumConstList<CExplosionTrack>::vfunc_0 (30 B): matches/0x00078360.cpp
// sym: ??_G?$ParamEnumConstList@VCExplosionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CExplosionTrack>::~ParamEnumConstList() {}


// 0x00078380 fight::ParamVector<CExplosionTrack>::vfunc_0 (30 B): matches/0x00078380.cpp
// sym: ??_G?$ParamVector@VCExplosionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CExplosionTrack>::~ParamVector() {}

