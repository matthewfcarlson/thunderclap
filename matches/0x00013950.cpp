#include "compat/ptr.h"
#include "gen/global.h"

bool CAction::vfunc_5(hulk_intptr sel, int arg) {
    bool r = false;
    switch (sel) {
    case 0:
        r = vfunc_7(arg);
        break;
    case 1:
        r = vfunc_8(arg);
        break;
    }
    return r;
}
