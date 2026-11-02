class TrackFactoryCasterTemplate_189f60 {
  public:
    virtual void cast();
};
class Obj {
  public:
    int Do(void*);
};
extern void* Find(int, TrackFactoryCasterTemplate_189f60*);
extern "C" int FUN_00189f60(Obj* obj, int name) {
    TrackFactoryCasterTemplate_189f60 c;
    return obj->Do(Find(name, &c));
}