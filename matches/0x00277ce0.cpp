class A {
  public:
    virtual void f();
    virtual void g();
};
class B {
  public:
    A* p;
    void target();
};
void B::target() {
    A* q = p;
    q->g();
    p = 0;
}