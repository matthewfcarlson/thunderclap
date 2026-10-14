extern void* vFileCompletion;
extern void* vRequest;
class Obj_2736b0 {
  public:
    virtual void f();
    virtual void g();
};
class FileCompletionRequest {
  public:
    void** vt;
    char pad[8];
    Obj_2736b0* m0c;
    Obj_2736b0* m10;
    void Finish();
};
void FileCompletionRequest::Finish() {
    vt = &vFileCompletion;
    m10->g();
    m0c->g();
    vt = &vRequest;
}
