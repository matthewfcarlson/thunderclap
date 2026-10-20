// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/physics.h"
class CAction_30e610 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_30e610* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CollisionAnalyser_30e610 : public CAction_30e610 {
  public:
    CollisionAnalyser_30e610* vfunc_2(unsigned char);
};
struct CollisionAnalyser_nv_30e610 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(CollisionAnalyser_30e610*);
CollisionAnalyser_30e610* CollisionAnalyser_30e610::vfunc_2(unsigned char param_2) {
    ((CollisionAnalyser_nv_30e610*)(((physics::CollisionAnalyser*)(this))))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}