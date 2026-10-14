class B_d8220 {
  public:
    void F1();
    int F2();
    void F3();
};
class A_d8220 {
  public:
    B_d8220* Inner();
};
class M_d8220 {
  public:
    A_d8220* Get(int);
};
class C_d8220 {
  public:
    int Run(int x);
    char pad[0x150];
    M_d8220* m;
};
int C_d8220::Run(int x) {
    m->Get(x)->Inner()->F1();
    int r = m->Get(x)->Inner()->F2();
    m->Get(x)->Inner()->F3();
    return r;
}