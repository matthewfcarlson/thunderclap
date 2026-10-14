extern "C" char DAT_00428de0[];
class Ref_23e8c0 {
  public:
    virtual void f0();
    virtual void f1();
};
class fight_StopAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual fight_StopAction* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x18];
    Ref_23e8c0* m1c;
    char pad20[8];
    Ref_23e8c0* volatile m28;
    void cleanup();
};
void destroy(fight_StopAction*);
fight_StopAction* fight_StopAction::vfunc_2(unsigned char param) {
    *(volatile int*)this = ((int)DAT_00428de0);
    Ref_23e8c0* r = m28;
    if (r) {
        r->f1();
        m28 = 0;
    }
    m1c->f1();
    cleanup();
    if (param & 1)
        destroy(this);
    return this;
}
