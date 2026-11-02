class TrackFactoryCasterTemplate_158b00 {
  public:
    virtual void Cast();
};
struct Obj {
    void Fn(void*);
};
void* __cdecl Find(void*, TrackFactoryCasterTemplate_158b00*);
extern "C" void __cdecl FUN_00158b00(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158b00 caster;
    void* result = Find(name, &caster);
    obj->Fn(result);
}