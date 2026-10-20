// Same code shape as 0x0022a5d0 (propagated; names are from that function)
class Bank_23c640 {
  public:
    virtual void f();
    Bank_23c640* construct(void*);
};
struct ThisCall_00232e90 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
Bank_23c640* Bank_23c640::construct(void* arg) {
    ((ThisCall_00232e90*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}