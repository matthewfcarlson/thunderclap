// Same code shape as 0x0004df70 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<CGrappleSizeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CGrappleSizeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CGrappleSizeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CGrappleSizeCondition>::**)(int))&this->f_18))(b);
}
