// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006cd10..0x0006cf00 (kind game, layer game, confidence high), dominant class CRageModeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc1047fa {
#define TREE_TU_END }
namespace fn_fc1047fa {} using namespace fn_fc1047fa;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc1047fa {
class ParamValueFloat_6cd10 {
  public:
    ParamValueFloat_6cd10(float);
    virtual void f();
};
} // namespace fn_fc1047fa
class CDriftTrack;
namespace fn_fc1047fa {
class Param {
  public:
    virtual void f();
};
class ParamFloatConstRange : public ParamValueFloat_6cd10 {
  public:
    ParamFloatConstRange(float, CDriftTrack*);
    virtual void f();
    char pad[12];
    CDriftTrack* track;
};
class CStageCondition_6cd50;
class ParamValue_6cd50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cd50 : public ParamValue_6cd50 {
  public:
    int pad;
};
class CStageCondition_6cda0;
class ParamValue_6cda0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cda0 : public ParamValue_6cda0 {
  public:
    int pad;
};
class CStageCondition_6cdf0;
class ParamValue_6cdf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cdf0 : public ParamValue_6cdf0 {
  public:
    int pad;
};
class CStageCondition_6ce40;
class ParamValue_6ce40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6ce40 : public ParamValue_6ce40 {
  public:
    int pad;
};
struct CAxisArcCondition_6ce80;
class CStageCondition_6ce90 {};
class ParamValue_6ce90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_6ce90 : public ParamValue_6ce90 {
  public:
    virtual void f();
};


// 0x0006cd10 FUN_0006cd10 (32 B): matches/0x0006cd10.cpp
// sym: ??0ParamFloatConstRange@fn_fc1047fa@@QAE@MPAVCDriftTrack@@@Z
ParamFloatConstRange::ParamFloatConstRange(float x, CDriftTrack* t) : ParamValueFloat_6cd10(x), track(t) {}

} // namespace fn_fc1047fa

// 0x0006cd30 fight::ParamFloatConstRange<CDriftTrack>::vfunc_6 (26 B): matches/0x0006cd30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDriftTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CDriftTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CDriftTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CDriftTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cd50 fight::ParamFloatConstRange<CDriftTrack>::vfunc_2 (11 B): matches/0x0006cd50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDriftTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cd80 fight::ParamFloatConstRange<CUninterruptibleTrack>::vfunc_6 (26 B): matches/0x0006cd80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CUninterruptibleTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CUninterruptibleTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CUninterruptibleTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CUninterruptibleTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cda0 fight::ParamFloatConstRange<CUninterruptibleTrack>::vfunc_2 (11 B): matches/0x0006cda0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CUninterruptibleTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cdd0 fight::ParamFloatConstRange<CInvulnerableTrack>::vfunc_6 (26 B): matches/0x0006cdd0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CInvulnerableTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CInvulnerableTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CInvulnerableTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CInvulnerableTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cdf0 fight::ParamFloatConstRange<CInvulnerableTrack>::vfunc_2 (11 B): matches/0x0006cdf0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CInvulnerableTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006ce20 fight::ParamFloatConstRange<CRageModeTrack>::vfunc_6 (26 B): matches/0x0006ce20.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CRageModeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CRageModeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CRageModeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CRageModeTrack>::**)(int))&this->f_10))(b);
}


// 0x0006ce40 fight::ParamFloatConstRange<CRageModeTrack>::vfunc_2 (11 B): matches/0x0006ce40.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDriftTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CRageModeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006ce80 fight::ParamEnumConstList<CRageModeTrack>::vfunc_7 (6 B): matches/0x0006ce80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCRageModeTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CRageModeTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0006ce90 fight::ParamEnumConstList<CRageModeTrack>::vfunc_6 (30 B): matches/0x0006ce90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCRageModeTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CRageModeTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_6ce90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_6ce90*)&DAT_003f335c));
}


// 0x0006ceb0 fight::ParamEnumConstList<CRageModeTrack>::vfunc_8 (26 B): matches/0x0006ceb0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCRageModeTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CRageModeTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CRageModeTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CRageModeTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CRageModeTrack>::**)(int))&this->f_18))(b);
}


// 0x0006ced0 fight::ParamEnumConstList<CRageModeTrack>::vfunc_2 (11 B): matches/0x0006ced0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCRageModeTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CRageModeTrack>::vfunc_2() {
    return this->f_18 == 0;
}

