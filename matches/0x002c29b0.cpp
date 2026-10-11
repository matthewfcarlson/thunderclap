extern void* g_vftable[];
void* operator new(unsigned) throw();
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class A : public Ref {
  public:
    A() throw();
    char pad[0x2c - 4];
};
class B : public Ref {
  public:
    B() throw();
    char pad[0x24 - 4];
};
struct RP {
    Ref* p;
    void Set(Ref* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
struct Pad {
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
class Obj {
  public:
    void* vptr;
    int m4;
    int m8;
    int mc;
    int m10;
    char m14;
    int m18;
    RP m1c;
    RP m20;
    Pad pd;
    Obj();
};
Obj::Obj() {
    m8 = 0x10000;
    vptr = g_vftable;
    m14 = 1;
    m18 = -1;
    m4 = 0;
    mc = 0;
    m10 = 0;
    m1c.p = 0;
    m20.p = 0;
    pd.Set();
    m1c.Set(new A);
    m20.Set(new B);
}
