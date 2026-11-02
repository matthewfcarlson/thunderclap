class TrackFactoryCasterTemplate_158b30 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_158b30*);
extern "C" void FUN_00158b30(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b30 c;
    obj->set(FUN_00236ac0(name, &c));
}