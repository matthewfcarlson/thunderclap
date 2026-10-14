class Child_363f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
};
class Owner_363f0 {
  public:
    char pad0[0x118];
    unsigned char a;
    unsigned char b;
    char pad1[0x1ca0 - 0x11a];
    Child_363f0* p;
    char pad2[0x22e0 - 0x1ca4];
    unsigned char c;
    void f(int, int);
};
void Owner_363f0::f(int x, int y) {
    if (!a && !b && c && p)
        p->f3(x, y);
}