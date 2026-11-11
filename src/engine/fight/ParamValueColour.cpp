// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234f10..0x00234fa0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueColour
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f433ff21 {
#define TREE_TU_END }
namespace fn_f433ff21 {} using namespace fn_f433ff21;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f433ff21 {
class ParamValue_234f10 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};

} // namespace fn_f433ff21

// 0x00234f10 fight::ParamValueColour::vfunc_1 (6 B): matches/0x00234f10.cpp
// sym: ?vfunc_1@ParamValueColour@fight@@UAEHXZ
int fight::ParamValueColour::vfunc_1() {
    return 8;
}


// 0x00234f20 fight::ParamValueColour::vfunc_5 (68 B): matches/0x00234f20.cpp [wrapped: conflict: fight::ParamValue; fight::ParamValueColour; fight::Reader]
// sym: ?v5@ParamValueColour@fight@fn_00234f20@@UAEDHHPAVReader@23@@Z
namespace fn_00234f20 {
namespace fight {
class Reader {
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
    virtual char f10(int, int, int*);
};
class ParamValue {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int, int, Reader*);
    virtual void v6(int, int);
    int unused;
    int a;
    int b;
};
class ParamValueColour : public ParamValue {
  public:
    virtual char v5(int, int, Reader*);
};
char ParamValueColour::v5(int x, int y, Reader* r) {
    int result;
    int aa = a;
    int bb = b;
    result = 0;
    char ok = r->f10(aa, bb, &result);
    if (ok)
        v6(x, result);
    return ok;
}
} // namespace fight
} // namespace fn_00234f20

