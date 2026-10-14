class Y_1c37f0 {
  public:
    void g();
};
class X_1c37f0 {
    char pad[0x18];
    Y_1c37f0* p;

  public:
    void f();
};
void X_1c37f0::f() {
    p->g();
}