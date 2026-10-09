struct Tgt {
    char p[0x40];
    float x, y, z;
};
struct Sub {
    char p[8];
    Tgt* t;
    char q[0x39];
    char flag;
    void Go(float* v, int a, float s, int b, int c);
};
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void SetN(int n);
    virtual int GetN();
    char pad[0x58 - 4];
    Sub sub;
    void Fn(Tgt* t, char f);
};
void Base::Fn(Tgt* t, char f) {
    Sub* s = &sub;
    if (t && s && s->t == t) {
        float v[3];
        v[0] = t->x;
        v[1] = t->y;
        v[2] = t->z;
        s->Go(v, 1, 1.0f, 0, 0);
        if (GetN() < 3)
            SetN(3);
        if (f)
            s->flag = 1;
    }
}
