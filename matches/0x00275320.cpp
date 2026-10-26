#include "decls/data/engine/core.h"
// data: g_lock_275320 = DAT_0052a1c8, g_mgr_275320 = DAT_0052a1e4

extern void* g_vftableA[];
extern void* g_vftableB[];
class Inner_275320 {
  public:
    virtual void a();
    virtual void b();
};
class Root_275320 {
  public:
    virtual void a();
    virtual void b();
};
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
struct Manager_275320 {
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void q();
    virtual void add(void*);
};
namespace core { class FileWriteRequest {
  public:
    void* vt;
    int pad;
    Inner_275320* inner;
    FileWriteRequest* vfunc_0(int flags);
}; }
core::FileWriteRequest* core::FileWriteRequest::vfunc_0(int flags) {
    Inner_275320* p = inner;
    vt = g_vftableA;
    ((Inner_275320*)((char*)p + 4))->a();
    --*(int*)((char*)inner + 0x18);
    ((Inner_275320*)((char*)inner + 4))->b();
    ((Root_275320*)inner)->b();
    vt = g_vftableB;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Manager_275320**)&DAT_0052a1e4)->add(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
