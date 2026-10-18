// Same code shape as 0x001d64a0 (propagated; names are from that function)
class B_1d6980 {
  public:
    int G();
};
class A_1d6980 {
  public:
    char pad[0xec];
    B_1d6980* p;
    int F();
};
int A_1d6980::F() {
    return p->G();
}