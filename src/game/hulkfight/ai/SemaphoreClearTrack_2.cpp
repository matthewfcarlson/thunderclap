// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110840..0x00110910 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8b71ad1 {
#define TREE_TU_END }
namespace fn_f8b71ad1 {} using namespace fn_f8b71ad1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f8b71ad1 {
class CStageCondition_110860;
class ParamValue_110860 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110860 : public ParamValue_110860 {
  public:
    int pad;
};
class CStageCondition_1108e0;
class ParamValue_1108e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1108e0 : public ParamValue_1108e0 {
  public:
    int pad;
};

} // namespace fn_f8b71ad1

// 0x00110840 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::vfunc_6 (26 B): matches/0x00110840.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::**)(int))&this->f_10))(b);
}


// 0x00110860 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::vfunc_2 (11 B): matches/0x00110860.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f8b71ad1 {

// 0x00110890 fight::ParamName<hulkfight::ai::SemaphoreClearTrack>::vfunc_7 (12 B): matches/0x00110890.cpp
// sym: ?vfunc_6@ParamBranch@fn_f8b71ad1@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f8b71ad1

// 0x001108c0 fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::vfunc_6 (26 B): matches/0x001108c0.cpp
// sym: ?vfunc_6@?$ParamBool@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::**)(int))&this->f_10))(b);
}


// 0x001108e0 fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::vfunc_2 (11 B): matches/0x001108e0.cpp
// sym: ?vfunc_2@?$ParamBool@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}

