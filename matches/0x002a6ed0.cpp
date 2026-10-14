class A_2a6ed0 {
  public:
    virtual void f();
};
class B_2a6ed0 {
  public:
    virtual void f();
    virtual void g();
};
class C_2a6ed0 {
    char pad[0x40];
    B_2a6ed0* m;

  public:
    void set(A_2a6ed0*);
};
class D {
  public:
    char pad[0x5c];
    A_2a6ed0* m;
};
void C_2a6ed0::set(A_2a6ed0* p) {
    A_2a6ed0* n = ((D*)p)->m;
    if (n)
        n->f();
    if (m)
        m->g();
    m = (B_2a6ed0*)n;
}