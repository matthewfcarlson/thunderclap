// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235220..0x002352d0 (kind game, layer engine, confidence high), dominant class fight::ParamValueConditionGroup
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fb539295 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb539295 {} using namespace fn_fb539295;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fb539295 {
extern void* hulk_at_004279fc[];
struct Sub_235220 {
    void Init_0027b0e0(int a) throw();
};
class ParamValueConditionGroup_235220 {
  public:
    void* vptr;
    char pad[4];
    Sub_235220 sub;
    ParamValueConditionGroup_235220(hulk_intptr a) throw();
};
class Helper_235250 {
  public:
    void Process_00236ee0(int);
};
namespace fight {
class ParamValueConditionGroup {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    virtual int Query(int);
    virtual void f7();
};
}
class Helper_235270 {
  public:
    void Process_00236f10(int);
};
class ParamValueConditionGroup_235270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    virtual int Query(int);
    virtual void f7();
};


// 0x00235220 FUN_00235220 (34 B): matches/0x00235220.cpp
// sym: ??0ParamValueConditionGroup_235220@fn_fb539295@@QAE@H@Z
ParamValueConditionGroup_235220::ParamValueConditionGroup_235220(hulk_intptr a) throw() {
    vptr = hulk_at_004279fc;
    sub.Init_0027b0e0(a);
    vptr = g_vt2;
}


// 0x00235250 fight::ParamValueConditionGroup::vfunc_3 (29 B): matches/0x00235250.cpp
// sym: ?vfunc_3@ParamValueConditionGroup@fight@fn_fb539295@@UAEXHH@Z
// Same code shape as 0x002351a0 (propagated; names are from that function)
void fight::ParamValueConditionGroup::vfunc_3(int a, int b) {
    hulk_intptr x = Query(a);
    if (x)
        ((Helper_235250*)x)->Process_00236ee0(b);
}


// 0x00235270 fight::ParamValueConditionGroup::vfunc_4 (29 B): matches/0x00235270.cpp
// sym: ?vfunc_3@ParamValueConditionGroup_235270@fn_fb539295@@UAEXHH@Z
// Same code shape as 0x002351a0 (propagated; names are from that function)
void ParamValueConditionGroup_235270::vfunc_3(int a, int b) {
    hulk_intptr x = Query(a);
    if (x)
        ((Helper_235270*)x)->Process_00236f10(b);
}

} // namespace fn_fb539295

// 0x00235290 fight::ParamValueConditionGroup::vfunc_5 (54 B): matches/0x00235290.cpp [wrapped: conflict: fight::ParamValueConditionGroup]
// sym: ?v5@ParamValueConditionGroup@fight@fn_00235290@@UAEDHHH@Z
namespace fn_00235290 {
class Result {
  public:
    char Work_00237160(int, int, int, int);
};
namespace fight {
class ParamValue {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int, int, int);
    virtual Result* v6(int);
    int base;
};
class ParamValueConditionGroup : public ParamValue {
  public:
    int a;
    int b;
    virtual char v5(int, int, int);
};
} // namespace fight
char fight::ParamValueConditionGroup::v5(int x, int y, int z) {
    Result* p = v6(x);
    if (p) {
        int q = z;
        int aa = a;
        int bb = b;
        return p->Work_00237160(aa, bb, y, q);
    }
    return 0;
}
} // namespace fn_00235290

