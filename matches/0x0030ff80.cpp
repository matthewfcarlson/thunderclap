class R_30ff80 {
  public:
    void f650();
    void f4c0();
    void fa10(int);
};
class C_30ff80 {
    char pad0[8];
    int m8;
    R_30ff80* mc;

  public:
    void target(char b);
};
void C_30ff80::target(char b) {
    mc->f650();
    if (b) {
        mc->f4c0();
        return;
    }
    mc->fa10(m8);
}
