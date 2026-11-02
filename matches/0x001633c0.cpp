class TrackFactoryCasterTemplate_1633c0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Do(void*);
};
extern void* Find(void*, TrackFactoryCasterTemplate_1633c0*);
extern "C" void FUN_001633c0(Obj* obj, void* value) {
    TrackFactoryCasterTemplate_1633c0 c;
    void* p = Find(value, &c);
    obj->Do(p);
}