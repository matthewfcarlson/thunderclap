class Inner_272a40 {
  public:
    virtual void A();
    virtual void B();
};
class Other_272a40 {
  public:
    void Run(int);
};
class Drive_272a40 {
  public:
    char pad0[0x0c];
    Inner_272a40 inner;
    char pad10[0x44];
    unsigned char flag;
    int value;
    char pad60[0x5c];
    Other_272a40* other;
    void Target(int);
};
void Drive_272a40::Target(int arg) {
    inner.A();
    flag = 0;
    value = 0;
    inner.B();
    other->Run(arg);
}