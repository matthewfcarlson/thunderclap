struct Out_2f5ec0 {
    char pad[4];
    float a, b, c, d, e, f;
};
class Helper_2f5ec0 {
  public:
    void Transform(float*);
};
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20(float*, Out_2f5ec0*, int, int, int);
    char pad[0x44 - 4];
    float offset;
    char pad2[0x98 - 0x48];
    float x, y, z;
    char pad3[0x118 - 0xa4];
    unsigned int m0, m1, m2, m3, m4, m5;
};
void PhysicsObject::f20(float* p, Out_2f5ec0* out, int, int, int) {
    float t[3];
    t[0] = p[0] - x;
    t[1] = p[1] - y;
    t[2] = p[2] - z;
    out->a = *(float*)&m0;
    out->b = *(float*)&m1;
    out->c = *(float*)&m2;
    out->d = *(float*)&m3;
    out->e = *(float*)&m4;
    out->f = *(float*)&m5;
    ((Helper_2f5ec0*)out)->Transform(t);
    out->a = offset + out->a;
    out->d = offset + out->d;
    out->f = out->f + offset;
}