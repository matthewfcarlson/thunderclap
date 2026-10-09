struct Ref {
    virtual void AddRef();
    virtual void Release();
    int pad[5];
    int kind;
};
struct PG {
    int v1;
    int v2;
    int v3;
    int flag;
    char pad[0x40 - 0x14];
    Ref* mat;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(Ref* r);
};
void PG::f8(Ref* r) {
    if (r)
        r->AddRef();
    if (mat)
        mat->Release();
    mat = r;
    if (r && (r->kind == 1 || r->kind == 3 || r->kind == 7 || r->kind == 2 || r->kind == 4 || r->kind == 5 ||
              r->kind == 6)) {
        flag = 1;
        return;
    }
    flag = 0;
}
