#include "compat/ptr.h"
#include "gen/fight.h"

extern int gState_23e5a0;
class Helper_23e5a0 {
  public:
    bool Check(int, int, int);
};
class Finisher {
  public:
    void Finish();
};
namespace fight {

} // namespace fight
bool fight::StopAction::vfunc_5(hulk_intptr value, int unused) {
    if (value == gState_23e5a0) {
        if (((char*)(*(Helper_23e5a0 * *)&this->f_20), ((Helper_23e5a0*)((char*)(*(Helper_23e5a0 * *)&this->f_20) + 0x14)))->Check(this->f_1c, this->f_28, 0)) {
            (*(Finisher * *)&this->f_24)->Finish();
            return false;
        }
    }
    return true;
}
