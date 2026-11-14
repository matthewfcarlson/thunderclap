// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002348e0..0x00234960 (kind game, layer engine, confidence medium), dominant class fight::ParamValueInt
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter classes' real constructors
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7e8950c {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7e8950c {} using namespace fn_f7e8950c;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7e8950c {
extern "C" char DAT_00427a38[];
class ParamValue {
  public:
    ParamValue(int);
    virtual void F();
};
class ParamValueInt {
  public:
    virtual void* FnF_002352d0(int);
    char pad[4];
    ParamValue value;
    ParamValueInt(hulk_intptr);
};
namespace fight {
class Provider {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual char read(int, int, int*);
};
}
namespace fight {
class ParamValueInt {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char vfunc_5(int, int, Provider*);
    virtual void set(int, int);
    int pad;
    int x;
    int y;
};
}


} // namespace fn_f7e8950c

// 0x002348e0 FUN_002348e0 (34 B): matches/0x002348e0.cpp
// sym: ??0ParamValueInt@fight@@QAE@PBD@Z
// (gx2, D18) the constructor the parameter registrations call (`new ParamX<T>(name, setter)`)
::fight::ParamValueInt::ParamValueInt(const char* name) : ::fight::ParamValue(name) {}

namespace fn_f7e8950c {




// 0x00234910 fight::ParamValueInt::vfunc_5 (68 B): matches/0x00234910.cpp
// sym: ?vfunc_5@ParamValueInt@fight@fn_f7e8950c@@UAEDHHPAVProvider@23@@Z
namespace fight {
char ParamValueInt::vfunc_5(int a, int b, Provider* p) {
    int n = 0;
    int xx = x;
    int yy = y;
    char ok = p->read(xx, yy, &n);
    if (ok)
        set(a, n);
    return ok;
}
}

} // namespace fn_f7e8950c
