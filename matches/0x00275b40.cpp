class DriveRequest_275b40 {
  public:
    DriveRequest_275b40(unsigned int);
    virtual void Fn();
};
class DriveFindCloseRequest : public DriveRequest_275b40 {
  public:
    DriveFindCloseRequest(unsigned int);
    virtual void Fn();
};
extern void FUN_002705f0();
DriveFindCloseRequest::DriveFindCloseRequest(unsigned int x) : DriveRequest_275b40(x) {
    FUN_002705f0();
}