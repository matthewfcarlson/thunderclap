#include "gen/core.h"

class I_274a90 {
  public:
    virtual void f0();
    virtual void f1();
};
class M_274a90 {
  public:
    int dummy;
    void Call(void* a, int b);
};
class P_274a90 {
  public:
    char pad0[4];
    I_274a90 sub;
    char pad8[4];
    M_274a90* obj;
    int x10;
    char pad14[4];
    int zero;
};

int core::DriveCancelRequest::vfunc_1() {
    (*(P_274a90 * *)&this->f_08)->obj->Call((*(P_274a90 * *)&this->f_08), (*(P_274a90 * *)&this->f_08)->x10);
    (*(P_274a90 * *)&this->f_08)->sub.f0();
    (*(P_274a90 * *)&this->f_08)->zero = 0;
    (*(P_274a90 * *)&this->f_08)->sub.f1();
    return 1;
}
