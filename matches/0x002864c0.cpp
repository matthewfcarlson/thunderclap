extern "C" void _ReadWriteBarrier();
extern char simpleVftable;
extern char frameVftable;
class SimpleFrameController {
  public:
    virtual void a();
    virtual void b();
    virtual SimpleFrameController* vfunc_2(unsigned char);
    void cleanup();
    char pad[0x38];
    struct Obj {
        virtual void a();
        virtual void b();
    }* member;
};
extern void destroy(SimpleFrameController*);
SimpleFrameController* SimpleFrameController::vfunc_2(unsigned char flag) {
    *(void**)this = &simpleVftable;
    _ReadWriteBarrier();
    if (member) {
        member->b();
        member = 0;
    }
    *(void**)this = &frameVftable;
    cleanup();
    if (flag & 1)
        destroy(this);
    return this;
}