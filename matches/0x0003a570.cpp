class A_3a570 {
  public:
    virtual void f();
    virtual void g();
};
class B_3a570 {
    char pad[0x128];
    A_3a570* p;

  public:
    void run();
};
void B_3a570::run() {
    if (p) {
        p->g();
        p = 0;
    }
}