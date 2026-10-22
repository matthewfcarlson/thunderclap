class TrackFactoryCasterTemplate_14b990 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_14b990*);
class Obj {
  public:
    void Set(void*);
};
void Fn(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_14b990 c;
    obj->Set(Find(name, &c));
}