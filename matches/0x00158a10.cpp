class TrackFactoryCasterTemplate_158a10 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_158a10*);
void __cdecl FUN_00158a10(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_158a10 caster;
    void* p = FUN_00236ac0(key, &caster);
    obj->Set(p);
}