class TrackFactoryCasterTemplate_23efe0 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_23efe0*);
class Obj {
  public:
    void Set(void*);
};
extern "C" void FUN_0023efe0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_23efe0 caster;
    obj->Set(Find(name, &caster));
}