class Inner_272960 {
  public:
    virtual void A();
    virtual void B();
};
class Target_272960 {
  public:
    char pad[0xc];
    Inner_272960 inner;
    char pad2[0x30];
    int a;
    char pad3[4];
    int b;
    int c;
    void f(int);
};
void Target_272960::f(int x) {
    inner.A();
    c = 0;
    b = 0;
    a = 0;
    inner.B();
}