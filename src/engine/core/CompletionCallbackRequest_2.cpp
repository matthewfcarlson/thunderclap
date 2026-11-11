// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274c30..0x00274ca0 (kind game, layer engine, confidence medium), dominant class core::CompletionCallbackRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_fb5aa021 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb5aa021 {} using namespace fn_fb5aa021;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fb5aa021 {
void init();
class Request {
  public:
    hulk_intptr v;
    int a;
    int b;
};
class CompletionCallbackRequest : public Request {
  public:
    CompletionCallbackRequest(int arg);
};
struct Manager_274c60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
namespace core {
struct CompletionCallbackRequest {
    void** vt;
    CompletionCallbackRequest* vfunc_0(unsigned char);
};
}


// 0x00274c30 FUN_00274c30 (45 B): matches/0x00274c30.cpp
// sym: ??0CompletionCallbackRequest@fn_fb5aa021@@QAE@H@Z
CompletionCallbackRequest::CompletionCallbackRequest(int arg) {
    v = ((hulk_intptr)DAT_0042b914);
    a = 0;
    init();
    v = ((hulk_intptr)DAT_0042b9dc);
    b = arg;
    init();
}


// 0x00274c60 core::CompletionCallbackRequest::vfunc_0 (60 B): matches/0x00274c60.cpp
// sym: ?vfunc_0@CompletionCallbackRequest@core@fn_fb5aa021@@QAEPAU123@E@Z
// Same code shape as 0x00274b60 (propagated; names are from that function)
// data: g_lock_274c60 = DAT_0052a1c8, g_manager_274c60 = DAT_0052a1e4
core::CompletionCallbackRequest* core::CompletionCallbackRequest::vfunc_0(unsigned char param) {
    vt = request_vftable;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Manager_274c60**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_fb5aa021
