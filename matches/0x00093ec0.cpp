#include "gen/global.h"

class CUnlockablesManager_93ec0 {
  public:
    void Unlock(int, bool);
};
struct Args {
    int n;
    bool b;
};
class Function_93ec0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CUnlockablesManager_93ec0*, Args*, void*);
};

template <> void Method2<CUnlockablesManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_93ec0 * obj = (CUnlockablesManager_93ec0 *)__p0; Args * args = (Args *)__p1; void * result = (void *)__p2;

    (obj->*(*(void (CUnlockablesManager_93ec0::**)(int, bool))&this->f_1c))(args->n, args->b);
}
