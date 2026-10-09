class FileCommitRequest {
  public:
    int vt;
    void Init(int);
    FileCommitRequest(int);
};
extern void __stdcall Finish();
FileCommitRequest::FileCommitRequest(int a) {
    Init(a);
    vt = 0x42ba80;
    Finish();
}