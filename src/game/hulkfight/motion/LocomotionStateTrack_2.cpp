// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177da0..0x00177ed0 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotionStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd27c887 {
#define TREE_TU_END }
namespace fn_fd27c887 {} using namespace fn_fd27c887;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd27c887 {
class CStageCondition_177dc0;
class ParamValue_177dc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177dc0 : public ParamValue_177dc0 {
  public:
    int pad;
};
class CStageCondition_177e10;
class ParamValue_177e10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177e10 : public ParamValue_177e10 {
  public:
    int pad;
};
struct CAxisArcCondition_177e50;
class CStageCondition_177e60 {};
class ParamValue_177e60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_177e60 : public ParamValue_177e60 {
  public:
    virtual void f();
};

} // namespace fn_fd27c887

// 0x00177da0 fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::vfunc_6 (26 B): matches/0x00177da0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSuckTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::**)(int))&this->f_10))(b);
}


// 0x00177dc0 fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::vfunc_2 (11 B): matches/0x00177dc0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSuckTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SuckTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177df0 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::vfunc_6 (26 B): matches/0x00177df0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSuckTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::**)(int))&this->f_10))(b);
}


// 0x00177e10 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::vfunc_2 (11 B): matches/0x00177e10.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSuckTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177e50 fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_7 (6 B): matches/0x00177e50.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00177e60 fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_6 (30 B): matches/0x00177e60.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_177e60 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_177e60*)&DAT_003f335c));
}


// 0x00177e80 fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_8 (26 B): matches/0x00177e80.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::**)(int))&this->f_18))(b);
}


// 0x00177ea0 fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_2 (11 B): matches/0x00177ea0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VLocomotionStateTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_2() {
    return this->f_18 == 0;
}

