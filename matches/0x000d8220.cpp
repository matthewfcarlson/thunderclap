class B {
  public:
    void F1();
    int F2();
    void F3();
};
class A {
  public:
    B* Inner();
};
class M {
  public:
    A* Get(int);
};
class C {
  public:
    int Run(int x);
    char pad[0x150];
    M* m;
};
int C::Run(int x) {
    m->Get(x)->Inner()->F1();
    int r = m->Get(x)->Inner()->F2();
    m->Get(x)->Inner()->F3();
    return r;
}