class B_272b60 {
  public:
    int f(int, int, int);
};
class A_272b60 {
  public:
    char pad[0xb8];
    B_272b60* p;
    int run(int, int, int);
};
int A_272b60::run(int a0, int a1, int a2) {
    return p->f(a0, a1, a2);
}