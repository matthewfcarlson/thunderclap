#include "compat/ptr.h"
typedef unsigned int uint_26fd80;
hulk_uintptr FUN_0026fd80(hulk_uintptr param_1, uint_26fd80 param_2) {
    if (param_2 != 0)
        param_1 = (param_1 / param_2) * param_2;
    return param_1;
}