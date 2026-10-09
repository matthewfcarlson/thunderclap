class TeleportAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    virtual void f4();
    virtual void f5();
    char pad[0x20 - 4];
    volatile int value;
};
bool TeleportAction::vfunc_3(int a, int b) {
    return value;
}