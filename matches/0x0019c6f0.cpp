class TrackFactoryCasterTemplate_19c6f0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern void* Find(void*, TrackFactoryCasterTemplate_19c6f0*);
void target(Obj* o, void* name) {
    TrackFactoryCasterTemplate_19c6f0 c;
    void* p = Find(name, &c);
    o->Set(p);
}