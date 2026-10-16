#include "gen/core.h"

float core::ControllerInputPointXBox::vfunc_9(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    if (p)
        *p = this->f_18;
    return (this->f_10 - this->f_0c) * this->f_08 + this->f_0c;
}
