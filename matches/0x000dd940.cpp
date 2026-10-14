class Base_dd940 {
  public:
    virtual void Dummy();
    Base_dd940(int);
};
class ControllerPoller : public Base_dd940 {
  public:
    virtual void Poll();
    char pad[4];
    int m8;
    char pad2[0x2c];
    int m38;
    ControllerPoller(int a, int b);
};
ControllerPoller::ControllerPoller(int a, int b) : Base_dd940(b) {
    m8 = b;
    m38 = a;
}
