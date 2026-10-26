#include "decls/data/engine/core.h"
// data: gLock_274d20 = DAT_0052a1c8, gObject_274d20 = DAT_0052a1e4

typedef unsigned char u8_274d20;
struct Obj_274d20 {
    virtual void f0();
    virtual void f1();
};
namespace core { struct FileCompletionRequest {
    virtual FileCompletionRequest* vfunc_0(u8_274d20);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[8];
    Obj_274d20* mAtC;
    Obj_274d20* mAt10;
}; }
struct GlobalObj_274d20 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(core::FileCompletionRequest*);
};
extern char vtFile[];
extern char vtRequest[];
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
core::FileCompletionRequest* core::FileCompletionRequest::vfunc_0(u8_274d20 param) {
    *(void**)this = vtFile;
    mAt10->f1();
    mAtC->f1();
    *(void**)this = vtRequest;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(GlobalObj_274d20**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}