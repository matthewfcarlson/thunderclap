struct Ent_1c24d0 {
    char pad0[8];
    float f8;
    float fc;
    float f10;
    int f14;
};
class Obj_1c24d0 {
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
Ent_1c24d0* __stdcall Find(Obj_1c24d0* o, bool b);
void __stdcall F(Obj_1c24d0* o, int a, float t) {
    Ent_1c24d0* e = Find(o, t > 0.0f);
    if (e) {
        e->f14 = a;
        e->f10 = t;
        if (e->f8 > 0.0f)
            return;
        if (t > 0.0f)
            return;
        if (e->fc < 1.0f)
            return;
    }
    o->Fire();
}
