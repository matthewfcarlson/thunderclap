struct Info_182420 {
    char p[0x10];
    int idx;
};
struct Hit_182420 {
    void Go();
};
struct Mgr_182420 {
    Hit_182420* Get(int i);
    void Play(int i, int a, int b, int c, int d, int e);
    char p[0x128];
    Hit_182420* def;
};
struct Sing {
    Mgr_182420* Find();
};
struct Tgt_182420 {
    Sing* GetSing();
};
struct Act_182420 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Run(int a, int b);
    char p[0x18];
    Info_182420* info;
    Tgt_182420* tgt;
};
bool Act_182420::Run(int a, int b) {
    if (!tgt)
        return false;
    Mgr_182420* m = tgt->GetSing()->Find();
    int i = info->idx;
    if (m) {
        Hit_182420* h;
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
