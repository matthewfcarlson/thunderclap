class C_1d2de0 {
  public:
    char pad[8];
    int member;
    void target(int a, int b);
    void finish(int);
};
extern void F(int, int);
extern void G(int, int);
void C_1d2de0::target(int a, int b) {
    F(member, a);
    G(member, -2);
    finish(b);
}
