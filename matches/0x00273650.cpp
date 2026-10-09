class Request {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int vfunc_6();
};
class CompletionEventRequest : public Request {
  public:
    int vfunc_6();
};
int CompletionEventRequest::vfunc_6() {
    return 0x16;
}