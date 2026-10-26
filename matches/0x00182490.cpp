#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Helper_182490 {
    Helper_182490* first();
    char* second();
};

bool hulkfight::motion::PropThrowAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(Helper_182490 * *)&this->f_20))
        return false;
    Helper_182490* p = (*(Helper_182490 * *)&this->f_20)->first();
    *(p->second() + 0x1f51) = 1;
    return true;
}
