extern "C" void _ReadWriteBarrier();
struct Helper {
    void Init() throw();
    char b[0x1c];
};
struct J;
struct PJ {
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
    virtual PJ* d27();
    virtual void v28(PJ* p);
    int m4, m8, mc, m10, m14, m18, m1c;
    int m20, m24, m28;
    char p2c[0x1c];
    Helper h48;
    Helper h64;
    char tail[0xf8 - 0x80];
    PJ() throw() {
        _ReadWriteBarrier();
        m20 = 0;
        m24 = 0;
        m28 = 0;
        h48.Init();
        h64.Init();
    }
    void Init(PJ* owner);
};
struct J : PJ {
    J() throw() {}
    virtual PJ* d27();
};
void* operator new(unsigned int);
PJ* J::d27() {
    J* r = new J;
    r->Init(this);
    this->v28(r);
    return r;
}
