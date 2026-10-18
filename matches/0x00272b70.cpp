// Same code shape as 0x00272b60 (propagated; names are from that function)
class B_272b70 {
  public:
    void f(int, int);
};
class A_272b70 {
  public:
    char pad[0xb8];
    B_272b70* p;
    void run(int, int);
};
void A_272b70::run(int a0, int a1) {
    p->f(a0, a1);
}