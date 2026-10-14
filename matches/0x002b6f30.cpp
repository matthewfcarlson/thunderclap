class Ref_2b6f30 {
  public:
    virtual void f0();
    virtual void f1();
};
class Provider_2b6f30 {
  public:
    char pad[0x70];
    Ref_2b6f30* getObj();
};
class ShadowSkinImpl {
  public:
    char pad[0x70];
    Provider_2b6f30* provider;
    char gap[8];
    Ref_2b6f30* p;
    void helper(Ref_2b6f30*);
    void vfunc_6();
};
void ShadowSkinImpl::vfunc_6() {
    if (!p) {
        Ref_2b6f30* r = provider->getObj();
        if (r)
            r->f0();
        if (p)
            p->f1();
        p = r;
    }
    helper(p);
}
