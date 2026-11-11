// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235170..0x00235220 (kind game, layer engine, confidence high), dominant class fight::ParamValueBranch
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd2c6ba9 {
#define TREE_TU_END }
namespace fn_fd2c6ba9 {} using namespace fn_fd2c6ba9;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fd2c6ba9 {
extern "C" char DAT_00427c68[];
struct Member_235170 {
    void Init_0027b0e0(const char*);
};
class Helper_2351c0 {
  public:
    void Process_00234090(int);
};
class ParamValueBranch {
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

} // namespace fn_fd2c6ba9

// 0x00235170 FUN_00235170 (34 B): matches/0x00235170.cpp
// sym: ?FUN_00235170@ParamValueBranch@fight@@QAEPAV12@PBD@Z
fight::ParamValueBranch* fight::ParamValueBranch::FUN_00235170(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_235170*)((char*)this + 8))->Init_0027b0e0(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427c68);
    return (fight::ParamValueBranch*)(this);
}


// 0x002351a0 fight::ParamValueBranch::vfunc_3 (29 B): matches/0x002351a0.cpp [wrapped: conflict: fight::ParamValueBranch]
// sym: ?vfunc_3@ParamValueBranch@fight@fn_002351a0@@UAEXHH@Z
namespace fn_002351a0 {
class Helper_2351a0 {
  public:
    void Process_00233fe0(int);
};
namespace fight { class ParamValueBranch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    virtual int Query(int);
    virtual void f7();
}; }
void fight::ParamValueBranch::vfunc_3(int a, int b) {
    hulk_intptr x = Query(a);
    if (x)
        ((Helper_2351a0*)x)->Process_00233fe0(b);
}
} // namespace fn_002351a0

namespace fn_fd2c6ba9 {

// 0x002351c0 fight::ParamValueBranch::vfunc_4 (29 B): matches/0x002351c0.cpp
// sym: ?vfunc_3@ParamValueBranch@fn_fd2c6ba9@@UAEXHH@Z
// Same code shape as 0x002351a0 (propagated; names are from that function)
void ParamValueBranch::vfunc_3(int a, int b) {
    hulk_intptr x = Query(a);
    if (x)
        ((Helper_2351c0*)x)->Process_00234090(b);
}

} // namespace fn_fd2c6ba9

// 0x002351e0 fight::ParamValueBranch::vfunc_5 (49 B): matches/0x002351e0.cpp [wrapped: conflict: fight::ParamValueBranch]
// sym: ?v5@ParamValueBranch@fight@fn_002351e0@@UAEDHHH@Z
namespace fn_002351e0 {
namespace fight {
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int, int, int);
    virtual void* v6(int);
    int pad;
    int a;
    int b;
};
} // namespace fight
class Result {
  public:
    char go_002340b0(int, int, int);
};
char fight::ParamValueBranch::v5(int x, int y, int z) {
    Result* p = (Result*)v6(x);
    if (p) {
        int first = a;
        int last = z;
        int second = b;
        return p->go_002340b0(first, second, last);
    }
    return 0;
}
} // namespace fn_002351e0

