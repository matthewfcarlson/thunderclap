#include "gen/hulkfight.h"

class Obj {
  public:
    Obj* a();
    char* b();
};

bool hulkfight::ai::MotionStopAction::vfunc_5(int n, int ) {
    if (n == 0) {
        if (!(*(Obj * *)&this->f_20))
            return (bool)(0);
        char* p = (*(Obj * *)&this->f_20)->a()->b() + 0x1f58;
        *(int*)(p + 0x114) = 0;
        *(int*)(p + 0x110) = 0;
        *(int*)(p + 0x10c) = 0;
        *(int*)(p + 0x118) = 0;
    }
    return (bool)(1);
}
