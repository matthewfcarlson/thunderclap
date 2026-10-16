#include "gen/hulkfight.h"

class Service_13b380 {
  public:
    Service_13b380* get();
    Service_13b380* check();
    void run(void*, int, float);
};
struct Obj_13b380 {
    virtual void a();
    virtual void b();
};

void hulkfight::motion::AnimationLinkedAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        Service_13b380* x = (*(Service_13b380 * *)&this->f_20)->get();
        Service_13b380* y = x->check();
        if (y) {
            y->run((*(void * *)&this->f_24), 0, -1.0f);
            if ((*(void * *)&this->f_24)) {
                ((Obj_13b380*)(*(void * *)&this->f_24))->b();
                (*(void * *)&this->f_24) = 0;
            }
        }
    }
}
