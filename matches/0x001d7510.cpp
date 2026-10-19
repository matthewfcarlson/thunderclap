class Res_1d7510 {
  public:
    void Release(int);
};
class Y_1d7510 {
  public:
    void Go(float* v);
};
Y_1d7510* __stdcall GetY();
class Fn_1d7510 {
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
struct B_1d7510 {
    char p[0x10];
};
struct Mid_1d7510 {
    char p[0x10];
    Fn_1d7510* c70;
};
struct Mid2 {
    char p[0x70];
    Fn_1d7510* f;
};
struct Link_1d7510 {
    char p[0x10];
    Mid2* m;
};
class W_1d7510 {
  public:
    char p0[8];
    float x, y;
    char p1[0x90];
    Link_1d7510* l;
    char p2[0x148];
    char flag;
    void F();
};
void W_1d7510::F() {
    Link_1d7510* k = l;
    if (!k)
        return;
    Mid2* m = k->m;
    if (!m)
        return;
    Fn_1d7510* f = m->f;
    if (f) {
        float v = f->Get();
        if (v != 0.0f) {
            ((Res_1d7510*)l)->Release(1);
            return;
        }
        if (flag) {
            float t[2];
            t[0] = x;
            t[1] = y;
            GetY()->Go(t);
        }
    }
}
