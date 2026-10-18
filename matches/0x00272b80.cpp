// Same code shape as 0x00272b60 (propagated; names are from that function)
class B_272b80 {
  public:
    int f();
};
class A_272b80 {
  public:
    char pad[0xb8];
    B_272b80* p;
    int run();
};
int A_272b80::run() {
    return p->f();
}