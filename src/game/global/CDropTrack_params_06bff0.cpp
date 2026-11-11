// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006bff0..0x0006c0e0 (kind game, layer game, confidence high), dominant class CDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f22830b2 {
#define TREE_TU_END }
namespace fn_f22830b2 {} using namespace fn_f22830b2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f22830b2 {
class CStageCondition_6c010;
class ParamValue_6c010 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c010 : public ParamValue_6c010 {
  public:
    int pad;
};
class CStageCondition_6c060;
class ParamValue_6c060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c060 : public ParamValue_6c060 {
  public:
    int pad;
};
class CStageCondition_6c0b0;
class ParamValue_6c0b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c0b0 : public ParamValue_6c0b0 {
  public:
    int pad;
};

} // namespace fn_f22830b2

// 0x0006bff0 fight::ParamFloatConstRange<CDropTrack>::vfunc_6 (26 B): matches/0x0006bff0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDropTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CDropTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CDropTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c010 fight::ParamFloatConstRange<CDropTrack>::vfunc_2 (11 B): matches/0x0006c010.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDropTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c040 fight::ParamBool<CDropTrack>::vfunc_6 (26 B): matches/0x0006c040.cpp
// sym: ?vfunc_6@?$ParamBool@VCDropTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CDropTrack>*)a)->*(*(bool (fight::ParamBool<CDropTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c060 fight::ParamBool<CDropTrack>::vfunc_2 (11 B): matches/0x0006c060.cpp
// sym: ?vfunc_2@?$ParamBool@VCDropTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c090 fight::ParamIntConstRange<CDropTrack>::vfunc_6 (26 B): matches/0x0006c090.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCDropTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CDropTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CDropTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c0b0 fight::ParamIntConstRange<CDropTrack>::vfunc_2 (11 B): matches/0x0006c0b0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCDropTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}

