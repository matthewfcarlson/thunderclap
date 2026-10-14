// Same code shape as 0x001d64a0 (propagated; names are from that function)
class B_1d6990 {
  public:
    void G();
};
class A_1d6990 {
  public:
    char pad[0xec];
    B_1d6990* p;
    void F();
};
void A_1d6990::F() {
    p->G();
}