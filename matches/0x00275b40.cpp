class DriveFindRequest {
  public:
    DriveFindRequest(unsigned int);
};
class DriveFindCloseRequest : public DriveFindRequest {
  public:
    DriveFindCloseRequest(unsigned int);
    virtual void Fn();
};
extern void __stdcall FUN_00275600(unsigned int);
extern void FUN_002705f0();
DriveFindRequest::DriveFindRequest(unsigned int x) {
    FUN_00275600(x);
}
DriveFindCloseRequest::DriveFindCloseRequest(unsigned int x) : DriveFindRequest(x) {
    FUN_002705f0();
}