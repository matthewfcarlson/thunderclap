class A_ebda0 {
  public:
    virtual void f();
};
class B_ebda0 {
  public:
    virtual void f();
    virtual void g();
};
class C_ebda0 {
    char pad[0x1d8c];
    B_ebda0* m;

  public:
    void set(A_ebda0*);
};
void C_ebda0::set(A_ebda0* p) {
    if (p)
        p->f();
    if (m)
        m->g();
    m = (B_ebda0*)p;
}