#include "compat/ptr.h"
#include "gen/global.h"

bool CMotionStateCondition::vfunc_7(void* __p0) { hulk_intptr p = (hulk_intptr)__p0;

    hulk_intptr result = vfunc_8(p);
    if (!result)
        return false;
    int expected = this->f_10;
    int op = this->f_0c;
    switch (op) {
    case 0:
        return *(int*)(result + 0x140) == expected;
    case 1:
        return *(int*)(result + 0x140) != expected;
    }
    return false;
}
