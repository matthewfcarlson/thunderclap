class C_1d2de0 {
  public:
    char pad[8];
    int member;
    int target(int a, int b);
    int finish(int);
};
extern void FUN_002133d0(int, int);
extern void FUN_00213600(int, int);
int C_1d2de0::target(int a, int b) {
    FUN_002133d0(member, a);
    FUN_00213600(member, -2);
    return finish(b);
}
