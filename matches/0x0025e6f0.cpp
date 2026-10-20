// Same code shape as 0x0022a5d0 (propagated; names are from that function)
class MetaEntity_25e6f0 {
  public:
    virtual void f();
    MetaEntity_25e6f0* construct(void*);
};
struct ThisCall_00244ea0 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
MetaEntity_25e6f0* MetaEntity_25e6f0::construct(void* arg) {
    ((ThisCall_00244ea0*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}