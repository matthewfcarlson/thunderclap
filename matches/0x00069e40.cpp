#include "gen/global.h"

struct Helper_69e40 {
    int run(int, int, int);
};
extern void* FUN_0008d690(int);

int CDamageTrack::vfunc_12(int x) {
    Helper_69e40* p = (Helper_69e40*)FUN_0008d690(0x28);
    if (p)
        return p->run(x, this->f_10, this->f_14);
    return 0;
}
