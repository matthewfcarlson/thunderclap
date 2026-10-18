class Y_1c37f0 {
  public:
    void g(int, int, int, int);
};
class X_1c37f0 {
    char pad[0x18];
    Y_1c37f0* p;

  public:
    void f(int, int, int, int);
};
void X_1c37f0::f(int a0, int a1, int a2, int a3) {
    p->g(a0, a1, a2, a3);
}