extern void* g_vftable_2c29b0[];
void* operator new(unsigned) throw();
class Ref_2c29b0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class PrimGroupLoader_2c29b0 : public Ref_2c29b0 {
  public:
    PrimGroupLoader_2c29b0() throw();
    char pad[0x2c - 4];
};
class OldPrimGroupLoader_2c29b0 : public Ref_2c29b0 {
  public:
    OldPrimGroupLoader_2c29b0() throw();
    char pad[0x24 - 4];
};
struct RP_2c29b0 {
    Ref_2c29b0* p;
    void Set(Ref_2c29b0* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
struct Pad_2c29b0 {
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
class GeometryLoader_2c29b0 {
  public:
    void* vptr;
    int m4;
    int m8;
    int mc;
    int m10;
    char m14;
    int m18;
    RP_2c29b0 m1c;
    RP_2c29b0 m20;
    Pad_2c29b0 pd;
    GeometryLoader_2c29b0();
};
GeometryLoader_2c29b0::GeometryLoader_2c29b0() {
    m8 = 0x10000;
    vptr = g_vftable_2c29b0;
    m14 = 1;
    m18 = -1;
    m4 = 0;
    mc = 0;
    m10 = 0;
    m1c.p = 0;
    m20.p = 0;
    pd.Set();
    m1c.Set(new PrimGroupLoader_2c29b0);
    m20.Set(new OldPrimGroupLoader_2c29b0);
}
