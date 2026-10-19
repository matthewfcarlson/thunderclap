// Same code shape as 0x0022a5d0 (propagated; names are from that function)
class RestPoseDriver {
  public:
    virtual void f();
    RestPoseDriver* construct(void*);
};
struct ThisCall_002a4e10 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
RestPoseDriver* RestPoseDriver::construct(void* arg) {
    ((ThisCall_002a4e10*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}