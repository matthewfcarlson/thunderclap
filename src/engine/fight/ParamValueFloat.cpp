// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234960..0x002349e0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueFloat
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f106b04d {
#define TREE_TU_END }
namespace fn_f106b04d {} using namespace fn_f106b04d;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f106b04d {
extern "C" char DAT_00427a58[];
struct Member_234960 {
    void Init_0027b0e0(const char*);
};

} // namespace fn_f106b04d

// 0x00234960 FUN_00234960 (34 B): matches/0x00234960.cpp
// sym: ?FUN_00234960@ParamValueFloat@fight@@QAEPAV12@PBD@Z
fight::ParamValueFloat* fight::ParamValueFloat::FUN_00234960(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234960*)((char*)this + 8))->Init_0027b0e0(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427a58);
    return (fight::ParamValueFloat*)(this);
}


// 0x00234990 fight::ParamValueFloat::vfunc_5 (68 B): matches/0x00234990.cpp [wrapped: conflict: fight::ParamValue; fight::ParamValueFloat]
// sym: ?f5@ParamValueFloat@fight@fn_00234990@@UAEDHHPAVSource@23@@Z
namespace fn_00234990 {
namespace fight {
class Source {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual char get(int, int, int*);
};
class ParamValue {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char f5(int, int, Source*);
    virtual void f6(int, int);
    int pad;
};
class ParamValueFloat : public ParamValue {
  public:
    int x;
    int y;
    virtual char f5(int, int, Source*);
};
char ParamValueFloat::f5(int a, int b, Source* src) {
    int xx = x;
    int yy = y;
    int value = 0;
    char ok = src->get(xx, yy, &value);
    if (ok)
        f6(a, value);
    return ok;
}
} // namespace fight
} // namespace fn_00234990

