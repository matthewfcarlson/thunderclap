class Action_1dc40 {
  public:
    Action_1dc40();
    virtual void f();
    char pad[0x18];
};
class Ref {
  public:
    virtual void add();
    virtual void release();
};
class CAction : public Action_1dc40 {
  public:
    Ref* ref;
    int value;
    CAction(int v, Ref* r) : Action_1dc40() {
        ref = 0;
        if (r)
            r->add();
        if (ref)
            ref->release();
        ref = r;
        value = v;
    }
    virtual void f();
};
class CGrappleLocoStrafe4Action : public CAction {
  public:
    int extra;
    CGrappleLocoStrafe4Action(int v, Ref* r);
    virtual void f();
};
CGrappleLocoStrafe4Action::CGrappleLocoStrafe4Action(int v, Ref* r) : CAction(v, r) {
    extra = 0;
}