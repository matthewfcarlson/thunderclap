class R {
  public:
    void f650();
    void f4c0();
    void fa10(int);
};
class C {
    char pad0[8];
    int m8;
    R* mc;

  public:
    void target(char b);
};
void C::target(char b) {
    mc->f650();
    if (b) {
        mc->f4c0();
        return;
    }
    mc->fa10(m8);
}
