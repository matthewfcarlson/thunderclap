class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class MoveJointAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual MoveJointAction* v2(unsigned char);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void helper();
    char pad[0x18];
    int m1c;
    Ref* m20;
    Ref* volatile m24;
    Ref* volatile m28;
};
void destroy(MoveJointAction*);
MoveJointAction* MoveJointAction::v2(unsigned char flag) {
    *(volatile int*)this = 0x417fb8;
    Ref* a = m24;
    if (a) {
        a->f1();
        m24 = 0;
    }
    Ref* b = m28;
    if (b) {
        b->f1();
        m28 = 0;
    }
    Ref* c = m20;
    if (c) {
        c->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    helper();
    if (flag & 1)
        destroy(this);
    return this;
}