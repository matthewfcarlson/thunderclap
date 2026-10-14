class Inner_272a80 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272a80 {
  public:
    char pad[0xc];
    Inner_272a80 p;
    char pad2[0x54 - 0x10];
    unsigned char value;
    unsigned char target();
};
unsigned char Obj_272a80::target() {
    p.A();
    unsigned char v = value;
    p.B();
    return v;
}