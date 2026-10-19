class RestPoseDriver {
  public:
    virtual void f();
    RestPoseDriver* construct(void*);
};
struct ThisCall_002223f0 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
RestPoseDriver* RestPoseDriver::construct(void* arg) {
    ((ThisCall_002223f0*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}