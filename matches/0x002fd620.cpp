#include "gen/physics.h"

struct Inner_2fd620 {
    char pad[0x1fc];
    int* items;
};

unsigned int physics::SimStateArticulated::vfunc_9(unsigned int __p0) { int index = (int)__p0;

    Inner_2fd620* p = (*(Inner_2fd620 * *)&this->f_70);
    if (index > 0 && p != 0 && p->items[index] == 0)
        p = 0;
    return (unsigned int)((int)p);
}
