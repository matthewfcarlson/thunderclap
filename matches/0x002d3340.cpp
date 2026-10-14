struct Curve_2d3340 {
    void Fn(float, float*);
};
struct Elem_2d3340 {
    char pad[8];
    Curve_2d3340* c[3];
};
extern float __cdecl Mix(Curve_2d3340*, Curve_2d3340*, float, float);
class ParticlePointGenerator {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(float);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    char p4[12];
    unsigned char mode;
    char p11[7];
    float amount;
    unsigned int count;
    int index;
    char p24[8];
    Elem_2d3340** points;
    char p30[8];
    float out[3];
};
void ParticlePointGenerator::f(float arg) {
    if (!(count > 0))
        return;
    if (mode == 1) {
        Elem_2d3340** p = points + index;
        Elem_2d3340* a = p[0];
        Elem_2d3340* b = p[1];
        out[0] = Mix(a->c[0], b->c[0], amount, arg);
        out[1] = Mix(a->c[1], b->c[1], amount, arg);
        out[2] = Mix(a->c[2], b->c[2], amount, arg);
    } else {
        Elem_2d3340* p = points[index];
        p->c[0]->Fn(arg, &out[0]);
        p->c[1]->Fn(arg, &out[1]);
        p->c[2]->Fn(arg, &out[2]);
    }
}
