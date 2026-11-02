class TrackFactoryCasterTemplate_122c90 {
  public:
    virtual void Cast();
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_122c90*);
class Target {
  public:
    void Set(void*);
};
extern "C" void FUN_00122c90(Target* t, void* key) {
    TrackFactoryCasterTemplate_122c90 caster;
    t->Set(Lookup(key, &caster));
}