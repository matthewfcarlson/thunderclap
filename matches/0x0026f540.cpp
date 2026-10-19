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

XboxDrive* MakeXboxDrive() {
    return new XboxDrive();
}
