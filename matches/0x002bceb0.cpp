struct Chunk {
    int Id();
};
extern int g_vt;
struct BO {
    void InitBase(int);
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
    virtual void Init();
    int a;
    int b;
    int c;
    char pad[0x48];
    float f;
};
struct Helper {
    void Fill(BO*, Chunk*, int);
};
void* operator new(unsigned);
struct Loader {
    char pad0[0x10];
    Helper* h;
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void Load(BO**, int*, Chunk*, int);
};
void Loader::Load(BO** out, int* info, Chunk* c, int x) {
    if (c->Id() == 0x17006) {
        BO* o = (BO*)operator new(0x60);
        if (o) {
            o->InitBase(1);
            *(int**)o = &g_vt;
            o->f = 1.0f;
        } else {
            o = 0;
        }
        h->Fill(o, c, x);
        o->Init();
        *out = o;
        info[0] = o->b;
        info[1] = o->c;
    }
}
