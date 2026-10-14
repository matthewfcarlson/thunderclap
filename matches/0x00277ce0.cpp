class A_277ce0 {
  public:
    virtual void f();
    virtual void g();
};
class B_277ce0 {
  public:
    A_277ce0* p;
    void target();
};
void B_277ce0::target() {
    A_277ce0* q = p;
    q->g();
    p = 0;
}