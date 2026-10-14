// Same code shape as 0x001d64a0 (propagated; names are from that function)
class B_1d6980 {
  public:
    void G();
};
class A_1d6980 {
  public:
    char pad[0xec];
    B_1d6980* p;
    void F();
};
void A_1d6980::F() {
    p->G();
}