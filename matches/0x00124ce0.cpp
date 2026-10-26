#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Helper_124ce0 {
  public:
    Helper_124ce0* Get();
    Helper_124ce0* Next();
    int Check();
    void Act();
};

bool hulkfight::ai::ClearProjectileDistanceAction::vfunc_5(hulk_intptr a, int b) {
    if (a != 0)
        return true;
    Helper_124ce0* x = (*(Helper_124ce0 * *)&this->f_20)->Get();
    x = x->Next();
    if ((*(char * *)&this->f_1c)[0x14] && x->Check())
        x->Act();
    return true;
}
