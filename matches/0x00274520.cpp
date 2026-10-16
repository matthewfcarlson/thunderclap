#include "gen/core.h"

struct Obj8_274520 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    unsigned int* Get();
};
struct Obj2_274520 {
    virtual void v0();
    virtual void v1();
};
struct Drive_274520 {
    int x;
    Obj2_274520 b;
    int pad;
    Obj8_274520* a;
    int pad2[2];
    int z;
};
struct Data_274520 {
    unsigned int v[21];
};

int core::DriveMediaRequest::vfunc_1() {
    Obj8_274520* a = (*(Drive_274520 * *)&this->f_08)->a;
    a->v7();
    Data_274520* p = (Data_274520*)a->Get();
    *(*(Data_274520 * *)&this->f_0c) = *p;
    (*(Drive_274520 * *)&this->f_08)->b.v0();
    (*(Drive_274520 * *)&this->f_08)->z = 0;
    (*(Drive_274520 * *)&this->f_08)->b.v1();
    return 1;
}
