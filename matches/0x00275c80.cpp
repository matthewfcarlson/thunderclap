class DriveCancelRequest {
  public:
    int value;
    DriveCancelRequest(int);
    void Init(int);
};
extern void Helper();
DriveCancelRequest::DriveCancelRequest(int arg) {
    Init(arg);
    value = 0x42bc80;
    Helper();
}