#include "gen/core.h"

void core::ControllerInputPointXBox::vfunc_11(void* __p0, void* __p1) { unsigned long * a = (unsigned long *)__p0; unsigned long * b = (unsigned long *)__p1;

    if (a)
        *a = (*(unsigned long *)&this->f_0c);
    if (b)
        *b = (*(unsigned long *)&this->f_10);
}
