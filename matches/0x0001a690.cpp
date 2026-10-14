struct Game_1a690 {
    bool Ready();
    void Go(int a, int b, int c);
    char pad[0x1b49];
    char f1b49;
    char pad2[0x2fe];
    int f1e48;
};
struct Sess {
    Game_1a690* Get();
};
struct Mid_1a690 {
    Game_1a690* Get();
};
struct Tgt_1a690 {
    void Fn();
};
struct Ref_1a690 {
    virtual void v0();
    virtual void Release();
};
struct Info_1a690 {
    char pad[0x39];
    char flag;
};
Mid_1a690* __stdcall Conv(Ref_1a690* r);
struct Owner_1a690 {
    Mid_1a690* Get();
};
Sess* Lookup();
struct CCollisionAction {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Fn();
    char pad[0x18];
    Owner_1a690* owner;
    Info_1a690* info;
    char pad2[0x18];
    Ref_1a690* r3c;
    char pad3[8];
    Ref_1a690* r48;
};
void CCollisionAction::Fn() {
    Game_1a690* g = owner->Get()->Get();
    if (r3c) {
        Tgt_1a690* t = (Tgt_1a690*)Conv(r3c);
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
