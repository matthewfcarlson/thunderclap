class H {
  public:
    int check(int);
    void act(int);
};
class C_1c3740 {
    char pad[0x0c];
    H* member;

  public:
    void f(int);
};
void C_1c3740::f(int x) {
    if (member->check(x))
        member->act(x);
}