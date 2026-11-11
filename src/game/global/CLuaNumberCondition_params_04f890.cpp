// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f890..0x0004f9d0 (kind game, layer game, confidence high), dominant class CLuaNumberCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f45ce83c {
#define TREE_TU_END }
namespace fn_f45ce83c {} using namespace fn_f45ce83c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f45ce83c {
class CStageCondition_4f8b0;
class ParamValue_4f8b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f8b0 : public ParamValue_4f8b0 {
  public:
    int pad;
};
struct CAxisArcCondition_4f8f0;
class CStageCondition_4f900 {};
class ParamValue_4f900 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f900 : public ParamValue_4f900 {
  public:
    virtual void f();
};
class CStageCondition_4f990;
class ParamValue_4f990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f990 : public ParamValue_4f990 {
  public:
    int pad;
};

} // namespace fn_f45ce83c

// 0x0004f890 fight::ParamString<CLuaNumberCondition>::vfunc_6 (26 B): matches/0x0004f890.cpp
// sym: ?vfunc_6@?$ParamString@VCLuaNumberCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<CLuaNumberCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CLuaNumberCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CLuaNumberCondition>*)a)->*(*(bool (fight::ParamString<CLuaNumberCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f8b0 fight::ParamString<CLuaNumberCondition>::vfunc_2 (11 B): matches/0x0004f8b0.cpp
// sym: ?vfunc_2@?$ParamString@VCLuaNumberCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<CLuaNumberCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004f8f0 fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_7 (6 B): matches/0x0004f8f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCLuaNumberCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f900 fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_6 (30 B): matches/0x0004f900.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCLuaNumberCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f900 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f900*)&DAT_003f335c));
}


// 0x0004f920 fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_8 (26 B): matches/0x0004f920.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCLuaNumberCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CLuaNumberCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CLuaNumberCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CLuaNumberCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f940 fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_2 (11 B): matches/0x0004f940.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCLuaNumberCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CLuaNumberCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f970 fight::ParamFloatConstRange<CLuaNumberCondition>::vfunc_6 (26 B): matches/0x0004f970.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCLuaNumberCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CLuaNumberCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CLuaNumberCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CLuaNumberCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CLuaNumberCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f990 fight::ParamFloatConstRange<CLuaNumberCondition>::vfunc_2 (11 B): matches/0x0004f990.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCLuaNumberCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CLuaNumberCondition>::vfunc_2() {
    return this->f_10 == 0;
}

