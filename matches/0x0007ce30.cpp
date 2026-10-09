class Base {
  public:
    Base(int a, int b);
    virtual void f0();
    int pad4[3];
};

extern "C" char GetFlag(const char* name);

class Method5 : public Base {
  public:
    Method5(int a, int b);
    virtual void f0();
    char m10, m11, m12, m13, m14;
    char pad15[3];
    char m18;
    char pad19[3];
    int m1c;
};

void Base::f0() {}
void Method5::f0() {}

Method5::Method5(int a, int b) : Base(a, 5) {
    m1c = b;
    m18 = GetFlag((const char*)0x48e100);
    m10 = GetFlag((const char*)0x48e0f0);
    m11 = GetFlag((const char*)0x48e134);
    m12 = GetFlag((const char*)0x48e0e4);
    m13 = GetFlag((const char*)0x48e10c);
    m14 = GetFlag((const char*)0x48e10c);
}
