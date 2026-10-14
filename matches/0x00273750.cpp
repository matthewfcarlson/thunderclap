// Same code shape as 0x002736b0 (propagated; names are from that function)
extern void* vFileCompletion;
extern void* vRequest;
class Obj_273750 {
  public:
    virtual void f();
    virtual void g();
};
class FileCompletionRequest {
  public:
    void** vt;
    char pad[8];
    Obj_273750* m0c;
    Obj_273750* m10;
    void Finish();
};
void FileCompletionRequest::Finish() {
    vt = &vFileCompletion;
    m10->g();
    m0c->g();
    vt = &vRequest;
}
