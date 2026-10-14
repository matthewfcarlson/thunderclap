struct Ref_32e840 {
    virtual void f();
    virtual void Release();
};
struct Base_32e840 {
    virtual void f();
    void dtorBase();
};
struct Derived_32e840 : Base_32e840 {
    char pad[0x9c - 4];
    Ref_32e840* m;
    virtual ~Derived_32e840();
};
Derived_32e840::~Derived_32e840() {
    if (m)
        m->Release();
    Base_32e840::dtorBase();
}
