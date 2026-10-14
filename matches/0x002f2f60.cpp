class Vec_2f2f60 {
  public:
    void normalize();
    float x, y, z;
};
class CollisionCylinder {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    char pad[0x4c];
    float x50, x54;
    char gap[0x18];
    Vec_2f2f60 v;
    float x7c, x80;
    void base(float);
    void vfunc_7(float);
};
extern const float one;
void CollisionCylinder::vfunc_7(float p) {
    x50 = p * x7c;
    x54 = p * x80;
    Vec_2f2f60* q = &v;
    q->normalize();
    float f = one / p;
    q->x = f * q->x;
    q->y = f * q->y;
    q->z = f * q->z;
    j();
    base(p);
}