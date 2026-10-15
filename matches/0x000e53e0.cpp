class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void Action();
};
class Owner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void First();
    virtual void f5();
    virtual void f6();
    virtual void Second();
    char pad[0x48];
    Item* items[128];
    void Run(int mode);
};
void Owner::Run(int mode) {
    for (int i = 0; i < 128; ++i) {
        if (!items[i])
            break;
        items[i]->Action();
    }
    if (mode == 1) {
        First();
        return;
    }
    if (mode == 2)
        Second();
}