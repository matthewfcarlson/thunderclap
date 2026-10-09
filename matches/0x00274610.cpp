class DriveRequest {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class DriveFormatRequest : public DriveRequest {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f4();
    virtual int vfunc_6();
};
int DriveFormatRequest::vfunc_6() {
    return 0xd;
}