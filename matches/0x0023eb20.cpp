struct Sub_23eb20 {
    void Set(int, int);
    bool Done();
};
struct Res_23eb20 {
    void Bind(Sub_23eb20*, int, int);
};
struct Inner_23eb20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Res_23eb20* Check(int, int);
};
struct Check20 {
    char p[0x20];
    bool Ready(int, int, int);
};
struct Obj_23eb20 {
    char p[0x14];
    Inner_23eb20* inner;
    char q[8];
    Check20 c;
};
struct SpawnAction {
    char p[0x1c];
    Obj_23eb20* owner;
    int a, b;
    Sub_23eb20 sub;
    char q[0x24];
    int saved;
    bool flag;
    bool vfunc_3(int, int);
};
bool SpawnAction::vfunc_3(int param, int next) {
    Obj_23eb20* o = owner;
    saved = param;
    Inner_23eb20* i = o->inner;
    if (!i)
        return false;
    if (!o->c.Ready(a, b, 0))
        return false;
    Res_23eb20* r = i->Check(b, 0);
    if (!r)
        return false;
    r->Bind(&sub, b, 0);
    sub.Set(param, next);
    flag = true;
    return sub.Done();
}
