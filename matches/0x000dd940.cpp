class Base {
  public:
    virtual void Dummy();
    Base(int);
};
class ControllerPoller : public Base {
  public:
    virtual void Poll();
    char pad[4];
    int m8;
    char pad2[0x2c];
    int m38;
    ControllerPoller(int a, int b);
};
ControllerPoller::ControllerPoller(int a, int b) : Base(b) {
    m8 = b;
    m38 = a;
}
