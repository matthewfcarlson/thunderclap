// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c0e0..0x0006c1d0 (kind game, layer game, confidence high), dominant class CKeyPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc28dde3 {
#define TREE_TU_END }
namespace fn_fc28dde3 {} using namespace fn_fc28dde3;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc28dde3 {
class CStageCondition_6c100;
class ParamValue_6c100 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c100 : public ParamValue_6c100 {
  public:
    int pad;
};
class CStageCondition_6c150;
class ParamValue_6c150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c150 : public ParamValue_6c150 {
  public:
    int pad;
};
class CStageCondition_6c1a0;
class ParamValue_6c1a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c1a0 : public ParamValue_6c1a0 {
  public:
    int pad;
};

} // namespace fn_fc28dde3

// 0x0006c0e0 fight::ParamFloatConstRange<CKeyPoseTrack>::vfunc_6 (26 B): matches/0x0006c0e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCKeyPoseTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CKeyPoseTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CKeyPoseTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CKeyPoseTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CKeyPoseTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c100 fight::ParamFloatConstRange<CKeyPoseTrack>::vfunc_2 (11 B): matches/0x0006c100.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCKeyPoseTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CKeyPoseTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c130 fight::ParamBool<CKeyPoseTrack>::vfunc_6 (26 B): matches/0x0006c130.cpp
// sym: ?vfunc_6@?$ParamBool@VCKeyPoseTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CKeyPoseTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CKeyPoseTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CKeyPoseTrack>*)a)->*(*(bool (fight::ParamBool<CKeyPoseTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c150 fight::ParamBool<CKeyPoseTrack>::vfunc_2 (11 B): matches/0x0006c150.cpp
// sym: ?vfunc_2@?$ParamBool@VCKeyPoseTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CKeyPoseTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c180 fight::ParamIntConstRange<CKeyPoseTrack>::vfunc_6 (26 B): matches/0x0006c180.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCKeyPoseTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CKeyPoseTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CKeyPoseTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CKeyPoseTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CKeyPoseTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c1a0 fight::ParamIntConstRange<CKeyPoseTrack>::vfunc_2 (11 B): matches/0x0006c1a0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCKeyPoseTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CKeyPoseTrack>::vfunc_2() {
    return this->f_10 == 0;
}

