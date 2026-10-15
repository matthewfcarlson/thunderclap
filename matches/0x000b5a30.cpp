class Widget {
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
extern "C" void* __cdecl lookup(const char*);
extern "C" Widget* __cdecl convert(void*, int, void*, void*, int);
extern char name[];
extern int r1, r2;
class Owner {
    char pad[0x44];
    char* state;

  public:
    void run();
};
void Owner::run() {
    Widget* w = convert(lookup(name), 0, &r1, &r2, 0);
    if (w && state)
        w->set(state[5] == 0);
}