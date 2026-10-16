#include "gen/global.h"

class A_16cc0 {
  public:
    int Get(int);
};
class B_16cc0 {
  public:
    void Put(int);
};
class A2 {
  public:
    A_16cc0* Second();
};
class M_16cc0 {
  public:
    A2* First();
};
extern B_16cc0* __cdecl Make();

void CEffectStopAction::vfunc_4() {
    A2* q = (*(M_16cc0 * *)&this->f_1c)->First();
    A_16cc0* a = q->Second();
    B_16cc0* c = Make();
    int lo = (*(int * *)&this->f_20)[4];
    int hi = (*(int * *)&this->f_20)[5];
    if (lo < 0 || hi <= lo || hi >= 32) {
        int v = a->Get(lo);
        c->Put(v);
        return;
    }
    while (lo <= hi) {
        int v = a->Get(lo);
        c->Put(v);
        ++lo;
    }
}
