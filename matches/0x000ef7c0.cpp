extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base(int a, int b);
    virtual void v0();
    char pad[0x98c - 4];
};
struct Init1 {
    int m98c, m990, m994, m998, m99c, m9a0;
    Init1() {
        m98c = 0;
        m990 = 0;
        m994 = 0;
        m998 = 0;
        m99c = 0;
        m9a0 = 0;
    }
};
class FEDialog : public Base, public Init1 {
  public:
    FEDialog(int a, int b);
    virtual void v0();
    int m9a4;
    char m9a8;
    char pad9a9[3];
    int m9ac;
};
FEDialog::FEDialog(int a, int b) : Base(a, b) {
    _ReadWriteBarrier();
    m9a8 = 1;
    m9ac = 3;
    _ReadWriteBarrier();
    m9a4 = 0;
}
