#include "gen/hulkfight.h"

class Obj_136d60 {
  public:
    virtual void a();
    virtual void b();
    Obj_136d60* query();
    void act(void*, int);
};
class Source_136d60 {
  public:
    Obj_136d60* get();
};

void hulkfight::motion::AirToGroundTargetAction::vfunc_4() {
    Obj_136d60* x = (*(Source_136d60 * *)&this->f_20)->get();
    x = x->query();
    if (x) {
        x->act((*(void * *)&this->f_24), 0);
        if ((*(Obj_136d60 * *)&this->f_28)) {
            (*(Obj_136d60 * *)&this->f_28)->b();
            (*(Obj_136d60 * *)&this->f_28) = 0;
        }
    }
}
