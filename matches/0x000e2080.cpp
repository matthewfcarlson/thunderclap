#include "gen/global.h"

struct Obj_e2080 {
    char pad[0x141];
    char a;
    char b;
};

int SingleLayout::vfunc_19() {
    Obj_e2080* p = (*(struct Obj_e2080 * *)&this->f_44);
    if (p && p->a && p->b)
        return 1;
    return 0;
}
