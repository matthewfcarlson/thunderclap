#include "gen/audio.h"

class HalStream_263050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};
class Device_263050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int, unsigned, int);
};

void audio::HalRsdFileStream::vfunc_6(int a, int b, unsigned int n) {
    if (this->f_2c < n)
        this->f_3c = this->f_2c;
    else
        this->f_3c = n;
    if (this->f_3c > 0) {
        (*(Device_263050 * *)&this->f_20)->v3(a, this->f_3c, b);
        this->f_44 = 5;
        return;
    }
    this->f_44 = 6;
}
