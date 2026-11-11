// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c8f0..0x0006ca70 (kind game, layer game, confidence high), dominant class CCameraDramaticTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fee2dbba {
#define TREE_TU_END }
namespace fn_fee2dbba {} using namespace fn_fee2dbba;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fee2dbba {
class CStageCondition_6c910;
class ParamValue_6c910 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c910 : public ParamValue_6c910 {
  public:
    int pad;
};
class CStageCondition_6c960;
class ParamValue_6c960 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c960 : public ParamValue_6c960 {
  public:
    int pad;
};
class CStageCondition_6c9b0;
class ParamValue_6c9b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c9b0 : public ParamValue_6c9b0 {
  public:
    int pad;
};
struct CAxisArcCondition_6c9f0;
class CStageCondition_6ca00 {};
class ParamValue_6ca00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_6ca00 : public ParamValue_6ca00 {
  public:
    virtual void f();
};

} // namespace fn_fee2dbba

// 0x0006c8f0 fight::ParamFloatConstRange<CCameraDramaticTrack>::vfunc_6 (26 B): matches/0x0006c8f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCameraDramaticTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCameraDramaticTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCameraDramaticTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCameraDramaticTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CCameraDramaticTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c910 fight::ParamFloatConstRange<CCameraDramaticTrack>::vfunc_2 (11 B): matches/0x0006c910.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCameraDramaticTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCameraDramaticTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c940 fight::ParamVector<CCameraDramaticTrack>::vfunc_6 (26 B): matches/0x0006c940.cpp
// sym: ?vfunc_6@?$ParamVector@VCCameraDramaticTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CCameraDramaticTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CCameraDramaticTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CCameraDramaticTrack>*)a)->*(*(bool (fight::ParamVector<CCameraDramaticTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c960 fight::ParamVector<CCameraDramaticTrack>::vfunc_2 (11 B): matches/0x0006c960.cpp
// sym: ?vfunc_2@?$ParamVector@VCCameraDramaticTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CCameraDramaticTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c990 fight::ParamBool<CCameraDramaticTrack>::vfunc_6 (26 B): matches/0x0006c990.cpp
// sym: ?vfunc_6@?$ParamBool@VCCameraDramaticTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CCameraDramaticTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CCameraDramaticTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CCameraDramaticTrack>*)a)->*(*(bool (fight::ParamBool<CCameraDramaticTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c9b0 fight::ParamBool<CCameraDramaticTrack>::vfunc_2 (11 B): matches/0x0006c9b0.cpp
// sym: ?vfunc_2@?$ParamBool@VCCameraDramaticTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CCameraDramaticTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c9f0 fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_7 (6 B): matches/0x0006c9f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCameraDramaticTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0006ca00 fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_6 (30 B): matches/0x0006ca00.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCameraDramaticTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_6ca00 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_6ca00*)&DAT_003f335c));
}


// 0x0006ca20 fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_8 (26 B): matches/0x0006ca20.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCameraDramaticTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCameraDramaticTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCameraDramaticTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CCameraDramaticTrack>::**)(int))&this->f_18))(b);
}


// 0x0006ca40 fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_2 (11 B): matches/0x0006ca40.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCameraDramaticTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_2() {
    return this->f_18 == 0;
}

