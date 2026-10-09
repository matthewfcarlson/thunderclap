class D3DDeviceState {
  public:
    char pad[0x44c];
    unsigned char value;
};
class d3dExtAntialiasControl {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(unsigned char);
    virtual void f3();
    virtual void f4();
    D3DDeviceState* state;
};
void d3dExtAntialiasControl::f2(unsigned char value) {
    state->value = value;
}