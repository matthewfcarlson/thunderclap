#include "compat/ptr.h"
#include "decls/data/engine/core.h"
// data: glob_275650 = DAT_0052a1e4

extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
typedef unsigned char byte_275650;
struct O_275650 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
    virtual void f();
    virtual void g();
};
struct T_275650 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[0x10];
    int count;
};
namespace core { struct DriveRequest {
    virtual DriveRequest* vfunc_0(byte_275650);
    char pad[4];
    T_275650* field8;
}; }
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
core::DriveRequest* core::DriveRequest::vfunc_0(byte_275650 flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042b9bc);
    ((O_275650*)((char*)field8 + 4))->a();
    field8->count--;
    ((O_275650*)((char*)field8 + 4))->b();
    ((O_275650*)field8)->b();
    *(void**)this = (void*)((hulk_intptr)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(O_275650**)&DAT_0052a1e4)->e(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}
