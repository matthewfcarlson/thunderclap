struct A_15c460 {
    void* f592();
};
struct C_15c460 {
    void f22(void*, int, float);
};
struct D {
    void f359(int);
};
struct B_15c460 {
    C_15c460* f9a40();
    D* f9a30();
};
struct LocomotionStrafeAction {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    char pad[0x18];
    A_15c460* member1c;
    void* member20;
};
void LocomotionStrafeAction::vfunc_4() {
    if (member20) {
        B_15c460* b = (B_15c460*)member1c->f592();
        C_15c460* c = b->f9a40();
        if (c) {
            c->f22(member20, 0, -1.0f);
            D* d = b->f9a30();
            if (d)
                d->f359(0);
        }
    }
}