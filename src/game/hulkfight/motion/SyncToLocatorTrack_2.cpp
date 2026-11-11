// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177bc0..0x00177da0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SyncToLocatorTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb7097ec {
#define TREE_TU_END }
namespace fn_fb7097ec {} using namespace fn_fb7097ec;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb7097ec {
class CStageCondition_177be0;
class ParamValue_177be0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177be0 : public ParamValue_177be0 {
  public:
    int pad;
};
typedef unsigned int u32_177c20;
struct C_177c20 {
    bool go(u32_177c20, u32_177c20);
};
class Param {
  public:
    char pad[0xc];
    hulk_uintptr fn; // holds a function pointer (read as *(Fn*)&fn)
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    bool vfunc_6(hulk_uintptr a, u32_177c20 b, u32_177c20 c);
};
class CStageCondition_177c40;
class ParamValue_177c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177c40 : public ParamValue_177c40 {
  public:
    int pad;
};
struct CAxisArcCondition_177c80;
class CStageCondition_177c90 {};
class ParamValue_177c90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_177c90 : public ParamValue_177c90 {
  public:
    virtual void f();
};
class CStageCondition_177d20;
class ParamValue_177d20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177d20 : public ParamValue_177d20 {
  public:
    int pad;
};
class CStageCondition_177d70;
class ParamValue_177d70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177d70 : public ParamValue_177d70 {
  public:
    int pad;
};

} // namespace fn_fb7097ec

// 0x00177bc0 fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_6 (26 B): matches/0x00177bc0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x00177be0 fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_2 (11 B): matches/0x00177be0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fb7097ec {

// 0x00177c10 fight::ParamValueScript::vfunc_1 (6 B): matches/0x00177c10.cpp
// sym: ?FUN_00177c10@fn_fb7097ec@@YAHXZ
// Same code shape as 0x0008c580 (propagated; names are from that function)
int FUN_00177c10() {
    return 5;
}


// 0x00177c20 fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>::vfunc_6 (31 B): matches/0x00177c20.cpp
// sym: ?vfunc_6@Param@fn_fb7097ec@@QAE_NIII@Z
bool Param::vfunc_6(hulk_uintptr a, u32_177c20 b, u32_177c20 c) {
    if (!fn)
        return false;
    typedef bool (C_177c20::*Fn)(u32_177c20, u32_177c20);
    Fn p = *(Fn*)&fn;
    return ((C_177c20*)a->*p)(b, c);
}

} // namespace fn_fb7097ec

// 0x00177c40 fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>::vfunc_2 (11 B): matches/0x00177c40.cpp
// sym: ?vfunc_2@?$ParamScript@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177c80 fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_7 (6 B): matches/0x00177c80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00177c90 fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_6 (30 B): matches/0x00177c90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_177c90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_177c90*)&DAT_003f335c));
}


// 0x00177cb0 fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_8 (26 B): matches/0x00177cb0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_18))(b);
}


// 0x00177cd0 fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_2 (11 B): matches/0x00177cd0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00177d00 fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::vfunc_6 (26 B): matches/0x00177d00.cpp
// sym: ?vfunc_6@?$ParamVector@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x00177d20 fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::vfunc_2 (11 B): matches/0x00177d20.cpp
// sym: ?vfunc_2@?$ParamVector@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177d50 fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_6 (26 B): matches/0x00177d50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x00177d70 fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_2 (11 B): matches/0x00177d70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VSyncToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}

