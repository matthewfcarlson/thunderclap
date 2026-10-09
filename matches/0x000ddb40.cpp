class ControllerPollerBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual bool f2();
    virtual bool f3();
    virtual bool f4(int, int);
    virtual void f5();
};
class ControllerPoller : public ControllerPollerBase {
  public:
    bool f3(int);
};
bool ControllerPoller::f3(int arg) {
    int i = 0;
    do {
        if (f4(arg, i))
            return true;
        ++i;
    } while (i < 1);
    return false;
}