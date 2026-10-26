// Same code shape as 0x00274b60 (propagated; names are from that function)
#include "decls/data/engine/core.h"
// data: g_lock_274c60 = DAT_0052a1c8, g_manager_274c60 = DAT_0052a1e4

extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
struct Manager_274c60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern void* request_vftable[];
namespace core { struct CompletionCallbackRequest {
    void** vt;
    CompletionCallbackRequest* vfunc_0(unsigned char);
}; }
core::CompletionCallbackRequest* core::CompletionCallbackRequest::vfunc_0(unsigned char param) {
    vt = request_vftable;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Manager_274c60**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}