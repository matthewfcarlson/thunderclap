class TrackFactoryCasterTemplate_158bf0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_158bf0*);
void Func(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158bf0 caster;
    void* p = Find(name, &caster);
    obj->Apply(p);
}