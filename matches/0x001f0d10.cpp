class Base {
  public:
    Base(void* a, int n);
    virtual void f0();
    char pad[12];
};

class Derived : public Base {
  public:
    Derived(void* a, int b);
    char m10, m11, m12, m13;
    int pad14;
    char m18;
    char pad19[3];
    int m1c;
};

extern "C" char __cdecl Lookup(const char* s);

Derived::Derived(void* a, int b) : Base(a, 4) {
    m1c = b;
    m18 = Lookup((const char*)0x48e100);
    m10 = Lookup((const char*)0x49cad8);
    m11 = Lookup((const char*)0x49cad8);
    m12 = Lookup((const char*)0x48e128);
    m13 = Lookup((const char*)0x48e128);
}
