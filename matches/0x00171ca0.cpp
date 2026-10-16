#include "gen/hulkfight.h"

struct Vec_171ca0 {
    int x, y, z;
};
class Obj_171ca0 {
  public:
    Obj_171ca0* get();
    Obj_171ca0* next();
    void set(Vec_171ca0*);
};

bool hulkfight::motion::TeleportAction::vfunc_5(int a, int b) {
    if (!a) {
        if (!(*(Obj_171ca0 * *)&this->f_20))
            return (bool)(0);
        Obj_171ca0* p = (*(Obj_171ca0 * *)&this->f_20)->get()->next();
        Vec_171ca0 v = *(Vec_171ca0*)((*(char * *)&this->f_1c) + 0x10);
        p->set(&v);
    }
    return (bool)(1);
}
