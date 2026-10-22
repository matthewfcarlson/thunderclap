class TrackFactoryCasterTemplate_158b00 {
  public:
    virtual void Cast();
};
struct Obj {
    void Fn(void*);
};
void* __cdecl Find(void*, TrackFactoryCasterTemplate_158b00*);
void __cdecl Target(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158b00 caster;
    void* result = Find(name, &caster);
    obj->Fn(result);
}