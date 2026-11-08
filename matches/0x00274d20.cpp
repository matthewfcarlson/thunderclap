#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: gLock_274d20 = DAT_0052a1c8, gObject_274d20 = DAT_0052a1e4
struct Obj_274d20 {
    virtual void f0();
    virtual void f1();
};
struct GlobalObj_274d20 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b954[];
extern "C" void FUN_0026d850(void*);
extern "C" void FUN_0026d840(void*);
// core::FileCompletionRequest's deleting destructor (records.h CoreCompletionRequest): releases the callback and
// the file; the memory goes back to the "FileRequest" pool
struct FileCompletionRequest_274d20 : CoreCompletionRequest {
    FileCompletionRequest_274d20* vfunc_0(unsigned char);
};
FileCompletionRequest_274d20* FileCompletionRequest_274d20::vfunc_0(unsigned char param) {
    vftable = DAT_0042b954;
    ((Obj_274d20*)callback)->f1();
    ((Obj_274d20*)file)->f1();
    vftable = DAT_0042b914;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(GlobalObj_274d20**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
