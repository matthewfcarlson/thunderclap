#include "compat/ptr.h"
struct V {
    float x, y, z;
};
class Shape_3023b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual V* Pos();
    virtual void a5();
    virtual int Type();
    char pad[0x30];
    float radius;
};
class Test_3023b0 {
  public:
    char pad[0xc];
    float margin;
    float pad2;
    V d;
    float pad3[3];
    float dist2;
    bool Check(Shape_3023b0* a, Shape_3023b0* b);
};
bool Test_3023b0::Check(Shape_3023b0* a, Shape_3023b0* b) {
    if (a->Type() == 8 || a->Type() == 1)
        return true;
    V* pb = b->Pos();
    V* pa = a->Pos();
    d.x = pa->x - pb->x;
    d.y = pa->y - pb->y;
    d.z = pa->z - pb->z;
    float* q = &dist2;
    volatile V* dv = &d;
    hulk_freg t = dv->z * dv->z + dv->y * dv->y;
    *q = t + dv->x * dv->x;
    if (*q < 1e-6f)
        return false;
    hulk_freg r = a->radius + b->radius + margin;
    return *q < r * r;
}