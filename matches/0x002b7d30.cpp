extern void* g_vftable_2b7d30[];
void* operator new(unsigned) throw();
class Ref_2b7d30 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class A_2b7d30 : public Ref_2b7d30 {
  public:
    A_2b7d30() throw();
    char pad[0x2c - 4];
};
class B_2b7d30 : public Ref_2b7d30 {
  public:
    B_2b7d30() throw();
    char pad[0x24 - 4];
};
struct RP_2b7d30 {
    Ref_2b7d30* p;
    void Set(Ref_2b7d30* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
struct Pad_2b7d30 {
    unsigned char b24, b25, b26, b27, b28, b29, b2a;
    void Set() {
        b27 = 0x20;
        b26 = 0x20;
        b25 = 0x20;
        b24 = 0x20;
        b28 = 0x20;
        b29 = 0x20;
        b2a = 0x20;
    }
};
class Obj_2b7d30 {
  public:
    void* vptr;
    int m4;
    int m8;
    int mc;
    int m10;
    char m14;
    int m18;
    RP_2b7d30 m1c;
    RP_2b7d30 m20;
    Pad_2b7d30 pd;
    Obj_2b7d30();
};
Obj_2b7d30::Obj_2b7d30() {
    m8 = 0x10001;
    vptr = g_vftable_2b7d30;
    m14 = 1;
    m18 = -1;
    m4 = 0;
    mc = 0;
    m10 = 0;
    m1c.p = 0;
    m20.p = 0;
    pd.Set();
    m1c.Set(new A_2b7d30);
    m20.Set(new B_2b7d30);
}
