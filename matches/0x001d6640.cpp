class C_1d6640 {
  public:
    char pad0[0x40];
    int a;
    char pad44[0xa8];
    C_1d6640* p;
    int g(int);
    int target();
};
int C_1d6640::target() {
    return p->g(a);
}
