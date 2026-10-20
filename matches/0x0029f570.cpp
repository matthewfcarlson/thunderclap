// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"
class CAction_29f570 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_29f570* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CacheManager_29f570 : public CAction_29f570 {
  public:
    CacheManager_29f570* vfunc_2(unsigned char);
};
struct CacheManager_nv_29f570 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(CacheManager_29f570*);
CacheManager_29f570* CacheManager_29f570::vfunc_2(unsigned char param_2) {
    ((CacheManager_nv_29f570*)(((pure3d::LightsChooser::CacheManager*)(this))))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}