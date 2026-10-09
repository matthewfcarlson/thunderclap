class Base {
  public:
    virtual void V();
    Base(int);
};
class DriveFormatRequest : public Base {
  public:
    virtual void W();
    DriveFormatRequest(int);
};
extern void FinishInit();
DriveFormatRequest::DriveFormatRequest(int x) : Base(x) {
    FinishInit();
}
