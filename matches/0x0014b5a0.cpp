class TrackFactoryCasterTemplate_14b5a0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    int Get(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_14b5a0*);
int __cdecl F(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_14b5a0 caster;
    return obj->Get(FUN_00236ac0(name, &caster));
}