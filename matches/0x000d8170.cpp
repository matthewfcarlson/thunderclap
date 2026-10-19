class B_d8170 {
  public:
    int f();
};
class C_d8170 {
  public:
    int g(int, int);
};
class Obj_d8170 {
  public:
    char pad[0x150];
    B_d8170* member;
    int target(int a, int b);
};
int Obj_d8170::target(int a, int b) {
    return ((C_d8170*)member->f())->g(a, b);
}