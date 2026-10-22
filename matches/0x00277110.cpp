namespace core {
struct IMutable {
    virtual void m();
};
struct InstanceDrive;
} // namespace core
struct Source_277110 {
    virtual void first();
    void FUN_00272b60(void*, void*, int);
};
struct Context {
    void FUN_002705f0();
};
struct DriveOpenRequest_277110 {
    void* FUN_002756c0(core::InstanceDrive*);
};
void* __cdecl FUN_00273560(unsigned int);
namespace core {
struct Primary_277110 {
    virtual void p();
};
struct InstanceDrive : Primary_277110, IMutable {
    int refs;
    Source_277110* source;
    Context* context;
    int state;
    char pad[8];
    char flag;
    virtual void p();
    virtual void m();
    InstanceDrive(Source_277110*, Context*);
};
InstanceDrive::InstanceDrive(Source_277110* s, Context* c) {
    refs = 1;
    source = s;
    context = c;
    state = 0;
    flag = 0;
    c->FUN_002705f0();
    source->first();
    DriveOpenRequest_277110* h = (DriveOpenRequest_277110*)FUN_00273560(12);
    void* result = h ? h->FUN_002756c0(this) : 0;
    source->FUN_00272b60(result, context, 0);
}
} // namespace core
