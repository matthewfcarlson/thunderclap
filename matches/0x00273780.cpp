// Same code shape as 0x002736e0 (propagated; names are from that function)
class FileCompletionRequest;
struct Callee_273780 {
    void f(FileCompletionRequest*);
};
struct Inner_273780 {
    char pad[12];
    Callee_273780* callee;
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
    Inner_273780* member;
    int v1();
};
int FileCompletionRequest::v1() {
    member->callee->f(this);
    return 3;
}