class Base {
  public:
    Base(int a, int b);
    virtual void f0();
    char pad[0xc];
};

extern "C" char __cdecl Lookup(const char* s);

class Derived : public Base {
  public:
    Derived(int a, int b);
    virtual void f0();
    char c10, c11, c12, c13, c14, c15;
    char pad2[2];
    char c18;
    char pad3[3];
    int m1c;
};

void Base::f0() {}
void Derived::f0() {}

Derived::Derived(int a, int b) : Base(a, 6) {
    m1c = b;
    c18 = Lookup((const char*)0x48e100);
    c10 = Lookup((const char*)0x48e134);
    c11 = Lookup((const char*)0x48e0f0);
    c12 = Lookup((const char*)0x48e0f0);
    c13 = Lookup((const char*)0x48e0f0);
    c14 = Lookup((const char*)0x48e0f0);
    c15 = Lookup((const char*)0x48e134);
}
