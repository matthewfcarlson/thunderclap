class Obj {
  public:
    void A();
    void B();
    void C();
    void D();
};
extern Obj* g;
void Obj::C() {
    g = this;
    A();
    B();
    D();
}
