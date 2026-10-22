class B_d8220 {
  public:
    void F1(int);
    int F2(int);
    void F3(int);
};
class A_d8220 {
  public:
    B_d8220* Inner();
};
class M_d8220 {
  public:
    A_d8220* Get();
};
class FEMemCardControl_d8220 {
  public:
    int Run(int x);
    char pad[0x150];
    M_d8220* m;
};
int FEMemCardControl_d8220::Run(int x) {
    m->Get()->Inner()->F1(x);
    int r = m->Get()->Inner()->F2(x);
    m->Get()->Inner()->F3(x);
    return r;
}