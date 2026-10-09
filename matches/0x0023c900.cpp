// Same code shape as 0x0010c7d0 (propagated; names are from that function)
struct Member {
    void Release();
};
struct Base {
    virtual void g();
    void Shutdown();
};
struct Derived : Base {
    char pad[8];
    Member m;
    ~Derived();
    virtual void f();
};
Derived::~Derived() {
    m.Release();
    Shutdown();
}
