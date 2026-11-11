// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e8b0..0x0004e930 (kind game, layer game, confidence high), dominant class CCollisionHitLocationCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3f94f7b {
#define TREE_TU_END }
namespace fn_f3f94f7b {} using namespace fn_f3f94f7b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3f94f7b {
struct CAxisArcCondition_4e8b0;
class CStageCondition_4e8c0 {};
class ParamValue_4e8c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e8c0 : public ParamValue_4e8c0 {
  public:
    virtual void f();
};

} // namespace fn_f3f94f7b

// 0x0004e8b0 fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_7 (6 B): matches/0x0004e8b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionHitLocationCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e8c0 fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_6 (30 B): matches/0x0004e8c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionHitLocationCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e8c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e8c0*)&DAT_003f335c));
}


// 0x0004e8e0 fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_8 (26 B): matches/0x0004e8e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionHitLocationCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionHitLocationCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionHitLocationCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionHitLocationCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e900 fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_2 (11 B): matches/0x0004e900.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionHitLocationCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionHitLocationCondition>::vfunc_2() {
    return this->f_18 == 0;
}

