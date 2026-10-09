struct Game {
    bool Ready();
    void Go(int a, int b, int c);
    char pad[0x1b49];
    char f1b49;
    char pad2[0x2fe];
    int f1e48;
};
struct Sess {
    Game* Get();
};
struct Mid {
    Game* Get();
};
struct Tgt {
    void Fn();
};
struct Ref {
    virtual void v0();
    virtual void Release();
};
struct Info {
    char pad[0x39];
    char flag;
};
Mid* __stdcall Conv(Ref* r);
struct Owner {
    Mid* Get();
};
Sess* Lookup();
struct CCollisionAction {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Fn();
    char pad[0x18];
    Owner* owner;
    Info* info;
    char pad2[0x18];
    Ref* r3c;
    char pad3[8];
    Ref* r48;
};
void CCollisionAction::Fn() {
    Game* g = owner->Get()->Get();
    if (r3c) {
        Tgt* t = (Tgt*)Conv(r3c);
        t->Fn();
        if (r3c) {
            r3c->Release();
            r3c = 0;
        }
    }
    if (info->flag) {
        if (g->Ready())
            g->Go(0, 0, 0);
    }
    g->f1b49 = 0;
    g->f1e48 = 0;
    if (r48) {
        r48->Release();
        r48 = 0;
    }
}
