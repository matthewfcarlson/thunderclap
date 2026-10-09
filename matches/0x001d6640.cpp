class C {
  public:
    char pad0[0x40];
    int a;
    char pad44[0xa8];
    C* p;
    void g(int);
    void target();
};
void C::target() {
    p->g(a);
}
