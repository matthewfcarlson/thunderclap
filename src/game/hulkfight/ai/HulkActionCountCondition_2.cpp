// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001103e0..0x00110510 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionCountCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_feaa98fd {
#define TREE_TU_END }
namespace fn_feaa98fd {} using namespace fn_feaa98fd;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_feaa98fd {
struct CAxisArcCondition_1103e0;
class CStageCondition_1103f0 {};
class ParamValue_1103f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1103f0 : public ParamValue_1103f0 {
  public:
    virtual void f();
};
class CStageCondition_110480;
class ParamValue_110480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110480 : public ParamValue_110480 {
  public:
    int pad;
};
class CStageCondition_1104d0;
class ParamValue_1104d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1104d0 : public ParamValue_1104d0 {
  public:
    int pad;
};

} // namespace fn_feaa98fd

// 0x001103e0 fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_7 (6 B): matches/0x001103e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001103f0 fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_6 (30 B): matches/0x001103f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1103f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1103f0*)&DAT_003f335c));
}


// 0x00110410 fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_8 (26 B): matches/0x00110410.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::**)(int))&this->f_18))(b);
}


// 0x00110430 fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_2 (11 B): matches/0x00110430.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00110460 fight::ParamString<hulkfight::ai::HulkActionCountCondition>::vfunc_6 (26 B): matches/0x00110460.cpp
// sym: ?vfunc_6@?$ParamString@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::HulkActionCountCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::HulkActionCountCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::HulkActionCountCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::HulkActionCountCondition>::**)(int))&this->f_10))(b);
}


// 0x00110480 fight::ParamString<hulkfight::ai::HulkActionCountCondition>::vfunc_2 (11 B): matches/0x00110480.cpp
// sym: ?vfunc_2@?$ParamString@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::HulkActionCountCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001104b0 fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::vfunc_6 (26 B): matches/0x001104b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::**)(int))&this->f_10))(b);
}


// 0x001104d0 fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::vfunc_2 (11 B): matches/0x001104d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::vfunc_2() {
    return this->f_10 == 0;
}

