class TrackFactoryCasterTemplate_158a10 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_158a10*);
void __cdecl FUN_00158a10(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_158a10 caster;
    void* p = Find(key, &caster);
    obj->Set(p);
}