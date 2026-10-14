extern "C" void _ReadWriteBarrier();
struct Helper_30d590 {
    void Init() throw();
    char b[0x1c];
};
struct J_30d590;
struct PJ_30d590 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual PJ_30d590* d27();
    virtual void v28(PJ_30d590* p);
    int m4, m8, mc, m10, m14, m18, m1c;
    int m20, m24, m28;
    char p2c[0x1c];
    Helper_30d590 h48;
    Helper_30d590 h64;
    char tail[0xf8 - 0x80];
    PJ_30d590() throw() {
        _ReadWriteBarrier();
        m20 = 0;
        m24 = 0;
        m28 = 0;
        h48.Init();
        h64.Init();
    }
    void Init(PJ_30d590* owner);
};
struct J_30d590 : PJ_30d590 {
    J_30d590() throw() {}
    virtual PJ_30d590* d27();
};
void* operator new(unsigned int);
PJ_30d590* J_30d590::d27() {
    J_30d590* r = new J_30d590;
    r->Init(this);
    this->v28(r);
    return r;
}
