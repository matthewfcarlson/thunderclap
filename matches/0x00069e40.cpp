#include "compat/ptr.h"
#include "gen/global.h"

struct Helper_69e40 {
    int run(hulk_intptr, int, int);
};
extern "C" void* FUN_0008d690(int);

hulk_intptr CDamageTrack::vfunc_12(hulk_intptr x) {
    Helper_69e40* p = (Helper_69e40*)FUN_0008d690(0x28);
    if (p)
        return p->run(x, this->damage, this->damageMax);
    return 0;
}
