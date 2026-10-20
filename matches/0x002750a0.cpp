#include "compat/ptr.h"
#include "decls/data/engine/core.h"

extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
class Inner_2750a0 {
  public:
    virtual void a();
    virtual void b();
};
class Root_2750a0 {
  public:
    virtual void a();
    virtual void b();
};
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
struct Manager_2750a0 {
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void q();
    virtual void add(void*);
};
extern Manager_2750a0* g_mgr_2750a0;
namespace core { class SaveGameOpenRequest {
  public:
    void* vt;
    int pad;
    Inner_2750a0* inner;
    SaveGameOpenRequest* vfunc_0(int flags);
}; }
core::SaveGameOpenRequest* core::SaveGameOpenRequest::vfunc_0(int flags) {
    Inner_2750a0* p = inner;
    *(void**)this = (void*)((hulk_intptr)DAT_0042b99c);
    ((Inner_2750a0*)((char*)p + 4))->a();
    --*(int*)((char*)inner + 0x18);
    ((Inner_2750a0*)((char*)inner + 4))->b();
    ((Root_2750a0*)inner)->b();
    *(void**)this = (void*)((hulk_intptr)DAT_0042b914);
    if (flags & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        g_mgr_2750a0->add(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}