struct I {
    void f(void*, void*);
};
class C {
    char pad[0x18];
    I inner;

  public:
    void g(void*);
};
void C::g(void* x) {
    inner.f(x, x);
}