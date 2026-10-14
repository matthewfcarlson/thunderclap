class B_1c1280 {
  public:
    void F();
};
class A_1c1280 {
  public:
    char pad[4];
    B_1c1280* m;
    void F();
};
void A_1c1280::F() {
    m->F();
}
