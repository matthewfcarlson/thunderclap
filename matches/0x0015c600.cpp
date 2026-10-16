#include "gen/hulkfight.h"

class Obj_15c600 {
  public:
    Obj_15c600* first();
    Obj_15c600* second();
};
class Manager_15c600 {
  public:
    Obj_15c600* get();
};
class Setter_15c600 {
  public:
    void set(int, int, int);
};
class Fin {
  public:
    void finish(int);
};

void hulkfight::motion::LocomotionSteerAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        Obj_15c600* edi = ((Manager_15c600*)(*(void * *)&this->f_20))->get();
        Obj_15c600* p = edi->first();
        if (p) {
            ((Setter_15c600*)p)->set((int)(*(void * *)&this->f_24), 0, (int)0xbf800000);
            if (*((char*)(*(void * *)&this->f_1c) + 0x48)) {
                p = edi->second();
                if (p)
                    ((Fin*)p)->finish(0);
            }
        }
    }
}
