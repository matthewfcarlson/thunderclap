#include "gen/core.h"

struct P_2742f0;
struct Sub_2742f0 {
    virtual void a();
    virtual void b();
};
struct Inner_2742f0 {
    void run(P_2742f0* p, int v);
};
struct P_2742f0 {
    int x;
    Sub_2742f0 s;
    int a;
    Inner_2742f0* i;
    int c;
    int d;
};

int core::FileCancelRequest::vfunc_1() {
    (*(P_2742f0 * *)&this->f_08)->i->run((*(P_2742f0 * *)&this->f_08), (*(P_2742f0 * *)&this->f_08)->c);
    (*(P_2742f0 * *)&this->f_08)->s.a();
    (*(P_2742f0 * *)&this->f_08)->d = 0;
    (*(P_2742f0 * *)&this->f_08)->s.b();
    return 1;
}
