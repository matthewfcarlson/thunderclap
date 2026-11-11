// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169b10..0x00169c40 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6fda2c2 {
#define TREE_TU_END }
namespace fn_f6fda2c2 {} using namespace fn_f6fda2c2;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6fda2c2 {
class CStageCondition_169b30;
class ParamValue_169b30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169b30 : public ParamValue_169b30 {
  public:
    int pad;
};
struct CAxisArcCondition_169b70;
class CStageCondition_169b80 {};
class ParamValue_169b80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169b80 : public ParamValue_169b80 {
  public:
    virtual void f();
};
class CStageCondition_169c10;
class ParamValue_169c10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169c10 : public ParamValue_169c10 {
  public:
    int pad;
};

} // namespace fn_f6fda2c2

// 0x00169b10 fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::vfunc_6 (26 B): matches/0x00169b10.cpp
// sym: ?vfunc_6@?$ParamBool@VInLoadedRoomCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::**)(int))&this->f_10))(b);
}


// 0x00169b30 fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::vfunc_2 (11 B): matches/0x00169b30.cpp
// sym: ?vfunc_2@?$ParamBool@VInLoadedRoomCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169b70 fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_7 (6 B): matches/0x00169b70.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169b80 fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_6 (30 B): matches/0x00169b80.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169b80 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169b80*)&DAT_003f335c));
}


// 0x00169ba0 fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_8 (26 B): matches/0x00169ba0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VVelocityXZCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::**)(int))&this->f_18))(b);
}


// 0x00169bc0 fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_2 (11 B): matches/0x00169bc0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VVelocityXZCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169bf0 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::vfunc_6 (26 B): matches/0x00169bf0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVelocityXZCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::**)(int))&this->f_10))(b);
}


// 0x00169c10 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::vfunc_2 (11 B): matches/0x00169c10.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVelocityXZCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::vfunc_2() {
    return this->f_10 == 0;
}

