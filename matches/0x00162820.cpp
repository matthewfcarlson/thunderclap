class TrackFactoryCasterTemplate_162820 {
  public:
    virtual void f();
};
class Obj {
  public:
    void use(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_162820*);
extern "C" void FUN_00162820(Obj* o, void* p) {
    TrackFactoryCasterTemplate_162820 c;
    o->use(Find(p, &c));
}