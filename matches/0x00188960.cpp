extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class Action {
  public:
    virtual void f0();
    virtual void f1();
    virtual int f2(char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void baseCleanup();
};
class PropAnimationAction : public Action {
  public:
    char pad[0x18];
    int m1c;
    Ref* m20;
    Ref* m24;
    Ref* m28;
    virtual int f2(char);
};
extern char propVtable[];
extern void thunk(PropAnimationAction*);
int PropAnimationAction::f2(char param) {
    *(void**)this = (void*)propVtable;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    this->Action::baseCleanup();
    if (param & 1)
        thunk(this);
    return (int)this;
}
