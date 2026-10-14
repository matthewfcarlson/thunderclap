class Part_2c2730 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class Geometry {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void vfunc_8(int, int);
    void helper(int, int);
    char pad[0x60 - 4];
    Part_2c2730* p1;
    Part_2c2730* p2;
};
void Geometry::vfunc_8(int a, int b) {
    if (p1)
        p1->f6(0, 1);
    if (p2)
        p2->f6(0, 1);
    helper(a, b);
}