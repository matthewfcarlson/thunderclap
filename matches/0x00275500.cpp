#include "compat/ptr.h"
#include "decls/data/engine/core.h"

extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
struct Owner_275500 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E(void*);
    virtual void F();
    virtual void G();
};
struct Inner_275500 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
};
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
extern Owner_275500* gObject_275500;
namespace core { struct FileGetSizeRequest {
    virtual FileGetSizeRequest* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[4];
    Owner_275500* owner;
}; }
core::FileGetSizeRequest* core::FileGetSizeRequest::vfunc_0(int flag) {
    ((hulk_intptr*)this)[0] = ((hulk_intptr)DAT_0042b99c);
    ((Inner_275500*)((char*)owner + 4))->A();
    --(*(int*)((char*)owner + 0x18));
    ((Inner_275500*)((char*)owner + 4))->B();
    owner->B();
    ((hulk_intptr*)this)[0] = ((hulk_intptr)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        gObject_275500->E(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}
