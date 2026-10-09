extern int RTTI1, RTTI2;
extern int FUN_00344e74(int, int, int, int, int);
struct Result {
    int pad;
    int type;
    char gap[0x20];
    int state;
};
struct Obj {
    Result* get();
};
struct Event_PropStateDescCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int, int, int);
    char pad[8];
    int value;
};
bool Event_PropStateDescCondition::vfunc_6(int a, int b, int c) {
    Obj* x = (Obj*)FUN_00344e74(b, 0, (int)&RTTI1, (int)&RTTI2, 0);
    if (!x)
        return false;
    Result* r = x->get();
    if (r->type != 0x17)
        return false;
    if (r->state == value)
        return true;
    return false;
}
