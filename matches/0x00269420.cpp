class Pad_269420 {
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
    Pad_269420 pads[4];
    Pad_269420* vfunc_4(int);
};
Pad_269420* ControllerSystemXBox::vfunc_4(int param) {
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
