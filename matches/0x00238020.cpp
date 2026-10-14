typedef unsigned int u32_238020;
extern void* Alloc(unsigned int);
class Builder {
  public:
    u32_238020 Run(u32_238020, u32_238020, u32_238020, u32_238020, void*, u32_238020, u32_238020);
};
class Track {
  public:
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
};
class SequenceTrack : public Track {
  public:
    char pad[8];
    u32_238020 field0c;
    char pad10[8];
    u32_238020 field18;
    char pad1c[4];
    u32_238020 vfunc_10(u32_238020, u32_238020, u32_238020);
};
u32_238020 SequenceTrack::vfunc_10(u32_238020 a, u32_238020 b, u32_238020 c) {
    Builder* p = (Builder*)Alloc(0x3c);
    if (p) {
        u32_238020 x = field0c;
        return p->Run(a, (u32_238020)this, x, field18, &pad1c, b, c);
    }
    return 0;
}
