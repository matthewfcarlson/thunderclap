class C_1d2de0 {
  public:
    char pad[8];
    int member;
    int target(int a, int b);
    int finish(int);
};
extern void F(int, int);
extern void G(int, int);
int C_1d2de0::target(int a, int b) {
    F(member, a);
    G(member, -2);
    return finish(b);
}
