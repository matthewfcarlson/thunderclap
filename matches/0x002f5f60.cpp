class PhysicsObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual bool f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual float f31();
    char p10[12];
    class Helper* member;
    char p40[44];
    float factor;
    char p98[84];
    float result[3];
};
class Helper {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i(float*, float*, int);
};
float PhysicsObject::f31() {
    float t[3];
    if (f11()) {
        member->i(result, t, -1);
        return (t[1] * t[1] + t[0] * t[0] + t[2] * t[2]) * factor * 0.5f;
    }
    return 0.0f;
}