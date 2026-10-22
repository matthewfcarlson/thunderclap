class TrackFactoryCasterTemplate_132560 {
  public:
    virtual void f();
};
class Obj {
  public:
    void apply(void*);
};
void* __cdecl find(const char*, TrackFactoryCasterTemplate_132560*);
void __cdecl target(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_132560 caster;
    obj->apply(find(name, &caster));
}