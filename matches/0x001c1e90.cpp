struct R_1c1e90 {
    virtual void A();
    virtual void Rel();
};
struct Sub_1c1e90 {
    void Cleanup();
    char pad[0xb0];
};
extern R_1c1e90* gR;
struct C_1c1e90 {
    virtual void V();
    R_1c1e90* m4;
    R_1c1e90* m8;
    Sub_1c1e90 sub;
    R_1c1e90* mbc;
    R_1c1e90* mc0;
    R_1c1e90* mc4;
    R_1c1e90* mc8;
    void Shutdown();
};
void C_1c1e90::Shutdown() {
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
