#include "gen/global.h"
#include "gen/owners.h"

class Obj_175f0 {
  public:
    Obj_175f0* second();
    void m40(int);
    void mC0(int);
    void m20(void*);
    void mA0(void*);
};
class Factory_175f0 {
  public:
};

void CInvulnerableAction::vfunc_4() {
    Obj_175f0* x = ((Obj_175f0 *)((owners::Object_592a0 *)((*(Factory_175f0 * *)&this->f_1c)))->FUN_000592a0());
    Obj_175f0* s = x->second();
    s->m40(0);
    s->mC0(0);
    s->m20((*(void * *)&this->f_20));
    s->mA0((*(void * *)&this->f_20));
}
