class Ref_2e0460 {
  public:
    virtual void f0();
    virtual void f1();
};
class PrimGroup {
  public:
    virtual void v();
    PrimGroup(const PrimGroup&);
    char pad[0x54];
};
class PrimGroupStreamed_2e0460 : public PrimGroup {
  public:
    virtual void v();
    PrimGroupStreamed_2e0460(const PrimGroupStreamed_2e0460& o) : PrimGroup(o) {
        r1 = 0;
        x58 = o.x58;
        Ref_2e0460* p = o.r1;
        if (p)
            p->f0();
        if (r1)
            r1->f1();
        r1 = p;
    }
    int x58;
    Ref_2e0460* r1;
};
class PrimGroupSkinnedStreamed_2e0460 : public PrimGroupStreamed_2e0460 {
  public:
    virtual void v();
    PrimGroupSkinnedStreamed_2e0460(const PrimGroupSkinnedStreamed_2e0460& o);
    int x60;
    Ref_2e0460* r2;
};
PrimGroupSkinnedStreamed_2e0460::PrimGroupSkinnedStreamed_2e0460(const PrimGroupSkinnedStreamed_2e0460& o) : PrimGroupStreamed_2e0460(o) {
    x60 = 0;
    r2 = 0;
    Ref_2e0460* p = o.r2;
    if (p)
        p->f0();
    if (r2)
        r2->f1();
    r2 = p;
}
