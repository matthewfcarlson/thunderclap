struct Sub {
    void Set(int, int);
    bool Done();
};
struct Res {
    void Bind(Sub*, int, int);
};
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Res* Check(int, int);
};
struct Check20 {
    char p[0x20];
    bool Ready(int, int, int);
};
struct Obj {
    char p[0x14];
    Inner* inner;
    char q[8];
    Check20 c;
};
struct SpawnAction {
    char p[0x1c];
    Obj* owner;
    int a, b;
    Sub sub;
    char q[0x24];
    int saved;
    bool flag;
    bool vfunc_3(int, int);
};
bool SpawnAction::vfunc_3(int param, int next) {
    Obj* o = owner;
    saved = param;
    Inner* i = o->inner;
    if (!i)
        return false;
    if (!o->c.Ready(a, b, 0))
        return false;
    Res* r = i->Check(b, 0);
    if (!r)
        return false;
    r->Bind(&sub, b, 0);
    sub.Set(param, next);
    flag = true;
    return sub.Done();
}
