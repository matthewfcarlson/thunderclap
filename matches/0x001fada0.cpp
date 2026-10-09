struct File {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Read(void* buf, int len, int one);
    virtual void v4();
    virtual void v5();
    virtual void GetPos(int* out);
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
    virtual void Sync();
};
struct S {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual int Read(void* buf, int len);
    File* f;
    int pos;
    int end;
};
int S::Read(void* buf, int len) {
    int n = end - pos;
    if (n < len)
        len = n;
    int p0;
    f->GetPos(&p0);
    f->Sync();
    f->Read(buf, len, 1);
    f->Sync();
    int p1;
    f->GetPos(&p1);
    f->Sync();
    pos += p1 - p0;
    return p1 - p0;
}
