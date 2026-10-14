class B_86da0 {
  public:
    void a();
};
bool b80();
void c90();
void thunk();
void f656a0();
class C_86da0 {
  public:
    void d(int, int);
};
class A_86da0 {
  public:
    char pad[0x1c];
    B_86da0* x;
    char pad2[0x10];
    C_86da0* y;
    void tail();
    void run();
};
void A_86da0::run() {
    if (x)
        x->a();
    else {
        thunk();
        f656a0();
    }
    if (y)
        y->d(0, 0);
    if (x) {
        while (b80()) {
            c90();
            x->a();
        }
    }
    tail();
}