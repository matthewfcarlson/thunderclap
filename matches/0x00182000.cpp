struct Act_182000 {
    void Run(void* o, unsigned char b);
};
struct G_182000 {
    char pad[0x10];
    Act_182000* act;
};
extern G_182000* gG_182000;
struct Cfg_182000 {
    char pad[0x10];
    int idx;
    unsigned char b;
};
struct Ent_182000 {
    char pad[0x128];
    void* s128;
    void* Get(int i);
};
struct Reg2 {
    Ent_182000* Lookup();
};
struct Owner_182000 {
    Reg2* GetReg2();
};
class A_182000 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(unsigned p, int q);
    char pad[0x1c - 4];
    Cfg_182000* cfg;
    Owner_182000* m20;
};
bool A_182000::v5(unsigned p, int q) {
    if (p == 0 && m20 != 0) {
        Ent_182000* e = m20->GetReg2()->Lookup();
        int i = cfg->idx;
        if (e) {
            void* o;
            if (i < 0)
                o = e->s128;
            else {
                if (i >= 8)
                    return false;
                o = e->Get(i);
            }
            if (o)
                gG_182000->act->Run(o, cfg->b);
        }
    }
    return false;
}
