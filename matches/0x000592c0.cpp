extern void* Alloc(unsigned int);
inline void* operator new(unsigned int, void* p) {
    return p;
}
class FightBase {
  public:
    virtual void b0();
    FightBase();
};
class CFightParams : public FightBase {
  public:
    CFightParams(int x) : FightBase() {
        field8 = x;
        fieldc = 0;
        field10 = 0;
    }
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual CFightParams* vfunc_4();
    int pad4;
    int field8;
    int fieldc;
    int field10;
};
CFightParams* CFightParams::vfunc_4() {
    void* mem = Alloc(0x14);
    if (mem) {
        int x = field8;
        return new (mem) CFightParams(x);
    }
    return 0;
}
