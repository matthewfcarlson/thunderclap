class Part {
  public:
    Part();
    char pad[8];
};
class CUnlockable {
  public:
    CUnlockable();
    virtual void f();
    char pad4[4];
    char flag8;
    char pad9[7];
    Part p10;
    int val18;
};
CUnlockable::CUnlockable() : flag8(1), val18(0) {}
class CUnlockableMove : public CUnlockable {
  public:
    CUnlockableMove(int x);
    virtual void g();
    void Init(int x);
    char pad1c[4];
    char flag20;
    char pad21[3];
    int val24;
    int val28;
    char flag2c;
    char pad2d[3];
    int val30;
    char pad34[4];
    Part p38;
    Part p40;
    char flag48;
};
CUnlockableMove::CUnlockableMove(int x) : flag20(0), val24(0), val28(-1), flag2c(0), val30(0), flag48(0) {
    Init(x);
}
