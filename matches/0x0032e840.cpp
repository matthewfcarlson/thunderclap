struct Ref {
    virtual void f();
    virtual void Release();
};
struct Base {
    virtual void f();
    void dtorBase();
};
struct Derived : Base {
    char pad[0x9c - 4];
    Ref* m;
    virtual ~Derived();
};
Derived::~Derived() {
    if (m)
        m->Release();
    Base::dtorBase();
}
