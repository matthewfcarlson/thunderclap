class Inner_272a20 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272a20 {
  public:
    char pad[0xc];
    Inner_272a20 inner;
    char pad2[0x30];
    int value;
    int target();
};
int Obj_272a20::target() {
    inner.A();
    int v = value;
    inner.B();
    return v;
}