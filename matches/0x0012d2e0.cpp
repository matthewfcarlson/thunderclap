class TrackFactoryCasterTemplate_12d2e0 {
  public:
    virtual void f();
};
extern "C" int __cdecl find(void*, TrackFactoryCasterTemplate_12d2e0*);
class Obj {
  public:
    void apply(int);
};
extern "C" void FUN_0012d2e0(Obj* o, void* p) {
    TrackFactoryCasterTemplate_12d2e0 c;
    o->apply(find(p, &c));
}