#include "gen/global.h"
#include "gen/owners.h"

class A_16cc0 {
  public:
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
};
extern "C" B_16cc0* __cdecl FUN_0027f250();

void CEffectStopAction::vfunc_4() {
    A2* q = ((A2 *)((owners::Object_592a0 *)((*(M_16cc0 * *)&this->f_1c)))->FUN_000592a0());
    A_16cc0* a = q->Second();
    B_16cc0* c = FUN_0027f250();
    int lo = (*(int * *)&this->f_20)[4];
    int hi = (*(int * *)&this->f_20)[5];
    if (lo < 0 || hi <= lo || hi >= 32) {
        int v = ((int)((owners::C_36c60 *)a)->FUN_00036c60((unsigned int)lo));
        c->Put(v);
        return;
    }
    while (lo <= hi) {
        int v = ((int)((owners::C_36c60 *)a)->FUN_00036c60((unsigned int)lo));
        c->Put(v);
        ++lo;
    }
}
