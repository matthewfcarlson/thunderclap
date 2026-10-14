class B_1d64a0 {
  public:
    void G();
};
class A_1d64a0 {
  public:
    char pad[0xec];
    B_1d64a0* p;
    void F();
};
void A_1d64a0::F() {
    p->G();
}