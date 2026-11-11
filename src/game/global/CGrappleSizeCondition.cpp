// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f800..0x0004f880 (kind game, layer game, confidence high), dominant class CGrappleSizeCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f63788fb {
#define TREE_TU_END }
namespace fn_f63788fb {} using namespace fn_f63788fb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f63788fb {
struct CAxisArcCondition_4f800;
class CStageCondition_4f810 {};
class ParamValue_4f810 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f810 : public ParamValue_4f810 {
  public:
    virtual void f();
};

} // namespace fn_f63788fb

// 0x0004f800 fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_7 (6 B): matches/0x0004f800.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCGrappleSizeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f810 fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_6 (30 B): matches/0x0004f810.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCGrappleSizeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f810 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f810*)&DAT_003f335c));
}


// 0x0004f830 fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_8 (26 B): matches/0x0004f830.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCGrappleSizeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CGrappleSizeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CGrappleSizeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CGrappleSizeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f850 fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_2 (11 B): matches/0x0004f850.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCGrappleSizeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

