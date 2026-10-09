class Next {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int, int);
};
class Child {
  public:
    void run();
};
class Obj {
  public:
    char pad118[0x118];
    unsigned char a;
    unsigned char b;
    char pad11a[0x1ca0 - 0x11a];
    Next* next;
    char pad1ca4[0x1f58 - 0x1ca4];
    Child child;
    char pad1f5c[0x22e0 - 0x1f59];
    unsigned char c;
    void target(int, int);
};
void Obj::target(int x, int y) {
    if (!a && !b && c) {
        child.run();
        if (next) {
            next->f4(x, y);
            return;
        }
    }
}
