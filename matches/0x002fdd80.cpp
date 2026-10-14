class B_2fdd80 {
  public:
    void H();
};
class A_2fdd80 {
    char pad[0x70];
    B_2fdd80* p;

  public:
    void F(int);
    void O();
};
void A_2fdd80::F(int x) {
    if (p)
        p->H();
    O();
}