// Same code shape as 0x000be1c0 (propagated; names are from that function)
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
