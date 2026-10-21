// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/movie.h"

class CAction_336f10 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_336f10* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
extern void FUN_00019420();
extern void thunk_FUN_00267090(movie::BinkCallback*);

void* movie::BinkCallback::vfunc_1_BinkCallback(unsigned char param_2) {
    FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return (void*)(this);
}
