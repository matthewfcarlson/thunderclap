// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273750..0x002737f0 (kind game, layer engine, confidence high), dominant class core::DriveCompletionRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f1ff819c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1ff819c {} using namespace fn_f1ff819c;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f1ff819c {
class Obj_273750 {
  public:
    virtual void f();
    virtual void g();
};
class DriveCompletionRequest_273750 {
  public:
    void** vt;
    char pad[8];
    Obj_273750* m0c;
    Obj_273750* m10;
    void Finish();
};
struct Callee_273780 {
    void Fnf_002728e0(core::DriveCompletionRequest*);
};
struct Inner_273780 {
    char pad[12];
    Callee_273780* callee;
};
class CompletionCallbackRequest_273780 {
  public:
    virtual void v0();
    virtual int v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
class V {
  public:
    virtual void f0();
    virtual void f1();
};
struct Obj_2737a0 {
    char pad[4];
    V sub;
    char pad2[12];
    int count;
};
class Q_2737a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
};


// 0x00273750 FUN_00273750 (33 B): matches/0x00273750.cpp
// sym: ?Finish@DriveCompletionRequest_273750@fn_f1ff819c@@QAEXXZ
// Same code shape as 0x002736b0 (propagated; names are from that function)
void DriveCompletionRequest_273750::Finish() {
    vt = &vFileCompletion;
    m10->g();
    m0c->g();
    vt = &vRequest;
}

} // namespace fn_f1ff819c

// 0x00273780 core::DriveCompletionRequest::vfunc_1 (18 B): matches/0x00273780.cpp
// sym: ?vfunc_1@DriveCompletionRequest@core@@UAEHXZ
// Same code shape as 0x002736e0 (propagated; names are from that function)
int core::DriveCompletionRequest::vfunc_1() {
    (*(Inner_273780 * *)&this->f_0c)->callee->Fnf_002728e0(this);
    return 3;
}


// 0x002737a0 core::DriveCompletionRequest::vfunc_7 (45 B): matches/0x002737a0.cpp
// sym: ?vfunc_7@DriveCompletionRequest@core@@UAEXXZ
void core::DriveCompletionRequest::vfunc_7() {
    (*(Obj_2737a0 * *)&this->f_0c)->sub.f0();
    --(*(Obj_2737a0 * *)&this->f_0c)->count;
    (*(Obj_2737a0 * *)&this->f_0c)->sub.f1();
    (*(Q_2737a0 * *)&this->f_10)->f3(this->f_14);
}


// 0x002737d0 core::DriveCompletionRequest::vfunc_3 (7 B): matches/0x002737d0.cpp
// sym: ?vfunc_3@DriveCompletionRequest@core@@UAEHXZ
// the request's drive: its file's (records.h CoreCompletionRequest, CoreFile provider)
hulk_intptr core::DriveCompletionRequest::vfunc_3() {
    return (hulk_intptr)((CoreFile*)((CoreCompletionRequest*)this)->file)->provider;
}


// 0x002737e0 core::DriveCompletionRequest::vfunc_6 (6 B): matches/0x002737e0.cpp
// sym: ?vfunc_6@DriveCompletionRequest@core@@UAEHXZ
int core::DriveCompletionRequest::vfunc_6() {
    return (int)(0x15);
}

