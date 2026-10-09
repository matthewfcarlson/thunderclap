class RestPoseDriver { public: virtual void f(); RestPoseDriver* construct(void*); };
extern void __stdcall InitRestPose(void*);
extern void* RestPoseVtable;
RestPoseDriver* RestPoseDriver::construct(void* arg) {
    InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}