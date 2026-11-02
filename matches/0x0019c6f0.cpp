class TrackFactoryCasterTemplate_19c6f0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern void* Find(void*, TrackFactoryCasterTemplate_19c6f0*);
extern "C" void FUN_0019c6f0(Obj* o, void* name) {
    TrackFactoryCasterTemplate_19c6f0 c;
    void* p = Find(name, &c);
    o->Set(p);
}