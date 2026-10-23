class TrackFactoryCasterTemplate_158b60 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_158b60*);
void Func(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b60 caster;
    void* p = FUN_00236ac0(name, &caster);
    obj->Set(p);
}