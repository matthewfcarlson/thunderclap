extern "C" char DAT_0043186c[];
class RootMatrixDriver {
  public:
    int vf;
    char pad[0x14];
    int value;
    RootMatrixDriver(int);
};
class Base {
  public:
    void Init();
};
RootMatrixDriver::RootMatrixDriver(int x) {
    ((Base*)this)->Init();
    value = x;
    vf = ((int)DAT_0043186c);
}