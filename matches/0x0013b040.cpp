#include "gen/hulkfight.h"

class PhaseObj {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_13b040 {
  public:
    void* get();
    void* next();
    void act(void*, int);
};

void hulkfight::motion::AnimationPhaseMatchedAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* x = ((Helper_13b040*)(*(void * *)&this->f_20))->get();
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
