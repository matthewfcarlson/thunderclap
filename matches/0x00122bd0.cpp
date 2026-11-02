class TrackFactoryCasterTemplate_122bd0 {
  public:
    virtual void Check();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_122bd0*);
extern "C" void FUN_00122bd0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_122bd0 c;
    obj->Apply(Find(name, &c));
}