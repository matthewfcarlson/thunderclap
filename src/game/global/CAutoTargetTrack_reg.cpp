// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c5d0..0x0006c6c0 (kind game, layer game, confidence high), dominant class CAutoTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa2767a4 {
#define TREE_TU_END }
namespace fn_fa2767a4 {} using namespace fn_fa2767a4;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa2767a4 {
class CStageCondition_6c5f0;
class ParamValue_6c5f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c5f0 : public ParamValue_6c5f0 {
  public:
    int pad;
};
class ParamValueBool_6c600 {
  public:
    ParamValueBool_6c600(int);
    virtual void f();
    char pad[0x0c];
};
class ParamBool_6c600 : public ParamValueBool_6c600 {
  public:
    ParamBool_6c600(int a, int b);
    virtual void g();
    int m10;
};
class CStageCondition_6c640;
class ParamValue_6c640 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c640 : public ParamValue_6c640 {
  public:
    int pad;
};
class CStageCondition_6c690;
class ParamValue_6c690 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c690 : public ParamValue_6c690 {
  public:
    int pad;
};

} // namespace fn_fa2767a4

// 0x0006c5d0 fight::ParamFloatConstRange<CAutoTargetTrack>::vfunc_6 (26 B): matches/0x0006c5d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAutoTargetTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAutoTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAutoTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAutoTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CAutoTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c5f0 fight::ParamFloatConstRange<CAutoTargetTrack>::vfunc_2 (11 B): matches/0x0006c5f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAutoTargetTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fa2767a4 {

// 0x0006c600 FUN_0006c600 (32 B): matches/0x0006c600.cpp
// sym: ??0ParamBool_6c600@fn_fa2767a4@@QAE@HH@Z
ParamBool_6c600::ParamBool_6c600(int a, int b) : ParamValueBool_6c600(a) {
    *(void**)this = g_vftable;
    m10 = b;
}

} // namespace fn_fa2767a4

// 0x0006c620 fight::ParamBool<CAutoTargetTrack>::vfunc_6 (26 B): matches/0x0006c620.cpp
// sym: ?vfunc_6@?$ParamBool@VCAutoTargetTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CAutoTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CAutoTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CAutoTargetTrack>*)a)->*(*(bool (fight::ParamBool<CAutoTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c640 fight::ParamBool<CAutoTargetTrack>::vfunc_2 (11 B): matches/0x0006c640.cpp
// sym: ?vfunc_2@?$ParamBool@VCAutoTargetTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c670 fight::ParamIntConstRange<CAutoTargetTrack>::vfunc_6 (26 B): matches/0x0006c670.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCAutoTargetTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CAutoTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CAutoTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CAutoTargetTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CAutoTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c690 fight::ParamIntConstRange<CAutoTargetTrack>::vfunc_2 (11 B): matches/0x0006c690.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCAutoTargetTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}

