class A {
  public:
    virtual void f();
    virtual void g();
};
class B {
  public:
    A* p;
    void run();
};
void B::run() {
    if (p)
        p->g();
    p = 0;
}