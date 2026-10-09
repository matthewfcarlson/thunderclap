class H {
  public:
    int check(int);
    void act(int);
};
class C {
    char pad[0x0c];
    H* member;

  public:
    void f(int);
};
void C::f(int x) {
    if (member->check(x))
        member->act(x);
}