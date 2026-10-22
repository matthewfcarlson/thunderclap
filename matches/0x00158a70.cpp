class TrackFactoryCasterTemplate_158a70 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl find(void*, TrackFactoryCasterTemplate_158a70*);
class Object {
  public:
    void attach(void*);
};
void __cdecl target(Object* obj, void* name) {
    TrackFactoryCasterTemplate_158a70 caster;
    obj->attach(find(name, &caster));
}