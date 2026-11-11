// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001698a0..0x001699d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CharacterPropStatusCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f502e866 {
#define TREE_TU_END }
namespace fn_f502e866 {} using namespace fn_f502e866;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f502e866 {
class CStageCondition_1698c0;
class ParamValue_1698c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1698c0 : public ParamValue_1698c0 {
  public:
    int pad;
};
struct CAxisArcCondition_169900;
class CStageCondition_169910 {};
class ParamValue_169910 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169910 : public ParamValue_169910 {
  public:
    virtual void f();
};
class CStageCondition_1699a0;
class ParamValue_1699a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1699a0 : public ParamValue_1699a0 {
  public:
    int pad;
};

} // namespace fn_f502e866

// 0x001698a0 fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_6 (26 B): matches/0x001698a0.cpp
// sym: ?vfunc_6@?$ParamString@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::**)(int))&this->f_10))(b);
}


// 0x001698c0 fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_2 (11 B): matches/0x001698c0.cpp
// sym: ?vfunc_2@?$ParamString@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169900 fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_7 (6 B): matches/0x00169900.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169910 fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_6 (30 B): matches/0x00169910.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169910 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169910*)&DAT_003f335c));
}


// 0x00169930 fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_8 (26 B): matches/0x00169930.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::**)(int))&this->f_18))(b);
}


// 0x00169950 fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_2 (11 B): matches/0x00169950.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169980 fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::vfunc_6 (26 B): matches/0x00169980.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::**)(int))&this->f_10))(b);
}


// 0x001699a0 fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::vfunc_2 (11 B): matches/0x001699a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::vfunc_2() {
    return this->f_10 == 0;
}

