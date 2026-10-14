struct Helper1_1727f0 {
    int f();
};
struct Helper2_1727f0 {
    int f();
};
struct Helper3 {
    void f(void*);
};
struct MomentumXZAddAction {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual bool vfunc_3(unsigned int x, unsigned int y);
    virtual void d();
    virtual void e();
    char pad[0x1c];
    Helper1_1727f0* member;
    int field24;
    int field28;
};
bool MomentumXZAddAction::vfunc_3(unsigned int x, unsigned int y) {
    Helper1_1727f0* p = member;
    if (!p)
        return false;
    int q = p->f();
    if (!q)
        return false;
    Helper2_1727f0* z = (Helper2_1727f0*)q;
    int r = z->f();
    if (!r)
        return false;
    ((Helper3*)r)->f(&field24);
    field28 = 0;
    return true;
}