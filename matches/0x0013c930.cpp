class TrackFactoryCasterTemplate_13c930 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_13c930*);
void target(Obj* o, void* p) {
    TrackFactoryCasterTemplate_13c930 c;
    o->use(find(p, &c));
}