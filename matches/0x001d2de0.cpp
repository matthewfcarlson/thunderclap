class C {
  public:
    char pad[8];
    int member;
    void target(int a, int b);
    void finish(int);
};
extern void F(int, int);
extern void G(int, int);
void C::target(int a, int b) {
    F(member, a);
    G(member, -2);
    finish(b);
}
