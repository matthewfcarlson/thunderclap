#include "gen/global.h"

typedef unsigned char u8;
struct A_4a600 {
    void* f();
};
struct B_4a600 {
    void* f();
};
struct Manager_4a600 {
    char pad[0x1b28];
    int field;
};

bool CRageModeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    A_4a600* a = (A_4a600*)arg;
    void* p = a->f();
    B_4a600* b = (B_4a600*)p;
    Manager_4a600* q = (Manager_4a600*)b->f();
    bool r = q->field != 0;
    return r == this->f_0c;
}
