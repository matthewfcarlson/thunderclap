// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169c40..0x00169d20 (kind game, layer game, confidence high), dominant class hulkfight::motion::RageModeStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5259df5 {
#define TREE_TU_END }
namespace fn_f5259df5 {} using namespace fn_f5259df5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5259df5 {
class CStageCondition_169c60;
class ParamValue_169c60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169c60 : public ParamValue_169c60 {
  public:
    int pad;
};
struct ParamValue_169ca0 {
    char pad[0x10];
};
struct ParamValueEnum_169ca0 : ParamValue_169ca0 {};
class CStageCondition_169cb0 {};
class ParamValue_169cb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169cb0 : public ParamValue_169cb0 {
  public:
    virtual void f();
};

} // namespace fn_f5259df5

// 0x00169c40 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_6 (26 B): matches/0x00169c40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVelocityAnimatedXZAngleCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x00169c60 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_2 (11 B): matches/0x00169c60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVelocityAnimatedXZAngleCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169ca0 fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_7 (6 B): matches/0x00169ca0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VRageModeStateCondition@motion@hulkfight@@@fight@@UAEHH@Z
template <> int fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169cb0 fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_6 (30 B): matches/0x00169cb0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VRageModeStateCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169cb0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169cb0*)&DAT_003f335c));
}


// 0x00169cd0 fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_8 (26 B): matches/0x00169cd0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VRageModeStateCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::**)(int))&this->f_18))(b);
}


// 0x00169cf0 fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_2 (11 B): matches/0x00169cf0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VRageModeStateCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}

