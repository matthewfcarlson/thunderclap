class Base_2757f0 {
  public:
    virtual void V();
    Base_2757f0(int);
};
class DriveFormatRequest : public Base_2757f0 {
  public:
    virtual void W();
    DriveFormatRequest(int);
};
extern void FinishInit();
DriveFormatRequest::DriveFormatRequest(int x) : Base_2757f0(x) {
    FinishInit();
}
