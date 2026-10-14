struct Ent_1c2550 {
    char pad[8];
    float a;
    float v;
    float b;
};
class Obj_1c2550 {
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
Ent_1c2550* __stdcall Find(Obj_1c2550* o, bool flag);
void __stdcall Fn(Obj_1c2550* o, float x) {
    Ent_1c2550* e = Find(o, x < 1.0f);
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
