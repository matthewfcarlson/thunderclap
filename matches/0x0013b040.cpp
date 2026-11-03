#include "gen/hulkfight.h"
#include "gen/owners.h"

class PhaseObj {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_13b040 {
  public:
    void* next();
    void act(void*, int);
};

void hulkfight::motion::AnimationPhaseMatchedAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* x = ((void *)((owners::Object_592a0 *)(((Helper_13b040*)(*(void * *)&this->f_20))))->FUN_000592a0());
        x = ((Helper_13b040*)x)->next();
        if (x) {
            ((Helper_13b040*)x)->act((*(void * *)&this->f_24), 0);
            if ((*(void * *)&this->f_24)) {
                ((PhaseObj*)(*(void * *)&this->f_24))->f1();
                (*(void * *)&this->f_24) = 0;
            }
        }
    }
}
