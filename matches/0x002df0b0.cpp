// Same code shape as 0x0022a5d0 (propagated; names are from that function)
class ShadowMeshBuffer_2df0b0 {
  public:
    virtual void f();
    ShadowMeshBuffer_2df0b0* construct(void*);
};
struct ThisCall_002a4e10 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
ShadowMeshBuffer_2df0b0* ShadowMeshBuffer_2df0b0::construct(void* arg) {
    ((ThisCall_002a4e10*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}