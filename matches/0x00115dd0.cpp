#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class Obj {
  public:
    char* b();
};

bool hulkfight::ai::MotionStopAction::vfunc_5(hulk_intptr n, int ) {
    if (n == 0) {
        if (!(*(Obj * *)&this->f_20))
            return (bool)(0);
        char* p = ((Obj *)((owners::Object_592a0 *)((*(Obj * *)&this->f_20)))->FUN_000592a0())->b() + 0x1f58;
        *(int*)(p + 0x114) = 0;
        *(int*)(p + 0x110) = 0;
        *(int*)(p + 0x10c) = 0;
        *(int*)(p + 0x118) = 0;
    }
    return (bool)(1);
}
