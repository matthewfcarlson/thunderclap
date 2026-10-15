struct Desc {
    int a;
};
extern Desc objA, objB;
extern "C" void* __cdecl find(const char*);
extern "C" void* __cdecl castObj(void*, int, Desc*, Desc*, int);
extern "C" char __cdecl check();
class Selector {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void set(int);
};
inline void use(Selector* s, int b) {
    s->set(b);
}
void target() {
    Selector* s = (Selector*)castObj(find("targeting_selector"), 0, &objA, &objB, 0);
    if (s)
        use(s, check() == 0);
}