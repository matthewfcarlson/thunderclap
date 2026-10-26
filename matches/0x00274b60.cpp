#include "decls/data/engine/core.h"
// data: g_lock_274b60 = DAT_0052a1c8, g_manager_274b60 = DAT_0052a1e4

extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
struct Manager_274b60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern void* request_vftable[];
namespace core { struct Request {
    void** vt;
    Request* vfunc_0(unsigned char);
}; }
core::Request* core::Request::vfunc_0(unsigned char param) {
    vt = request_vftable;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Manager_274b60**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}