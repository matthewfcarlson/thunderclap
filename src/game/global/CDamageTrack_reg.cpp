// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c6c0..0x0006c8f0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f93458d4 {
#define TREE_TU_END }
namespace fn_f93458d4 {} using namespace fn_f93458d4;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f93458d4 {
class CStageCondition_6c6e0;
class ParamValue_6c6e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c6e0 : public ParamValue_6c6e0 {
  public:
    int pad;
};
class CStageCondition_6c730;
class ParamValue_6c730 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c730 : public ParamValue_6c730 {
  public:
    int pad;
};
class ParamValueFloat_6c740 {
  public:
    virtual void f();
    ParamValueFloat_6c740(int);
    char pad[12];
};
class ParamFloatConstRange_06c740 : public ParamValueFloat_6c740 {
  public:
    virtual void f();
    int value;
    ParamFloatConstRange_06c740(int a, int b);
};
class CStageCondition_6c780;
class ParamValue_6c780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c780 : public ParamValue_6c780 {
  public:
    int pad;
};
class ParamValueFloat_6c790 {
  public:
    virtual void Fn();
    ParamValueFloat_6c790(float);
    char pad[12];
};
class ParamFloatConstRange_06c790 : public ParamValueFloat_6c790 {
  public:
    virtual void Fn();
    float val;
    ParamFloatConstRange_06c790(float a, float b);
};
class CStageCondition_6c7d0;
class ParamValue_6c7d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c7d0 : public ParamValue_6c7d0 {
  public:
    int pad;
};
class CStageCondition_6c820;
class ParamValue_6c820 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c820 : public ParamValue_6c820 {
  public:
    int pad;
};
class CStageCondition_6c870;
class ParamValue_6c870 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c870 : public ParamValue_6c870 {
  public:
    int pad;
};
class CStageCondition_6c8c0;
class ParamValue_6c8c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c8c0 : public ParamValue_6c8c0 {
  public:
    int pad;
};

} // namespace fn_f93458d4

// 0x0006c6c0 fight::ParamFloatConstRange<CDamageTrack>::vfunc_6 (26 B): matches/0x0006c6c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CDamageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c6e0 fight::ParamFloatConstRange<CDamageTrack>::vfunc_2 (11 B): matches/0x0006c6e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c710 fight::ParamFloatConstRange<CDrainHealthTrack>::vfunc_6 (26 B): matches/0x0006c710.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDrainHealthTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CDrainHealthTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CDrainHealthTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CDrainHealthTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c730 fight::ParamFloatConstRange<CDrainHealthTrack>::vfunc_2 (11 B): matches/0x0006c730.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDrainHealthTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f93458d4 {

// 0x0006c740 FUN_0006c740 (32 B): matches/0x0006c740.cpp
// sym: ??0ParamFloatConstRange_06c740@fn_f93458d4@@QAE@HH@Z
ParamFloatConstRange_06c740::ParamFloatConstRange_06c740(int a, int b) : ParamValueFloat_6c740(a), value(b) {}

} // namespace fn_f93458d4

// 0x0006c760 fight::ParamFloatConstRange<CComboTimerTrack>::vfunc_6 (26 B): matches/0x0006c760.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CComboTimerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CComboTimerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CComboTimerTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CComboTimerTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c780 fight::ParamFloatConstRange<CComboTimerTrack>::vfunc_2 (11 B): matches/0x0006c780.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CComboTimerTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f93458d4 {

// 0x0006c790 FUN_0006c790 (32 B): matches/0x0006c790.cpp
// sym: ??0ParamFloatConstRange_06c790@fn_f93458d4@@QAE@MM@Z
ParamFloatConstRange_06c790::ParamFloatConstRange_06c790(float a, float b) : ParamValueFloat_6c790(a) {
    val = b;
}

} // namespace fn_f93458d4

// 0x0006c7b0 fight::ParamFloatConstRange<CInvincibleTrack>::vfunc_6 (26 B): matches/0x0006c7b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CInvincibleTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CInvincibleTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CInvincibleTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CInvincibleTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c7d0 fight::ParamFloatConstRange<CInvincibleTrack>::vfunc_2 (11 B): matches/0x0006c7d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CInvincibleTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c800 fight::ParamFloatConstRange<CIntangibleTrack>::vfunc_6 (26 B): matches/0x0006c800.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CIntangibleTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CIntangibleTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CIntangibleTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CIntangibleTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c820 fight::ParamFloatConstRange<CIntangibleTrack>::vfunc_2 (11 B): matches/0x0006c820.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CIntangibleTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c850 fight::ParamFloatConstRange<CIntangibleToActorsTrack>::vfunc_6 (26 B): matches/0x0006c850.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CIntangibleToActorsTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CIntangibleToActorsTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CIntangibleToActorsTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CIntangibleToActorsTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c870 fight::ParamFloatConstRange<CIntangibleToActorsTrack>::vfunc_2 (11 B): matches/0x0006c870.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CIntangibleToActorsTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c8a0 fight::ParamFloatConstRange<CCameraShakeTrack>::vfunc_6 (26 B): matches/0x0006c8a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCameraShakeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCameraShakeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCameraShakeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CCameraShakeTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c8c0 fight::ParamFloatConstRange<CCameraShakeTrack>::vfunc_2 (11 B): matches/0x0006c8c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCDamageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCameraShakeTrack>::vfunc_2() {
    return this->f_10 == 0;
}

