extern int RTTI1_1a4ac0, RTTI2;
extern int FUN_00344e74(int, int, int, int, int);
struct Result_1a4ac0 {
    int pad;
    int type;
    char gap[0x20];
    int state;
};
struct Obj_1a4ac0 {
    Result_1a4ac0* get();
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
    Obj_1a4ac0* x = (Obj_1a4ac0*)FUN_00344e74(b, 0, (int)&RTTI1_1a4ac0, (int)&RTTI2, 0);
    if (!x)
        return false;
    Result_1a4ac0* r = x->get();
    if (r->type != 0x17)
        return false;
    if (r->state == value)
        return true;
    return false;
}
