#include "gen/audio.h"

class Device_262ee0 {
  public:
    virtual void f0();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void f1(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual int Get();
};

void audio::HalRsdFileStream::vfunc_5(int amount) {
    int end = this->f_34;
    if (!end)
        end = (*(Device_262ee0 * *)&this->f_20)->Get();
    int off = (end - (*(int *)&this->f_2c)) + amount;
    (*(int *)&this->f_2c) = end - off;
    (*(Device_262ee0 * *)&this->f_20)->f1(this->f_30 + off);
}
