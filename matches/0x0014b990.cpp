class TrackFactoryCasterTemplate_14b990 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_14b990*);
class Obj {
  public:
    void Set(void*);
};
void Fn(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_14b990 c;
    obj->Set(FUN_00236ac0(name, &c));
}