struct Vec {
    int* b;
    int* e;
};
struct Holder {
    char p[0x1c];
    Vec vec;
};
struct Prop {
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
    virtual void Do(int idx, int flag);
    char p[0x94];
    Holder* v;
};
struct Mgr {
    char p[0x128];
    Prop* dflt;
    Prop* Get(int i);
};
struct Info {
    char p[0x10];
    int a;
    int b;
};
extern void* __fastcall FUN_000592a0(void*);
extern Mgr* __fastcall FUN_00059a30(void*);
struct A {
    char p[0x18];
    Info* info;
    void* h;
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    bool F(int* x, int y);
};
bool A::F(int* x, int y) {
    if (!x && h) {
        Mgr* m = FUN_00059a30(FUN_000592a0(h));
        int a = info->a;
        if (m) {
            Prop* r;
            if (a < 0)
                r = m->dflt;
            else if (a >= 8)
                return false;
            else
                r = m->Get(a);
            if (r) {
                Vec* v = &r->v->vec;
                int i = info->b;
                if (i >= 0 && i < (v->e - v->b))
                    r->Do(i, 1);
            }
        }
    }
    return false;
}
