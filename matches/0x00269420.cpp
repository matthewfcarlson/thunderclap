class Pad {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool IsConnected();
    char data[0x49c];
};
class ControllerSystemXBox {
  public:
    char pad[0x20];
    Pad pads[4];
    Pad* vfunc_4(int);
};
Pad* ControllerSystemXBox::vfunc_4(int param) {
    int count = 0;
    for (unsigned int i = 0; i < 4; i++) {
        if (pads[i].IsConnected()) {
            if (count == param)
                return &pads[i];
            ++count;
        }
    }
    return 0;
}
