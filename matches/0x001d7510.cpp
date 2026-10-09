class Res {
  public:
    void Release(int);
};
class Y {
  public:
    void Go();
};
Y* __stdcall GetY(float* v);
class Fn {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual float Get();
};
struct B {
    char p[0x10];
};
struct Mid {
    char p[0x10];
    Fn* c70;
};
struct Mid2 {
    char p[0x70];
    Fn* f;
};
struct Link {
    char p[0x10];
    Mid2* m;
};
class W {
  public:
    char p0[8];
    float x, y;
    char p1[0x90];
    Link* l;
    char p2[0x148];
    char flag;
    void F();
};
void W::F() {
    Link* k = l;
    if (!k)
        return;
    Mid2* m = k->m;
    if (!m)
        return;
    Fn* f = m->f;
    if (f) {
        float v = f->Get();
        if (v != 0.0f) {
            ((Res*)l)->Release(1);
            return;
        }
        if (flag) {
            float t[2];
            t[0] = x;
            t[1] = y;
            GetY(t)->Go();
        }
    }
}
