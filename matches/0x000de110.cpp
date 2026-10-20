// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"
class FEThingsBase_de110 {
  public:
    virtual void a();
    virtual void b();
    virtual FEThingsBase_de110* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class FEThings_de110 : public FEThingsBase_de110 {
  public:
    FEThings_de110* vfunc_2(unsigned char);
};
struct FEThings_nv_de110 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(FEThings_de110*);
FEThings_de110* FEThings_de110::vfunc_2(unsigned char param_2) {
    ((FEThings_nv_de110*)(((FEThings*)(this))))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}