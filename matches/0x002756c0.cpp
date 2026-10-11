extern "C" char DAT_0042bb60[];
class DriveOpenRequest {
  public:
    int vptr;
    void Init(int);
    DriveOpenRequest(int);
};
extern void __stdcall Finish();
DriveOpenRequest::DriveOpenRequest(int a) {
    Init(a);
    vptr = ((int)DAT_0042bb60);
    Finish();
}