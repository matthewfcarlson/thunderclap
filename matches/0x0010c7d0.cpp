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
