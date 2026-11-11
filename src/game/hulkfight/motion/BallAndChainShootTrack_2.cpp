// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186010..0x00186190 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainShootTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f28494cf {
#define TREE_TU_END }
namespace fn_f28494cf {} using namespace fn_f28494cf;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f28494cf {
class CStageCondition_186030;
class ParamValue_186030 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186030 : public ParamValue_186030 {
  public:
    int pad;
};
class CStageCondition_186080;
class ParamValue_186080 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186080 : public ParamValue_186080 {
  public:
    int pad;
};
class CStageCondition_1860d0;
class ParamValue_1860d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1860d0 : public ParamValue_1860d0 {
  public:
    int pad;
};
struct CAxisArcCondition_186110;
class CStageCondition_186120 {};
class ParamValue_186120 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_186120 : public ParamValue_186120 {
  public:
    virtual void f();
};

} // namespace fn_f28494cf

// 0x00186010 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_6 (26 B): matches/0x00186010.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_10))(b);
}


// 0x00186030 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_2 (11 B): matches/0x00186030.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186060 fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_6 (26 B): matches/0x00186060.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_10))(b);
}


// 0x00186080 fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_2 (11 B): matches/0x00186080.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001860b0 fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::vfunc_6 (26 B): matches/0x001860b0.cpp
// sym: ?vfunc_6@?$ParamVector@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_10))(b);
}


// 0x001860d0 fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::vfunc_2 (11 B): matches/0x001860d0.cpp
// sym: ?vfunc_2@?$ParamVector@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186110 fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_7 (6 B): matches/0x00186110.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00186120 fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_6 (30 B): matches/0x00186120.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_186120 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_186120*)&DAT_003f335c));
}


// 0x00186140 fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_8 (26 B): matches/0x00186140.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::**)(int))&this->f_18))(b);
}


// 0x00186160 fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_2 (11 B): matches/0x00186160.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_2() {
    return this->f_18 == 0;
}

