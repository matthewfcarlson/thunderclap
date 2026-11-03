#include "gen/owners.h"
extern unsigned char Work(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                          unsigned int, unsigned int);
unsigned char owners::Obj_38de0::FUN_00038de0(hulk_uintptr a, hulk_uintptr b, unsigned int c, unsigned int d, hulk_uintptr e,
                        hulk_uintptr f, hulk_uintptr g, hulk_uintptr h) {
    Lock(0);
    unsigned char r = Work(((unsigned int)a), ((unsigned int)b), c, d, ((unsigned int)e), ((unsigned int)f), ((unsigned int)g), ((unsigned int)h));
    Lock(1);
    return r;
}