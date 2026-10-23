#include "gen/fight.h"

int fight::ParamValueEntity::vfunc_9(int a, int b) {
    int count = vfunc_8(a);
    for (int i = 0; i < count; ++i)
        if (b == vfunc_7(a, i))
            return i;
    return -1;
}
