// Same code shape as 0x002743f0 (propagated; names are from that function)
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
class Q_274480 {
  public:
    virtual void s0();
    virtual void s1();
};
class P_274480 {
  public:
    int pad0;
    Q_274480 q;
    int pad8;
    D* d;
    int pad10;
    int pad14;
    int f18;
};

int core::DriveOpenRequest::vfunc_1() {
    D* d = (*(P_274480 * *)&this->f_08)->d;
    int a = d->s7();
    int b = d->Helper();
    (*(P_274480 * *)&this->f_08)->q.s0();
    (*(P_274480 * *)&this->f_08)->f18 = b;
    (*(P_274480 * *)&this->f_08)->q.s1();
    return a;
}
