struct Vec3 {
    float x, y, z;
};

class Camera {
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
    virtual char Test(const Vec3* p, float r);
    char pad[0x18];
    float a; // 0x1c
    float b; // 0x20
    char pad2[0x8];
    float c0, c1, c2, c3, d0, d1, d2, d3;
};

char Camera::Test(const Vec3* p, float r) {
    if (p->z + r < a)
        return 0;
    if (p->z - r > b)
        return 0;
    if (c0 * p->x + c1 * p->z > r)
        return 0;
    if (c2 * p->x + c3 * p->z > r)
        return 0;
    if (d1 * p->z + d0 * p->y > r)
        return 0;
    if (d3 * p->z + d2 * p->y > r)
        return 0;
    return 1;
}
