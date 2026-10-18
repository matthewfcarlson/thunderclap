class B_1c1280 {
  public:
    void F(int, int, int, int);
};
class A_1c1280 {
  public:
    char pad[4];
    B_1c1280* m;
    void F(int, int, int, int);
};
void A_1c1280::F(int a0, int a1, int a2, int a3) {
    m->F(a0, a1, a2, a3);
}
