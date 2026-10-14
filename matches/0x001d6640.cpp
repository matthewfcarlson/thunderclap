class C_1d6640 {
  public:
    char pad0[0x40];
    int a;
    char pad44[0xa8];
    C_1d6640* p;
    void g(int);
    void target();
};
void C_1d6640::target() {
    p->g(a);
}
