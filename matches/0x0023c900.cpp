// Same code shape as 0x0010c7d0 (propagated; names are from that function)
struct Member_23c900 {
    void Release();
};
struct Base_23c900 {
    virtual void g();
    void Shutdown();
};
struct Derived_23c900 : Base_23c900 {
    char pad[8];
    Member_23c900 m;
    ~Derived_23c900();
    virtual void f();
};
Derived_23c900::~Derived_23c900() {
    m.Release();
    Shutdown();
}
