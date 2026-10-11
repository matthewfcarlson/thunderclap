extern void* __cdecl alloc(unsigned int);
extern void* MotionBlurAction_vftable[];
class BaseAction {
  public:
    BaseAction();
    virtual void a();
    virtual void b();
    char pad[0x18];
};
class MBAction : public BaseAction {
  public:
    void* owner;
    char pad2[0x2c - 0x20 - 4 - 0];
};
class MotionBlurTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual MBAction* vfunc_10(int a, int b, int c);
};
MBAction* MotionBlurTrack::vfunc_10(int a, int b, int c) {
    MBAction* p = (MBAction*)alloc(0x2c);
    if (p) {
        p->BaseAction::BaseAction();
        *(void* volatile*)p = MotionBlurAction_vftable;
        *(void* volatile*)&p->owner = 0;
        p->owner = (void*)this;
        return p;
    }
    return 0;
}
