class TrackFactoryCasterTemplate_191ae0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, TrackFactoryCasterTemplate_191ae0*);
extern "C" void FUN_00191ae0(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_191ae0 caster;
    void* p = Find(name, &caster);
    obj->Set(p);
}