extern void* alloc(unsigned int);
inline void* operator new(unsigned int, void* where) {
    return where;
}

class Base {
  public:
    Base();
    virtual void g();
    int x;
};

class Derived : public Base {
  public:
    Derived() : Base() {
        b = 0;
        c = -1.0f;
        d = 0;
        e = 100.0f;
        f = 0;
        a = 1;
    }
    virtual void g();
    int a;
    int b;
    float c;
    int d;
    float e;
    int f;
};

class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Derived* f5();
};

Derived* Factory::f5() {
    Derived* p = (Derived*)alloc(0x20);
    if (p) {
        new (p) Derived();
        return p;
    }
    return 0;
}
