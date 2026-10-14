struct I_1c7e90 {
    void f(void*, void*);
};
class C_1c7e90 {
    char pad[0x18];
    I_1c7e90 inner;

  public:
    void g(void*);
};
void C_1c7e90::g(void* x) {
    inner.f(x, x);
}