class TrackFactoryCasterTemplate_158a70 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl find(void*, TrackFactoryCasterTemplate_158a70*);
class Object {
  public:
    void attach(void*);
};
extern "C" void __cdecl FUN_00158a70(Object* obj, void* name) {
    TrackFactoryCasterTemplate_158a70 caster;
    obj->attach(find(name, &caster));
}