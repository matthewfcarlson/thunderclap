#include "gen/pure3d.h"

typedef unsigned int U_327660;
namespace pure3d {
class pddiPrimBufferStream_327660 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16(U_327660*, U_327660);
    virtual void f17();
};
struct d3dPrimBufferStream_nv_327660 {
    void helper();
};

} // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_16(int __p0, int __p1) { U_327660 * p = (U_327660 *)__p0; U_327660 v = (U_327660)__p1;

    U_327660* dst = (*(U_327660 * *)&this->f_24);
    dst[0] = p[0];
    dst[1] = p[1];
    dst[2] = p[2];
    *(*(U_327660 * *)&this->f_30) = v;
    ((d3dPrimBufferStream_nv_327660*)this)->helper();
}
