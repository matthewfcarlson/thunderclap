// Same code shape as 0x00273730 (propagated; names are from that function)
class CompletionCallbackRequest { public: char pad[12]; };
class Request { };
class FileCompletionRequest : public CompletionCallbackRequest, public Request {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
};
int FileCompletionRequest::vfunc_3() { return *(int *)(*(int *)((char *)this + 0xc) + 0xc); }
