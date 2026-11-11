// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178b30..0x00178bd0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VisibilityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb555025 {
#define TREE_TU_END }
namespace fn_fb555025 {} using namespace fn_fb555025;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb555025 {
class CStageCondition_178b50;
class ParamValue_178b50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178b50 : public ParamValue_178b50 {
  public:
    int pad;
};
class CStageCondition_178ba0;
class ParamValue_178ba0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178ba0 : public ParamValue_178ba0 {
  public:
    int pad;
};

} // namespace fn_fb555025

// 0x00178b30 fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::vfunc_6 (26 B): matches/0x00178b30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVisibilityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::**)(int))&this->f_10))(b);
}


// 0x00178b50 fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::vfunc_2 (11 B): matches/0x00178b50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVisibilityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VisibilityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178b80 fight::ParamBool<hulkfight::motion::VisibilityTrack>::vfunc_6 (26 B): matches/0x00178b80.cpp
// sym: ?vfunc_6@?$ParamBool@VVisibilityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::VisibilityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::VisibilityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::VisibilityTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::VisibilityTrack>::**)(int))&this->f_10))(b);
}


// 0x00178ba0 fight::ParamBool<hulkfight::motion::VisibilityTrack>::vfunc_2 (11 B): matches/0x00178ba0.cpp
// sym: ?vfunc_2@?$ParamBool@VVisibilityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::VisibilityTrack>::vfunc_2() {
    return this->f_10 == 0;
}

