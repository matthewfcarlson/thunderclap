class DriveOpenRequest {
  public:
    int vptr;
    void Init(int);
    DriveOpenRequest(int);
};
extern void __stdcall Finish();
DriveOpenRequest::DriveOpenRequest(int a) {
    Init(a);
    vptr = 0x42bb60;
    Finish();
}