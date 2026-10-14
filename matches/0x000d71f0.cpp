class X_d71f0 {
  public:
    void a(int, int, int);
    unsigned int b();
    void c(unsigned int);
};
class Y_d71f0 {
  public:
    char pad[4];
    unsigned char x;
    void a(int, int, int);
};
class Z {
  public:
    char pad[4];
    unsigned char x;
};
class A_d71f0 {
  public:
    char pad[4];
    Y_d71f0* p4;
    X_d71f0* p8;
    Z* pc;
    void f(int, int, int);
};
void A_d71f0::f(int a, int b, int c) {
    p8->a(a, b, c);
    p4->a(a, b, c);
    unsigned int v = p8->b();
    p8->c(v);
    p4->x = (unsigned char)((v >> 7) & 1);
    pc->x = (unsigned char)((v >> 8) & 1);
}