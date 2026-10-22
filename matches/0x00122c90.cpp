class TrackFactoryCasterTemplate_122c90 {
  public:
    virtual void Cast();
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_122c90*);
class Target {
  public:
    void Set(void*);
};
void Run(Target* t, void* key) {
    TrackFactoryCasterTemplate_122c90 caster;
    t->Set(Lookup(key, &caster));
}