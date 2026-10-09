void* __cdecl operator_new(unsigned int);
class FrameCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    void initialize(int);
    void initializeExtra();
    int pad[5];
    int a;
    int b;
};
FrameCondition* target(void) {
    FrameCondition* p = (FrameCondition*)operator_new(0x20);
    if (p) {
        p->initialize(0);
        *(void**)p = (void*)0x412430;
        ((FrameCondition*)((char*)p + 0x10))->initializeExtra();
        p->a = 0;
        p->b = 0;
        return p;
    }
    return (FrameCondition*)0;
}
