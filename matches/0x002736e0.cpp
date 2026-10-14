class FileCompletionRequest;
struct Callee_2736e0 {
    void f(FileCompletionRequest*);
};
struct Inner_2736e0 {
    char pad[12];
    Callee_2736e0* callee;
};
class CompletionCallbackRequest {
  public:
    virtual void v0();
    virtual int v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
class FileCompletionRequest : public CompletionCallbackRequest {
  public:
    char pad[8];
    Inner_2736e0* member;
    int v1();
};
int FileCompletionRequest::v1() {
    member->callee->f(this);
    return 3;
}