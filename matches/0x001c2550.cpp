struct Ent {
    char pad[8];
    float a;
    float v;
    float b;
};
class Obj {
  public:
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void Fire();
};
Ent* __stdcall Find(Obj* o, bool flag);
void __stdcall Fn(Obj* o, float x) {
    Ent* e = Find(o, x < 1.0f);
    if (e) {
        e->v = x;
        if (e->a > 0.0f)
            return;
        if (e->b > 0.0f)
            return;
        if (x < 1.0f)
            return;
    }
    o->Fire();
}
