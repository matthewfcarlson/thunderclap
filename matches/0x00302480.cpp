extern "C" double sqrt(double);
class VecSource {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual float* Get();
};
class Obj {
  public:
    char pad[0x34];
    float radius;
};
float dist(Obj* a, Obj* b) {
    float* p = ((VecSource*)a)->Get();
    float* q = ((VecSource*)b)->Get();
    float x = q[0] - p[0];
    float y = q[1] - p[1];
    float z = q[2] - p[2];
    return (float)sqrt(x * x + y * y + z * z) - (a->radius + b->radius);
}