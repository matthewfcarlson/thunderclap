// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274ba0..0x00274c30 (kind game, layer engine, confidence medium), dominant class core::CompletionEventRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f232f6a1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f232f6a1 {} using namespace fn_f232f6a1;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f232f6a1 {
extern "C" char DAT_0042b934[];
class Obj_274ba0 {
  public:
    virtual void A();
};
extern "C" int* FUN_002705f0();
struct CompletionEventRequest_274ba0 {
    const void* vf;
    void* next;
    hulk_uintptr* signal;
    Obj_274ba0* pC;
    CompletionEventRequest_274ba0* Init(hulk_uintptr*, Obj_274ba0*);
};
class Request {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Manager_274be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
extern int gCompletionVtable;
extern int gRequestVtable;
namespace core {
class CompletionEventRequest {
  public:
    int* vptr;
    char pad[8];
    Request* mRequest;
    void* vfunc_0(unsigned char);
};
}


// 0x00274ba0 FUN_00274ba0 (59 B): matches/0x00274ba0.cpp
// sym: ?Init@CompletionEventRequest_274ba0@fn_f232f6a1@@QAEPAU12@PAIPAVObj_274ba0@2@@Z
CompletionEventRequest_274ba0* CompletionEventRequest_274ba0::Init(hulk_uintptr* a, Obj_274ba0* b) {
    vf = DAT_0042b914;
    next = 0;
    FUN_002705f0();
    vf = DAT_0042b934;
    signal = a;
    pC = b;
    FUN_002705f0();
    pC->A();
    return this;
}


// 0x00274be0 core::CompletionEventRequest::vfunc_0 (74 B): matches/0x00274be0.cpp
// sym: ?vfunc_0@CompletionEventRequest@core@fn_f232f6a1@@QAEPAXE@Z
// data: gLock_274be0 = DAT_0052a1c8, gManager_274be0 = DAT_0052a1e4
void* core::CompletionEventRequest::vfunc_0(unsigned char param) {
    vptr = &gCompletionVtable;
    mRequest->f1();
    vptr = &gRequestVtable;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Manager_274be0**)&DAT_0052a1e4)->f4(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f232f6a1
