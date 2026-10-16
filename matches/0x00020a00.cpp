#include "gen/global.h"

class A_20a00 {
  public:
    void* get();
};
class B_20a00 {
  public:
    void* next();
};
class D {
  public:
    void act(void*, int);
};
class Obj_20a00 {
  public:
    virtual void f0();
    virtual void f1();
};

void CHeadTrackerAction::vfunc_4() {
    B_20a00* b = (B_20a00*)(*(A_20a00 * *)&this->f_1c)->get();
    void* y = b->next();
    if (y) {
        ((D*)y)->act((*(void * *)&this->f_24), 0);
        if ((*(Obj_20a00 * *)&this->f_88)) {
            (*(Obj_20a00 * *)&this->f_88)->f1();
            (*(Obj_20a00 * *)&this->f_88) = 0;
        }
    }
}
