class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class Provider {
  public:
    char pad[0x70];
    Ref* getObj();
};
class ShadowSkinImpl {
  public:
    char pad[0x70];
    Provider* provider;
    char gap[8];
    Ref* p;
    void helper(Ref*);
    void vfunc_6();
};
void ShadowSkinImpl::vfunc_6() {
    if (!p) {
        Ref* r = provider->getObj();
        if (r)
            r->f0();
        if (p)
            p->f1();
        p = r;
    }
    helper(p);
}
