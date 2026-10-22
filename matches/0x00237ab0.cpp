class TrackFactoryCasterTemplate_237ab0 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Method(void*);
};
void* Lookup(const char*, TrackFactoryCasterTemplate_237ab0*);
void Func(Target* target, const char* name) {
    TrackFactoryCasterTemplate_237ab0 caster;
    target->Method(Lookup(name, &caster));
}
