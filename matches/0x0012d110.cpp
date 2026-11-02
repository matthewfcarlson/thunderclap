class TrackFactoryCasterTemplate_12d110 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_12d110*);
class Obj {
  public:
    void* finish(void*);
};
extern "C" void* __cdecl FUN_0012d110(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_12d110 caster;
    void* found = FUN_00236ac0(name, &caster);
    return obj->finish(found);
}