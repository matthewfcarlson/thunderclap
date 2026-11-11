// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c1d0..0x0006c2c0 (kind game, layer game, confidence high), dominant class CSoundTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb2b5df9 {
#define TREE_TU_END }
namespace fn_fb2b5df9 {} using namespace fn_fb2b5df9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb2b5df9 {
class CStageCondition_6c1f0;
class ParamValue_6c1f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c1f0 : public ParamValue_6c1f0 {
  public:
    int pad;
};
class CStageCondition_6c240;
class ParamValue_6c240 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c240 : public ParamValue_6c240 {
  public:
    int pad;
};
class CStageCondition_6c290;
class ParamValue_6c290 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c290 : public ParamValue_6c290 {
  public:
    int pad;
};

} // namespace fn_fb2b5df9

// 0x0006c1d0 fight::ParamFloatConstRange<CSoundTrack>::vfunc_6 (26 B): matches/0x0006c1d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCSoundTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSoundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSoundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSoundTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSoundTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c1f0 fight::ParamFloatConstRange<CSoundTrack>::vfunc_2 (11 B): matches/0x0006c1f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCSoundTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSoundTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c220 fight::ParamString<CSoundTrack>::vfunc_6 (26 B): matches/0x0006c220.cpp
// sym: ?vfunc_6@?$ParamString@VCSoundTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<CSoundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CSoundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CSoundTrack>*)a)->*(*(bool (fight::ParamString<CSoundTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c240 fight::ParamString<CSoundTrack>::vfunc_2 (11 B): matches/0x0006c240.cpp
// sym: ?vfunc_2@?$ParamString@VCSoundTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<CSoundTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c270 fight::ParamBool<CSoundTrack>::vfunc_6 (26 B): matches/0x0006c270.cpp
// sym: ?vfunc_6@?$ParamBool@VCSoundTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSoundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSoundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSoundTrack>*)a)->*(*(bool (fight::ParamBool<CSoundTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c290 fight::ParamBool<CSoundTrack>::vfunc_2 (11 B): matches/0x0006c290.cpp
// sym: ?vfunc_2@?$ParamBool@VCSoundTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSoundTrack>::vfunc_2() {
    return this->f_10 == 0;
}

