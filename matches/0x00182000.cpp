struct Act {
    void Run(void* o, unsigned char b);
};
struct G {
    char pad[0x10];
    Act* act;
};
extern G* gG;
struct Cfg {
    char pad[0x10];
    int idx;
    unsigned char b;
};
struct Ent {
    char pad[0x128];
    void* s128;
    void* Get(int i);
};
struct Reg2 {
    Ent* Lookup();
};
struct Owner {
    Reg2* GetReg2();
};
class A {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(unsigned p, int q);
    char pad[0x1c - 4];
    Cfg* cfg;
    Owner* m20;
};
bool A::v5(unsigned p, int q) {
    if (p == 0 && m20 != 0) {
        Ent* e = m20->GetReg2()->Lookup();
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
                gG->act->Run(o, cfg->b);
        }
    }
    return false;
}
