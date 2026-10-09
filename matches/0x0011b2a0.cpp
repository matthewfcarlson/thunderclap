struct MotionFleeTrack {
    int vtable;
    char pad4[8];
    int a;
    int b;
    int c;
    void ctor();
};
void* __cdecl operator_new(unsigned int);
extern char MotionFleeVtable;
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual MotionFleeTrack* vfunc_5();
};
MotionFleeTrack* Factory::vfunc_5() {
    MotionFleeTrack* p = (MotionFleeTrack*)operator_new(0x18);
    if (p) {
        p->ctor();
        p->vtable = (int)&MotionFleeVtable;
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = (int)0x3f800000;
        return p;
    }
    return 0;
}
