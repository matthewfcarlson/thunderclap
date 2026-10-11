namespace core {
struct IMutable {
    virtual void m();
};
struct InstanceDrive;
} // namespace core
struct Source {
    virtual void first();
    void FUN_00272b60(void*, void*, int);
};
struct Context {
    void FUN_002705f0();
};
struct Helper {
    void* FUN_002756c0(core::InstanceDrive*);
};
void* __cdecl FUN_00273560(unsigned int);
namespace core {
struct Primary {
    virtual void p();
};
struct InstanceDrive : Primary, IMutable {
    int refs;
    Source* source;
    Context* context;
    int state;
    char pad[8];
    char flag;
    virtual void p();
    virtual void m();
    InstanceDrive(Source*, Context*);
};
InstanceDrive::InstanceDrive(Source* s, Context* c) {
    refs = 1;
    source = s;
    context = c;
    state = 0;
    flag = 0;
    c->FUN_002705f0();
    source->first();
    Helper* h = (Helper*)FUN_00273560(12);
    void* result = h ? h->FUN_002756c0(this) : 0;
    source->FUN_00272b60(result, context, 0);
}
} // namespace core
