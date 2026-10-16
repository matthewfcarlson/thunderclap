#include "gen/pure3d.h"

namespace pure3d {

} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_75(void* __p0, void* __p1, void* __p2) { unsigned int * a = (unsigned int *)__p0; unsigned int * b = (unsigned int *)__p1; unsigned int * c = (unsigned int *)__p2;

    *a = *(unsigned*)((char*)(*(unsigned int * *)&this->f_58) + 0x18);
    *b = *(unsigned*)((char*)(*(unsigned int * *)&this->f_58) + 0x1c);
    *c = *(unsigned*)((char*)(*(unsigned int * *)&this->f_58) + 0x20);
}
