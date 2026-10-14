class A_1c3d20 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c3d20 {
  public:
    A_1c3d20* p;
    void run();
};
void B_1c3d20::run() {
    if (p)
        p->g();
    p = 0;
}