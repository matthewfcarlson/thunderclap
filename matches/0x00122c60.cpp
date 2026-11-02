class TrackFactoryCasterTemplate_122c60 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_122c60*);
extern "C" void FUN_00122c60(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_122c60 caster;
    void* found = Lookup(key, &caster);
    obj->Apply(found);
}