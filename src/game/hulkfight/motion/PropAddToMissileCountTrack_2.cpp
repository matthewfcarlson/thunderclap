// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001863c0..0x00186460 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToMissileCountTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1c58330 {
#define TREE_TU_END }
namespace fn_f1c58330 {} using namespace fn_f1c58330;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1c58330 {
class CStageCondition_1863e0;
class ParamValue_1863e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1863e0 : public ParamValue_1863e0 {
  public:
    int pad;
};
class CStageCondition_186430;
class ParamValue_186430 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186430 : public ParamValue_186430 {
  public:
    int pad;
};

} // namespace fn_f1c58330

// 0x001863c0 fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_6 (26 B): matches/0x001863c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::**)(int))&this->f_10))(b);
}


// 0x001863e0 fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_2 (11 B): matches/0x001863e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186410 fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_6 (26 B): matches/0x00186410.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::**)(int))&this->f_10))(b);
}


// 0x00186430 fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_2 (11 B): matches/0x00186430.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_2() {
    return this->f_10 == 0;
}

