// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"
class CAction_1d0340 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_1d0340* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CScenarioManager_1d0340 : public CAction_1d0340 {
  public:
    CScenarioManager_1d0340* vfunc_2(unsigned char);
};
struct CScenarioManager_nv_1d0340 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(CScenarioManager_1d0340*);
CScenarioManager_1d0340* CScenarioManager_1d0340::vfunc_2(unsigned char param_2) {
    ((CScenarioManager_nv_1d0340*)(((CScenarioManager*)(this))))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}