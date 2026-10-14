class B_1d26d0 {
  public:
    void f(unsigned int);
};
class D {
  public:
    void h(B_1d26d0*);
};
class C_1d26d0 {
  public:
    char pad[12];
    D d;
    void g(unsigned int, B_1d26d0*);
};
void C_1d26d0::g(unsigned int a, B_1d26d0* b) {
    b->f(a);
    d.h(b);
}
