// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c3f0..0x0006c490 (kind game, layer game, confidence high), dominant class CMoveTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa9afe1d {
#define TREE_TU_END }
namespace fn_fa9afe1d {} using namespace fn_fa9afe1d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa9afe1d {
class CStageCondition_6c410;
class ParamValue_6c410 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c410 : public ParamValue_6c410 {
  public:
    int pad;
};
class ParamValueInt_6c420 {
  public:
    ParamValueInt_6c420(int a);
    virtual ~ParamValueInt_6c420();
};
class ParamIntConstRange_6c420 : public ParamValueInt_6c420 {
  public:
    ParamIntConstRange_6c420(int a, int b);
    virtual ~ParamIntConstRange_6c420();
    char pad[12];
    int mValue;
};
class CStageCondition_6c460;
class ParamValue_6c460 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c460 : public ParamValue_6c460 {
  public:
    int pad;
};

} // namespace fn_fa9afe1d

// 0x0006c3f0 fight::ParamFloatConstRange<CMoveTrack>::vfunc_6 (26 B): matches/0x0006c3f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMoveTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMoveTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMoveTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMoveTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMoveTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c410 fight::ParamFloatConstRange<CMoveTrack>::vfunc_2 (11 B): matches/0x0006c410.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMoveTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMoveTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fa9afe1d {

// 0x0006c420 FUN_0006c420 (32 B): matches/0x0006c420.cpp
// sym: ??0ParamIntConstRange_6c420@fn_fa9afe1d@@QAE@HH@Z
ParamIntConstRange_6c420::ParamIntConstRange_6c420(int a, int b) : ParamValueInt_6c420(a) {
    mValue = b;
}

} // namespace fn_fa9afe1d

// 0x0006c440 fight::ParamIntConstRange<CMoveTrack>::vfunc_6 (26 B): matches/0x0006c440.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCMoveTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CMoveTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CMoveTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CMoveTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CMoveTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c460 fight::ParamIntConstRange<CMoveTrack>::vfunc_2 (11 B): matches/0x0006c460.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCMoveTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CMoveTrack>::vfunc_2() {
    return this->f_10 == 0;
}

