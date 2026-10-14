struct Member_10c7d0 {
    void Release();
};
struct Base_10c7d0 {
    virtual void g();
    void Shutdown();
};
struct Derived_10c7d0 : Base_10c7d0 {
    char pad[8];
    Member_10c7d0 m;
    ~Derived_10c7d0();
    virtual void f();
};
Derived_10c7d0::~Derived_10c7d0() {
    m.Release();
    Shutdown();
}
