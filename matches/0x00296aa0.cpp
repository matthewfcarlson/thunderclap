struct Obj_296aa0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};
struct VisibilityNode {
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
    char pad[0xc];
    unsigned flags;
    char p14[4];
    unsigned count;
    Obj_296aa0** items;
    char p20[0xc];
    Obj_296aa0* ref;
    void vfunc_9();
};
void VisibilityNode::vfunc_9() {
    if (ref)
        ref->f23();
    flags &= 0xfffffffe;
    for (unsigned i = 0; i < count; ++i)
        items[i]->f9();
}