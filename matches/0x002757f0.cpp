class DriveRequest_2757f0 {
  public:
    virtual void V();
    DriveRequest_2757f0(int);
};
class DriveFormatRequest : public DriveRequest_2757f0 {
  public:
    virtual void W();
    DriveFormatRequest(int);
};
extern void FinishInit();
DriveFormatRequest::DriveFormatRequest(int x) : DriveRequest_2757f0(x) {
    FinishInit();
}
