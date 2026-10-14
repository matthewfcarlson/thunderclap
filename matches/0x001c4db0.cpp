struct S_1c4db0 {
    unsigned int x[16];
};
class Object {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(unsigned int, unsigned int, unsigned int);
    virtual void g();
    virtual void h();
    virtual void i();
    char pad[0x2c];
    S_1c4db0 data;
};
void Object::f(unsigned int a, unsigned int b, unsigned int c) {
    S_1c4db0 t;
    t = data;
    t.x[12] = a;
    t.x[13] = b;
    t.x[14] = c;
    data = t;
}