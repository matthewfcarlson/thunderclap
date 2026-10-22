class TrackFactoryCasterTemplate_189f30 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_189f30*);
void fun(Obj* o, void* p) {
    TrackFactoryCasterTemplate_189f30 c;
    o->Apply(Find(p, &c));
}