// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152e30..0x00152ff0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceNodeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3d4a067 {
#define TREE_TU_END }
namespace fn_f3d4a067 {} using namespace fn_f3d4a067;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3d4a067 {
class CStageCondition_152e50;
class ParamValue_152e50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152e50 : public ParamValue_152e50 {
  public:
    int pad;
};
class CStageCondition_152ea0;
class ParamValue_152ea0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152ea0 : public ParamValue_152ea0 {
  public:
    int pad;
};
struct CAxisArcCondition_152ee0;
class CStageCondition_152ef0 {};
class ParamValue_152ef0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152ef0 : public ParamValue_152ef0 {
  public:
    virtual void f();
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class ParamValueBool_152f70 {
  public:
    ParamValueBool_152f70(float f);
    virtual void V0();
    char pad[0xc];
};
class ParamBool_152f70 : public ParamValueBool_152f70 {
  public:
    ParamBool_152f70(float f, int x);
    virtual void V0();
    int m10;
};
class CStageCondition_152fb0;
class ParamValue_152fb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152fb0 : public ParamValue_152fb0 {
  public:
    int pad;
};

} // namespace fn_f3d4a067

// 0x00152e30 fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_6 (26 B): matches/0x00152e30.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::**)(int))&this->f_10))(b);
}


// 0x00152e50 fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_2 (11 B): matches/0x00152e50.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152e80 fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::vfunc_6 (26 B): matches/0x00152e80.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::**)(int))&this->f_10))(b);
}


// 0x00152ea0 fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::vfunc_2 (11 B): matches/0x00152ea0.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionExplosionCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152ee0 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_7 (6 B): matches/0x00152ee0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152ef0 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_6 (30 B): matches/0x00152ef0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152ef0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152ef0*)&DAT_003f335c));
}


// 0x00152f10 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_8 (26 B): matches/0x00152f10.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::**)(int))&this->f_18))(b);
}


// 0x00152f30 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_2 (11 B): matches/0x00152f30.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionSourceNodeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

namespace fn_f3d4a067 {

// 0x00152f60 fight::ParamBranch<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_6 (12 B): matches/0x00152f60.cpp
// sym: ?vfunc_6@ParamBranch@fn_f3d4a067@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}


// 0x00152f70 FUN_00152f70 (32 B): matches/0x00152f70.cpp
// sym: ??0ParamBool_152f70@fn_f3d4a067@@QAE@MH@Z
ParamBool_152f70::ParamBool_152f70(float f, int x) : ParamValueBool_152f70(f) {
    m10 = x;
}

} // namespace fn_f3d4a067

// 0x00152f90 fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_6 (26 B): matches/0x00152f90.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::**)(int))&this->f_10))(b);
}


// 0x00152fb0 fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_2 (11 B): matches/0x00152fb0.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

