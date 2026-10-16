#include "gen/pure3d.h"

class Thing_32c300 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14(int, void*);
    virtual void a15(int);
};
struct Mat_32c300 {
    float x[16];
};

void pure3d::d3dReflShader::vfunc_12() {
    (*(Thing_32c300 * *)&this->f_10)->a15(2);
    Mat_32c300 m;
    m.x[0] = 0.5f;
    m.x[1] = 0;
    m.x[2] = 0;
    m.x[3] = 0;
    m.x[4] = 0;
    m.x[5] = 0.5f;
    m.x[6] = 0;
    m.x[7] = 0;
    m.x[8] = 0;
    m.x[9] = 0;
    m.x[10] = 1.0f;
    m.x[11] = 0;
    m.x[12] = 0.5f;
    m.x[13] = 0.5f;
    m.x[14] = 0;
    m.x[15] = 1.0f;
    (*(Thing_32c300 * *)&this->f_10)->a14(2, &m);
}
