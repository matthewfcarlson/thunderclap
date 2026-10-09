// Same code shape as 0x0022a5d0 (propagated; names are from that function)
class RestPoseDriver { public: virtual void f(); RestPoseDriver* construct(void*); };
extern void __stdcall InitRestPose(void*);
extern void* RestPoseVtable;
RestPoseDriver* RestPoseDriver::construct(void* arg) {
    InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}