// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001857d0..0x00185960 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropActorToPropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4dd2180 {
#define TREE_TU_END }
namespace fn_f4dd2180 {} using namespace fn_f4dd2180;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4dd2180 {
class CStageCondition_1857f0;
class ParamValue_1857f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1857f0 : public ParamValue_1857f0 {
  public:
    int pad;
};
class CStageCondition_185840;
class ParamValue_185840 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185840 : public ParamValue_185840 {
  public:
    int pad;
};
class CStageCondition_185890;
class ParamValue_185890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185890 : public ParamValue_185890 {
  public:
    int pad;
};
class CStageCondition_1858e0;
class ParamValue_1858e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1858e0 : public ParamValue_1858e0 {
  public:
    int pad;
};
class CStageCondition_185930;
class ParamValue_185930 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185930 : public ParamValue_185930 {
  public:
    int pad;
};

} // namespace fn_f4dd2180

// 0x001857d0 fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_6 (26 B): matches/0x001857d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::**)(int))&this->f_10))(b);
}


// 0x001857f0 fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_2 (11 B): matches/0x001857f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185820 fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_6 (26 B): matches/0x00185820.cpp
// sym: ?vfunc_6@?$ParamBool@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::**)(int))&this->f_10))(b);
}


// 0x00185840 fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_2 (11 B): matches/0x00185840.cpp
// sym: ?vfunc_2@?$ParamBool@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185870 fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_6 (26 B): matches/0x00185870.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::**)(int))&this->f_10))(b);
}


// 0x00185890 fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_2 (11 B): matches/0x00185890.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001858c0 fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_6 (26 B): matches/0x001858c0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::**)(int))&this->f_10))(b);
}


// 0x001858e0 fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_2 (11 B): matches/0x001858e0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185910 fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::vfunc_6 (26 B): matches/0x00185910.cpp
// sym: ?vfunc_6@?$ParamBool@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropActorToPropTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::**)(int))&this->f_10))(b);
}


// 0x00185930 fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::vfunc_2 (11 B): matches/0x00185930.cpp
// sym: ?vfunc_2@?$ParamBool@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::vfunc_2() {
    return this->f_10 == 0;
}

