class Base {
  public:
    Base(int a, int b);
    virtual void f0();
    char pad[0x0c];
};

class Derived : public Base {
  public:
    Derived(int a, int b);
    virtual void f0();
    char m10, m11, m12, m13;
    int m14;
    char m18;
    char m19[3];
    int m1c;
};

extern char GetFlag(const char* s);

void Derived::f0() {}

Derived::Derived(int a, int b) : Base(a, 4) {
    m1c = b;
    m18 = GetFlag((const char*)0x48e100);
    m10 = GetFlag((const char*)0x48e134);
    m11 = GetFlag((const char*)0x48e128);
    m12 = GetFlag((const char*)0x48e128);
    m13 = GetFlag((const char*)0x48e128);
}
