struct R {
    virtual void A();
    virtual void Rel();
};
struct Sub {
    void Cleanup();
    char pad[0xb0];
};
extern R* gR;
struct C {
    virtual void V();
    R* m4;
    R* m8;
    Sub sub;
    R* mbc;
    R* mc0;
    R* mc4;
    R* mc8;
    void Shutdown();
};
void C::Shutdown() {
    if (mbc) {
        mbc->Rel();
        mbc = 0;
    }
    if (mc0) {
        mc0->Rel();
        mc0 = 0;
    }
    if (mc4) {
        mc4->Rel();
        mc4 = 0;
    }
    if (mc8) {
        mc8->Rel();
        mc8 = 0;
    }
    if (m4) {
        m4->Rel();
        m4 = 0;
    }
    if (m8) {
        m8->Rel();
        m8 = 0;
    }
    if (gR) {
        gR->Rel();
        gR = 0;
    }
    sub.Cleanup();
}
