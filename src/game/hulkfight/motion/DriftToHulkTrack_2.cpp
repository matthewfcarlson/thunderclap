// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178150..0x001781f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToHulkTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f90553de {
#define TREE_TU_END }
namespace fn_f90553de {} using namespace fn_f90553de;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f90553de {
class CStageCondition_178170;
class ParamValue_178170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178170 : public ParamValue_178170 {
  public:
    int pad;
};
class CStageCondition_1781c0;
class ParamValue_1781c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1781c0 : public ParamValue_1781c0 {
  public:
    int pad;
};

} // namespace fn_f90553de

// 0x00178150 fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::vfunc_6 (26 B): matches/0x00178150.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::**)(int))&this->f_10))(b);
}


// 0x00178170 fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::vfunc_2 (11 B): matches/0x00178170.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::DriftToHulkTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001781a0 fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::vfunc_6 (26 B): matches/0x001781a0.cpp
// sym: ?vfunc_6@?$ParamVector@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::DriftToHulkTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::**)(int))&this->f_10))(b);
}


// 0x001781c0 fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::vfunc_2 (11 B): matches/0x001781c0.cpp
// sym: ?vfunc_2@?$ParamVector@VDriftToHulkTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::DriftToHulkTrack>::vfunc_2() {
    return this->f_10 == 0;
}

