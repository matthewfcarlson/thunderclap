class DriveFindRequest {
  public:
    DriveFindRequest(unsigned int);
    virtual void Fn();
};
class DriveFindCloseRequest : public DriveFindRequest {
  public:
    DriveFindCloseRequest(unsigned int);
    virtual void Fn();
};
extern void FUN_002705f0();
DriveFindCloseRequest::DriveFindCloseRequest(unsigned int x) : DriveFindRequest(x) {
    FUN_002705f0();
}