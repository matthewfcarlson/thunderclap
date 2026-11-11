// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185d10..0x00185e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2609e96 {
#define TREE_TU_END }
namespace fn_f2609e96 {} using namespace fn_f2609e96;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2609e96 {
class CStageCondition_185d30;
class ParamValue_185d30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185d30 : public ParamValue_185d30 {
  public:
    int pad;
};
class CStageCondition_185d80;
class ParamValue_185d80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185d80 : public ParamValue_185d80 {
  public:
    int pad;
};
class CStageCondition_185dd0;
class ParamValue_185dd0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185dd0 : public ParamValue_185dd0 {
  public:
    int pad;
};
class CStageCondition_185e20;
class ParamValue_185e20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185e20 : public ParamValue_185e20 {
  public:
    int pad;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};

} // namespace fn_f2609e96

// 0x00185d10 fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::vfunc_6 (26 B): matches/0x00185d10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00185d30 fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::vfunc_2 (11 B): matches/0x00185d30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185d60 fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::vfunc_6 (26 B): matches/0x00185d60.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00185d80 fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::vfunc_2 (11 B): matches/0x00185d80.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185db0 fight::ParamBool<hulkfight::motion::PropThrowTrack>::vfunc_6 (26 B): matches/0x00185db0.cpp
// sym: ?vfunc_6@?$ParamBool@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropThrowTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00185dd0 fight::ParamBool<hulkfight::motion::PropThrowTrack>::vfunc_2 (11 B): matches/0x00185dd0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185e00 fight::ParamVector<hulkfight::motion::PropThrowTrack>::vfunc_6 (26 B): matches/0x00185e00.cpp
// sym: ?vfunc_6@?$ParamVector@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::PropThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::PropThrowTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::PropThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00185e20 fight::ParamVector<hulkfight::motion::PropThrowTrack>::vfunc_2 (11 B): matches/0x00185e20.cpp
// sym: ?vfunc_2@?$ParamVector@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::PropThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f2609e96 {

// 0x00185e50 fight::ParamBranch<hulkfight::motion::PropThrowTrack>::vfunc_6 (12 B): matches/0x00185e50.cpp
// sym: ?vfunc_6@ParamBranch@fn_f2609e96@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f2609e96
