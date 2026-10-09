// Same code shape as 0x0026f540 (propagated; names are from that function)
class Drive {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int a;
    int b;
};

class IBase {
  public:
    virtual void w0();
    virtual void w1();
    virtual void v2();
};

class XboxDrive : public Drive, public IBase {
  public:
    XboxDrive() {}
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

void XboxDrive::v0() {}
void XboxDrive::v1() {}
void XboxDrive::v2() {}
XboxDrive* MakeXboxDrive() {
    return new XboxDrive();
}
