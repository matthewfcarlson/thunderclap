class Request {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Manager_274be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
extern Manager_274be0* gManager_274be0;
extern char gLock_274be0;
extern int gCompletionVtable;
extern int gRequestVtable;
class CompletionEventRequest {
  public:
    int* vptr;
    char pad[8];
    Request* mRequest;
    void* vfunc_0(unsigned char);
};
void* CompletionEventRequest::vfunc_0(unsigned char param) {
    vptr = &gCompletionVtable;
    mRequest->f1();
    vptr = &gRequestVtable;
    if (param & 1) {
        FUN_0026d850(&gLock_274be0);
        gManager_274be0->f4(this);
        FUN_0026d840(&gLock_274be0);
    }
    return this;
}