class TrackFactoryCasterTemplate_1392d0 {
  public:
    virtual void cast();
};
class Recipient {
  public:
    void use(void*);
};
extern void* lookup(void*, TrackFactoryCasterTemplate_1392d0*);
void func(Recipient* r, void* name) {
    TrackFactoryCasterTemplate_1392d0 caster;
    void* p = lookup(name, &caster);
    r->use(p);
}