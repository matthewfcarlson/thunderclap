class TrackFactoryCasterTemplate_18a2e0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern void* Find(void*, TrackFactoryCasterTemplate_18a2e0*);
extern "C" void FUN_0018a2e0(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_18a2e0 c;
    obj->Apply(Find(p, &c));
}