class DriveRequest {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int vfunc_6();
};
class DriveCreateDirectoryRequest : public DriveRequest {
  public:
    int vfunc_6();
};
int DriveCreateDirectoryRequest::vfunc_6() {
    return 0xe;
}