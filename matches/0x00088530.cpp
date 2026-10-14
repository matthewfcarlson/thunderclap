class Obj_88530 {
  public:
    void A();
    void B();
    void C();
    void D();
};
extern Obj_88530* g_88530;
void Obj_88530::C() {
    g_88530 = this;
    A();
    B();
    D();
}
