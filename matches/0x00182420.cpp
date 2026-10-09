struct Info {
    char p[0x10];
    int idx;
};
struct Hit {
    void Go();
};
struct Mgr {
    Hit* Get(int i);
    void Play(int i, int a, int b, int c, int d, int e);
    char p[0x128];
    Hit* def;
};
struct Sing {
    Mgr* Find();
};
struct Tgt {
    Sing* GetSing();
};
struct Act {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Run(int a, int b);
    char p[0x18];
    Info* info;
    Tgt* tgt;
};
bool Act::Run(int a, int b) {
    if (!tgt)
        return false;
    Mgr* m = tgt->GetSing()->Find();
    int i = info->idx;
    if (m) {
        Hit* h;
        if (i < 0)
            h = m->def;
        else {
            if (i >= 8)
                return false;
            h = m->Get(i);
        }
        if (h) {
            m->Play(i, 0, -1, 0, 0, 0);
            h->Go();
        }
    }
    return false;
}
