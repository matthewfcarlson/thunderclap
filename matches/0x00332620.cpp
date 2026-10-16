#include "gen/pure3d.h"

class Dev_332620 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void SetTransform(int s, const float* m);
    virtual void SetState(int s);
};

void pure3d::d3dBuildingShader::vfunc_12() {
    (*(Dev_332620 * *)&this->f_10)->SetState(3);
    float m[16];
    m[0] = 0.5f;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0.5f;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1.0f;
    m[11] = 0;
    m[12] = 0.5f;
    m[13] = 0.5f;
    m[14] = 0;
    m[15] = 1.0f;
    (*(Dev_332620 * *)&this->f_10)->SetTransform(3, m);
}
