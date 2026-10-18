class B_d8170 {
  public:
    int f(int, int);
};
class C_d8170 {
  public:
    int g();
};
class Obj_d8170 {
  public:
    char pad[0x150];
    B_d8170* member;
    int target(int a, int b);
};
int Obj_d8170::target(int a, int b) {
    int x = member->f(a, b);
    return ((C_d8170*)x)->g();
}