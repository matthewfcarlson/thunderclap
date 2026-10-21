#include "compat/ptr.h"
struct Input_f6a70 {
    char p0[0x10];
    float angle;
    char p14[0xc4];
    float value;
};
struct Camera {
    char p[8];
    float value;
};
class Service_f6a70 {
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
    virtual void v14();
    virtual void v15();
    virtual float Get();
};
extern Service_f6a70* gService;
extern "C" double tan(double);
hulk_freg __cdecl Calc(Input_f6a70* a, Camera* b, void* c) {
    if (!a || !c)
        return 1.0f;
    float pad[4];
    float d = a->value;
    pad[3] = d;
    pad[0] = a->angle;
    float y = gService->Get();
    float z = b->value - pad[3];
    int bits = *(int*)&z;
    bits &= 0x7fffffff;
    z = *(float*)&bits;
    float r = (float)tan(pad[0] * 0.5f) / y;
    r = r * z;
    r = r + r;
    return r * 9.5238094e-05f;
}