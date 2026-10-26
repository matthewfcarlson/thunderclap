#include "decls/data/engine/choreo2.h"
// data: g_refCount = DAT_004e5aac

#include "compat/ptr.h"
extern "C" char DAT_004272f0[];
typedef unsigned char byte_224bb0;
namespace choreo2 {
class JointDriver {
  public:
    virtual void a();
    virtual void b();
    virtual JointDriver* vfunc_2(byte_224bb0);
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
};
} // namespace choreo2
class JointDriver_224bb0 {
  public:
    void call();
};
extern void thunk_FUN_00267090(choreo2::JointDriver*);
choreo2::JointDriver* choreo2::JointDriver::vfunc_2(byte_224bb0 param) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_004272f0);
    --(*(int*)&DAT_004e5aac);
    ((JointDriver_224bb0*)this)->call();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
