#include "gen/pure3d.h"

class pddiPrimBufferStream_3275c0 {
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
    virtual void f10(char, char, char, char);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
};

void pure3d::d3dPrimBufferStream::vfunc_10(char a, char b, char c, char d) {
    (*(unsigned char * *)&this->f_4c)[0] = c * 3;
    (*(unsigned char * *)&this->f_4c)[1] = b * 3;
    (*(unsigned char * *)&this->f_4c)[2] = a * 3;
    (*(unsigned char * *)&this->f_4c)[3] = d * 3;
}
