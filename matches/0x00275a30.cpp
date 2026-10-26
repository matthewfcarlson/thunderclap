#include "compat/ptr.h"
#include "decls/data/engine/core.h"
// data: globalG = DAT_0052a1e4

extern int vtDrive, vtRequest;
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
class Elem_275a30 {
  public:
    virtual void A();
    virtual void B();
};
class G_275a30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
namespace core { class DriveFindFirstRequest {
  public:
    virtual DriveFindFirstRequest* vfunc_0(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int pad;
    Elem_275a30* object;
}; }
core::DriveFindFirstRequest* core::DriveFindFirstRequest::vfunc_0(int flag) {
    ((hulk_intptr*)this)[0] = (hulk_intptr)&vtDrive;
    ((Elem_275a30*)((char*)object + 4))->A();
    --((int*)((char*)object))[5];
    ((Elem_275a30*)((char*)object + 4))->B();
    object->B();
    ((hulk_intptr*)this)[0] = (hulk_intptr)&vtRequest;
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(G_275a30**)&DAT_0052a1e4)->e(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}