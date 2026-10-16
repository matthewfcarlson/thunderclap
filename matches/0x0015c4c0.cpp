#include "gen/hulkfight.h"

struct Data_15c4c0 {
    char pad[0x14];
    int a;
    int b;
    unsigned char c;
};

void hulkfight::motion::LocomotionStrafe4Action::vfunc_8(void* __p0, void* __p1, void* __p2) { int * p2 = (int *)__p0; int * p3 = (int *)__p1; unsigned char * p4 = (unsigned char *)__p2;

    *p2 = (*(Data_15c4c0 * *)&this->f_44)->a;
    *p3 = (*(Data_15c4c0 * *)&this->f_44)->b;
    *p4 = (*(Data_15c4c0 * *)&this->f_44)->c;
}
