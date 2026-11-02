class TrackFactoryCaster_12de00 {
  public:
    virtual void Cast();
};
class TrackFactoryCasterTemplate_12de00 : public TrackFactoryCaster_12de00 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Use(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCaster_12de00*);
extern "C" void __cdecl FUN_0012de00(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_12de00 caster;
    obj->Use(FUN_00236ac0(key, &caster));
}