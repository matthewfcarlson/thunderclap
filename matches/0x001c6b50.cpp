// Same code shape as 0x001c3d20 (propagated; names are from that function)
class A_1c6b50 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c6b50 {
  public:
    A_1c6b50* p;
    void run();
};
void B_1c6b50::run() {
    if (p)
        p->g();
    p = 0;
}