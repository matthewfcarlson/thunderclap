// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"
class CAction_c1f50 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_c1f50* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CFEManager_c1f50 : public CAction_c1f50 {
  public:
    CFEManager_c1f50* vfunc_2(unsigned char);
};
struct CFEManager_nv_c1f50 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(CFEManager_c1f50*);
CFEManager_c1f50* CFEManager_c1f50::vfunc_2(unsigned char param_2) {
    ((CFEManager_nv_c1f50*)(((CFEManager*)(this))))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}