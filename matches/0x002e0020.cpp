struct Ref_2e0020 {
    virtual void AddRef();
    virtual void Release();
};
struct SP {
    Ref_2e0020* p;
    SP() : p(0) {}
    void operator=(Ref_2e0020* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
namespace pure3d {
struct Base_2e0020 {
    virtual void v0();
    Base_2e0020(const Base_2e0020&);
    char pad[0x54];
};
struct PrimGroupOptimized : Base_2e0020 {
    PrimGroupOptimized(const PrimGroupOptimized& o) : Base_2e0020(o) { m58 = o.m58.p; }
    virtual void v1();
    SP m58;
    int m5c;
};
struct PrimGroupSkinnedOptimized : PrimGroupOptimized {
    PrimGroupSkinnedOptimized(const PrimGroupSkinnedOptimized& o);
    virtual void v2();
    int m60;
    SP m64;
};
PrimGroupSkinnedOptimized::PrimGroupSkinnedOptimized(const PrimGroupSkinnedOptimized& o)
    : PrimGroupOptimized(o), m60(0) {
    m64 = o.m64.p;
}
} // namespace pure3d
