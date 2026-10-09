class A {
    char pad[0x18];

  public:
    unsigned char x;
    void f();
};
void A::f() {
    x = 0;
}