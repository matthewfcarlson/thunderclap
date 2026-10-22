class ControllerPollerBase_dd940 {
  public:
    virtual void Dummy();
    ControllerPollerBase_dd940(int);
};
class ControllerPoller : public ControllerPollerBase_dd940 {
  public:
    virtual void Poll();
    char pad[4];
    int m8;
    char pad2[0x2c];
    int m38;
    ControllerPoller(int a, int b);
};
ControllerPoller::ControllerPoller(int a, int b) : ControllerPollerBase_dd940(b) {
    m8 = b;
    m38 = a;
}
