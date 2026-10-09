class CFrontEndCallback {
  public:
    void Run();
};
typedef void (CFrontEndCallback::*CbFn)();
class CallbackHolder {
  public:
    virtual void vfunc_0();
    CFrontEndCallback* mObject;
    CbFn mFn;
};
void CallbackHolder::vfunc_0() {
    CbFn fn = mFn;
    (mObject->*fn)();
}
