#include "gen/pure3d.h"

class Base_3223a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(unsigned int);
    virtual void f7();
    virtual void f8();
};
struct Data_3223a0 {
    char pad[0x154];
    unsigned int field;
};
struct Inner_3223a0 {
    char pad[0x204];
    Data_3223a0* data;
};

void pure3d::d3dExtVertexProgram::vfunc_6(unsigned int x) {
    (*(Inner_3223a0 * *)&this->f_04)->data->field = x;
}
