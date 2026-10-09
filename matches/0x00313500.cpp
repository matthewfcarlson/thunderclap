class SubCollisionDetector {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    int a, b, c, d;
    char pad[0x20];
    char x, y;
    int z;
    SubCollisionDetector();
};
SubCollisionDetector::SubCollisionDetector() : a(0), b(0), c(0), d(0), x(0), y(0), z(3) {}