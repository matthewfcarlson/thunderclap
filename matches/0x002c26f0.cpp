struct Pair {
    int x, y;
};
class Child {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class DrawableContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(int, int);
};
class Geometry : public DrawableContainer {
  public:
    char pad[0x5c];
    Child* a;
    Child* b;
    virtual void vfunc_6(Pair);
};
void Geometry::vfunc_6(Pair p) {
    if (a)
        a->f6(p.x, p.y);
    if (b)
        b->f6(p.x, p.y);
    DrawableContainer::vfunc_6(p.x, p.y);
}