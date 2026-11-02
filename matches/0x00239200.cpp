class TrackFactoryCasterTemplate_239200 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_239200*);
extern "C" void FUN_00239200(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_239200 caster;
    void* p = FUN_00236ac0(name, &caster);
    obj->set(p);
}