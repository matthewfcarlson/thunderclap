extern "C" char DAT_0042bc80[];
class DriveCancelRequest {
  public:
    int value;
    DriveCancelRequest(int);
    void Init(int);
};
extern void Helper();
DriveCancelRequest::DriveCancelRequest(int arg) {
    Init(arg);
    value = ((int)DAT_0042bc80);
    Helper();
}