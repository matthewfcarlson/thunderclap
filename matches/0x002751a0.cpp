extern "C" char DAT_0042ba80[];
class FileCommitRequest {
  public:
    int vt;
    void Init(int);
    FileCommitRequest(int);
};
extern void __stdcall Finish();
FileCommitRequest::FileCommitRequest(int a) {
    Init(a);
    vt = ((int)DAT_0042ba80);
    Finish();
}