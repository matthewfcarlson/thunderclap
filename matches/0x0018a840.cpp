class TrackFactoryCasterTemplate_18a840 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, TrackFactoryCasterTemplate_18a840*);
extern "C" void __cdecl FUN_0018a840(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_18a840 caster;
    void* p = Find(name, &caster);
    obj->Set(p);
}