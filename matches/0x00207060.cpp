// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"
class CAction_207060 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_207060* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CWorldStreamManager_207060 : public CAction_207060 {
  public:
    CWorldStreamManager_207060* vfunc_2(unsigned char);
};
struct CWorldStreamManager_nv_207060 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(CWorldStreamManager_207060*);
CWorldStreamManager_207060* CWorldStreamManager_207060::vfunc_2(unsigned char param_2) {
    ((CWorldStreamManager_nv_207060*)(((CWorldStreamManager*)(this))))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}