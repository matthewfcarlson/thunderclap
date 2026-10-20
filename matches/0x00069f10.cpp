#include "compat/ptr.h"
#include "gen/global.h"

extern const float zero_69f10;
class Helper_69f10 {
  public:
    int Apply(int, float);
};
extern int __cdecl FUN_0008d690(int);

int CDrainHealthTrack::vfunc_12(int arg) {
    float value = vfunc_7();
    if (!(value <= zero_69f10)) {
        float a = this->f_14;
        hulk_intptr obj = FUN_0008d690(0x24);
        if (obj)
            return ((Helper_69f10*)obj)->Apply(arg, a / value);
    }
    return 0;
}
