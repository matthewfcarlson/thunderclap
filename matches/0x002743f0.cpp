#include "gen/core.h"

class D {
  public:
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    int Helper();
};
class Q_2743f0 {
  public:
    virtual void s0();
    virtual void s1();
};
class P_2743f0 {
  public:
    int pad0;
    Q_2743f0 q;
    int pad8;
    D* d;
    int pad10;
    int pad14;
    int f18;
};

int core::DriveRequest::vfunc_4() {
    D* d = (*(P_2743f0 * *)&this->f_08)->d;
    int a = d->s7();
    int b = d->Helper();
    (*(P_2743f0 * *)&this->f_08)->q.s0();
    (*(P_2743f0 * *)&this->f_08)->f18 = b;
    (*(P_2743f0 * *)&this->f_08)->q.s1();
    return a;
}
