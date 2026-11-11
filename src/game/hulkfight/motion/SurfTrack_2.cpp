// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001786d0..0x00178770 (kind game, layer game, confidence high), dominant class hulkfight::motion::SurfTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3c55caa {
#define TREE_TU_END }
namespace fn_f3c55caa {} using namespace fn_f3c55caa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3c55caa {
class CStageCondition_1786f0;
class ParamValue_1786f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1786f0 : public ParamValue_1786f0 {
  public:
    int pad;
};
class CStageCondition_178740;
class ParamValue_178740 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178740 : public ParamValue_178740 {
  public:
    int pad;
};

} // namespace fn_f3c55caa

// 0x001786d0 fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::vfunc_6 (26 B): matches/0x001786d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::**)(int))&this->f_10))(b);
}


// 0x001786f0 fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::vfunc_2 (11 B): matches/0x001786f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178720 fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::vfunc_6 (26 B): matches/0x00178720.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::SurfTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::**)(int))&this->f_10))(b);
}


// 0x00178740 fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::vfunc_2 (11 B): matches/0x00178740.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VSurfTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SurfTrack>::vfunc_2() {
    return this->f_10 == 0;
}

